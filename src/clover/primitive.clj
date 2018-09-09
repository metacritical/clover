(ns clover.primitive
  (:require [clover.llvm-emitter :as emitter])
  (:gen-class))
 
(defn compile-fixnum [num]
  "Emit llvm fixnum bitcode."
  (emitter/clj-fixnum num))

(defn compile-boolean [bool]
  "Emit llvm boolean bitcode."
  (emitter/clj-bool bool))

(defn compile-nil []
  "Emit llvm null bitcode."
  (emitter/clj-nil))

(defn compile-string [string]
  "Emit llvm string bitcode."
  (emitter/clj-str string))

(defn compile-double [num]
  "Emit llvm double bitcode."
  (emitter/clj-double num))

(defn compile-keyword [key]
  "Emit llvm keyword bitcode"
  (emitter/clj-keyword key))

(defn compile-symbol [sym]
  "Emit llvm symbol bitcode."
  (emitter/clj-symbol sym))

(defn compile-chr [chr]
  "Emit llvm character bitcode."
  (emitter/clj-chr chr))

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
