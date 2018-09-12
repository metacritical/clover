(ns clover.core
  (:use [clojure.core])
  (:require [clover.driver :as driver]
            [clover.compiler :as compiler])
  (:gen-class))

(defn read-build-run [expr]
  (->
   (compiler/clover-compile expr)
   (driver/emit)
   (driver/build-run)))

(defn repl []
  (print ">> ")
  (flush)
  (let [in (read)]
    (print "=>"(read-build-run in)))
  (recur))

(defn -main []
  (print "Clover 0.0.1 Interactive REPL.\n")
  (repl))
