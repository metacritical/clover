(ns clover.repl.readline
  (:import [org.jline.reader LineReaderBuilder]
    	   [org.jline.terminal TerminalBuilder]))

(defn term []
  (.build (.dumb (TerminalBuilder/builder) true)))

(defn builder []
  (LineReaderBuilder/builder))

(defn reader []
  (.readLine (.build (.terminal (builder) (term))) "-> "))

