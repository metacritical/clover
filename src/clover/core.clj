(ns clover.core
  (:require [clover.primitive :as primitive])
  (:gen-class))

(use '[clojure.java.shell :only [sh]])

(defn emit [expr]
  (spit "build/program.ll" expr))

(defn build []
  (if (sh "cp" "runtime/runtime.c" "build/")
    (println "Copy Runtime"))

  (if (sh "llc" "build/program.ll" "-o" "build/program.s")
    (println "LLVM Bitcode to assembly"))

  (if (sh "clang" "build/runtime.c" "build/program.s" "-o" "build/program")
    (println "Compilation with runtime.")))

(defn clover-compile
  "Emit given program to assembly and compile with runtime."
  [expr]
  (cond
    (integer? expr) (emit (primitive/compile-fixnum expr))))

(defn -main []
  (clover-compile 42)
  (build))
