(ns clover.core
  (:use [clojure.core])
  (:require [clover.driver :as driver])
  (:gen-class))

(defn read-build-run [expr]
  (driver/cache-cleanup)
  (driver/clover-compile expr)
  (driver/build-run))

(defn repl []
  (println "Clover 0.0.1 Interactive REPL.")
  (printf ">> ")
  (flush)
  (let [in (read)]
    (println "=> " (read-build-run in)))
  (recur))

(defn -main []
  (repl))
