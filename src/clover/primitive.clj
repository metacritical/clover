(ns clover.primitive
  (:require [clover.llvm-emitter :as emitter]))
 
(defn compile-fixnum [num]
  "Emit llvm fixnum code."
  (emitter/clj-int num))

(defn compile-boolean [bool]
  "Emit llvm boolean code."
  (emitter/clj-bool bool))

(defn compile-nil [nl]
  "Emit llvm null code."
  (emitter/clj-nil nl))

(defn compile-string [strn]
  "Emit llvm string code."
  (emitter/clj-str strn))

;; (defn compile-char [chr]
  ;; "Emit llvm character code."
  ;; (emitter/clj-char chr))
