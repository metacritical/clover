(ns clover.compiler
  (:require [clover.types.primitive :as prim]
            [clover.types.special-forms :as special]))

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
  (special/emit-list expr))
