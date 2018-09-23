(ns clover.compiler
  (:require [clover.types.primitive :as prim]))

(defmulti emit 
  "Emit given program to assembly and compile with runtime."
  (fn [form]
    (type form)))

(defmethod emit Long
  [expr]
  (prim/emit-long expr))

(defmethod emit Double
  [expr]
  (prim/emit-double expr))

(defmethod emit String
  [expr]
  (prim/emit-string expr))

(defmethod emit Boolean
  [expr]
  (prim/emit-bool expr))

(defmethod emit nil
  [expr]
  (prim/emit-nil))

(defmethod emit Character
  [expr]
  (prim/emit-chr expr))

(defmethod emit clojure.lang.Keyword
  [expr]
  (prim/emit-keyword expr))

(defmethod emit clojure.lang.Symbol
  [expr]
  (prim/emit-symbol expr))

(defmethod emit :default ;;clojure.lang.PersistentList
  [expr]
  (prim/emit-list expr))

;TODO: Instead of appending link separate prim files.
(defn append [expr] (str (slurp "src/bitcode/primitives.ll") expr))

;; TODO: There are two ingredients to making a primitive function.
;; 1. Binding type (def a 2)
;; 2. Procedure  (fn [x] (+ 1 x))
;; 3. Both def for binding and lambda for function are created using core
;; primitive functions in C.
;; 4. Variadic functions would use C's variadic functionality.
;; Both of these require an evironment to store the values in FOr now we will
;; Glib hash table as environment because it has generally good performance
;; and constant memory usage and complexity in both read and write operations
