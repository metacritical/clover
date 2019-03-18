(ns clover.driver
  (:use [clojure.java.io :as io])
  (:require [clojure.string :as str]
            [clojure.tools.analyzer :as ana]
            [clojure.java.shell :as shell]
            [clojure.tools.analyzer.env :as env])
  (:import java.io.File)
  (:gen-class))

(defn exec [cmd err-msg]
  (let [sh-out (shell/sh "/bin/sh" :in cmd)]
    (if (= (sh-out :err) "")
      (sh-out :out)
      (do
        (printf (str "\033[31;1m" (sh-out :err) "\033[0m"))
        err-msg))))

(defn cache-cleanup [tmpdir]
  (if (.exists (io/as-file (str tmpdir "program")))
    (io/delete-file (str tmpdir "program"))))

(defn build-and-run [clj-vars]
  (let [tmpdir (str (System/getProperty "java.io.tmpdir") "_clover_cache/")]
    (if-not (.exists (io/file tmpdir))
      (.mkdir (File. tmpdir)))

    ;; Delete Previous program file
    (cache-cleanup (str tmpdir "program"))

    ;; Spits clj-vars + expr bit code program file.
    (spit (str tmpdir "program.ll") clj-vars)
    
    ;; Copies runtime to temp directory.
    (io/copy (io/file "runtime/runtime.c") (io/file (str tmpdir "runtime.c")))

    ;;Compile emitted bitcode to assembly.
    (exec (str "llc " (str tmpdir "program.ll") " -o " (str tmpdir "program.s"))
          "# LLVM Bitcode to assembly.")
    ;;Compile and link with runtime.
    (exec (str "clang " " $(pkg-config --cflags glib-2.0) " "$(pkg-config --libs glib-2.0)" " -lglib-2.0 "  (str tmpdir "runtime.c")
               " " (str tmpdir "program.s") " -o " (str tmpdir "program")) "# Compile Failure")
    ;;Run program.
    (if (.exists (io/file (str tmpdir "program")))
      (exec (str tmpdir "program") "# Program build error.\n")
      (println "Execution Error."))))
