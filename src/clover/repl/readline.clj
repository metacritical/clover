(ns clover.repl.readline
  (:import [jline.console ConsoleReader]))

(defn reader []
  (let [cr (ConsoleReader.) line (.readLine cr ">> ")]
    line))
