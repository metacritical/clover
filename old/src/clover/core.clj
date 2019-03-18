(ns clover.core
  (:use [clojure.core])
  (:require [clover.driver :as driver]
            [clover.parser :as parser]
            [clover.repl.readline :as readline])
  (:gen-class))

;TODO: Instead of appending link separate prim files.
(defn append [expr] (str (slurp "src/bitcode/primitives.ll") expr))

(defn read-build-run [expr]
  (-> expr
   (parser/parse)
   (append)
   (driver/build-and-run)))

(defn spcl-cmd [in]
  (cond (keyword? in)
    (case in
      :reload (do (require 'clover.core :reload-all) :ok!)
      :exit (System/exit 0)
      in)
    :else in))

(defn repl []
  (print ">> ")
  (flush)
  (let [in (spcl-cmd (read))]
    (print "=>" (read-build-run in)))
  (recur))

(defn -main []
  (print
   "Clover 0.0.1 Interactive REPL.\n"
   "Commands: :reload, :exit \n")
  (repl))


;; TODO: There are two ingredients to making a primitive function.
;; 1. Binding type (def a 2)
;; 2. Procedure  (fn [x] (+ 1 x))
;; 3. Both def for binding and lambda for function are created using core
;; primitive functions in C.
;; 4. Variadic functions would use C's variadic functionality.
;; Both of these require an evironment to store the values in FOr now we will
;; Glib hash table as environment because it has generally good performance
;; and constant memory usage and complexity in both read and write operations
