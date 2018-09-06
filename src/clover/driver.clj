(ns clover.driver
  (:use [clojure.java.io :as io]
        [clover.primitive :as primitive]))

(use '[clojure.java.shell :only [sh]])

;;TODO: These build instructions should be produced dynamically
;;and create a Makefile.
(defn build-run []
  (if (sh "rm" "build/*")
    (println "Build Cleanup."))

  (if (sh "cp" "runtime/runtime.c" "build/")
    (println "Copy Runtime"))

  (if (sh "llc" "build/program.ll" "-o" "build/program.s")
    (println "LLVM Bitcode to assembly"))

  (if (sh "clang" "build/runtime.c" "build/program.s" "-o" "build/program")
    (println "Compile and Link with runtime."))

  (if (.exists (io/as-file "build/program"))
    (let [sh-out (sh "build/program")]
      (if (= (sh-out :err) "")
        (println (sh-out :out))
        (println (sh-out :err))))
    (println "Program Build Error.")))

(defn emit [expr]
  (spit "build/program.ll" (str (slurp "bitcode/clj-vars.ll") expr))) 

(defn clover-compile
  "Emit given program to assembly and compile with runtime."
  [expr]
  (cond
    (integer? expr) (emit (primitive/compile-fixnum expr))
    (double? expr) (emit (primitive/compile-double expr))
    (string? expr) (emit (primitive/compile-string expr))
    (boolean? expr) (emit (primitive/compile-boolean expr))))
