(ns clover.driver
  (:use [clojure.java.io :as io]
        [clover.primitive :as primitive])
  (:require [clojure.string :as str]
            [clojure.tools.analyzer :as ana]
            [clojure.java.shell :as shell]
            [clojure.tools.analyzer.env :as env])
  (:gen-class))

;;TODO: These build instructions should be produced dynamically
;;and create a Makefile.
(defn shell-exec [cmd err-msg]
  (let [sh-out (shell/sh "/bin/sh" :in cmd)]
    (if (= (sh-out :err) "")
      (print (sh-out :out))
      (do
        (println err-msg)
        (println (sh-out :err))))))

(defn cache-cleanup [] 
  (if (.exists (io/as-file "build/program"))
    (io/delete-file "build/program")))

(defn build-run []
  (io/copy (io/file "runtime/runtime.c") (io/file "build/runtime.c"))

  (shell-exec "llc build/program.ll -o build/program.s" 
              "# LLVM Bitcode to assembly.")

  (shell-exec "clang build/runtime.c build/program.s -o build/program"
              "# Compile Failure")

  (shell-exec "build/program" "# Program build error."))

(defn emit [expr]
  (spit "build/program.ll" (str (slurp "bitcode/clj-vars.ll") expr)))

(defn clover-compile
  "Emit given program to assembly and compile with runtime."
  [expr]
  (cond
    (integer? expr)
    (emit (primitive/compile-fixnum expr))
    
    (double? expr)
    (emit (primitive/compile-double expr))
    
    (string? expr)
    (emit (primitive/compile-string expr))
    
    (boolean? expr)
    (emit (primitive/compile-boolean expr))
    
    (nil? expr)
    (emit (primitive/compile-nil))

    (list? expr)
    (emit (primitive/compile-defn expr))

    :else (println "Unable to resolve symbol:" expr "in this context")))
