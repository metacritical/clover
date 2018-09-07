(ns clover.primitive
  (:require [clover.llvm-emitter :as emitter])
  (:gen-class))
 
(defn compile-fixnum [num]
  "Emit llvm fixnum code."
  (emitter/clj-int num))

(defn compile-boolean [bool]
  "Emit llvm boolean code."
  (emitter/clj-bool bool))

(defn compile-nil []
  "Emit llvm null code."
  (emitter/clj-nil))

(defn compile-string [string]
  "Emit llvm string code."
  (emitter/clj-str string))

(defn compile-double [num]
  "Emit llvm double/float code."
  (emitter/clj-double num))

(defn compile-char [chr]
  "Emit llvm character code."
  (emitter/clj-char chr))

(defn compile-unary [expr]
  (case (first expr)
    inc (emitter/clj-inc num)
    dec (emitter/clj-dec num)))

(defn compile-variadic [expr]
  "")

(defn compile-defn [expr]
  (if (< 2 (count expr))
    (compile-unary expr)
    (compile-variadic expr)))
