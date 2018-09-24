(ns clover.core
  (:use [clojure.core])
  (:require [clover.driver :as driver]
            [clover.parser :as parser]
            [clover.compiler :as compiler])
  (:import [org.jline.reader LineReaderBuilder]
           [org.jline.terminal TerminalBuilder])
  (:gen-class))

;; (defn term []
  ;; (.build (.dumb (TerminalBuilder/builder) true)))

;; (defn builder []
  ;; (LineReaderBuilder/builder))

;; (defn reader []
  ;; (.readLine (.build (.terminal (builder) (term))) "-> "))

(defn read-build-run [expr]
  (-> expr
   (parser/parse)
   (compiler/emit)
   (compiler/append)
   (driver/build-and-run)))

(defn repl []
  (print ">> ")
  (flush)
  (let [in (read)]
    (print "=>" (read-build-run in)))
  (recur))

(defn -main []
  (print 
   "Clover 0.0.1 Interactive REPL.\n"
   "Commands: :reload, :exit \n")
  (repl))
