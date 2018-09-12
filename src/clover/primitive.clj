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

;; TODO: There are two ingredients to making a primitive function.
;; 1. Binding type (def a 2)
;; 2. Procedure  (fn [x] (+ 1 x))
;; 3. Both def for binding and lambda for function are created using core
;; primitive functions in C.
;; 4. Variadic functions would use C's variadic functionality.
;; Both of these require an evironment to store the values in FOr now we will
;; Glib hash table as environment because it has generally good performance
;; and constant memory usage and complexity in both read and write operations

;; TODO: Experimental Code For testing would be deleted eventually.
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
