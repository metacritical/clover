(ns clover.compiler
  (:require [clover.primitive :as primitive]))

(defn clover-compile
  "Emit given program to assembly and compile with runtime."
  [expr]
  (cond
    (integer? expr)
    (primitive/compile-fixnum expr)

    (double? expr)
    (primitive/compile-double expr)

    (string? expr)
    (primitive/compile-string expr)

    (boolean? expr)
    (primitive/compile-boolean expr)

    (nil? expr)
    (primitive/compile-nil)

    (keyword? expr)
    (primitive/compile-keyword expr)

    (symbol? expr)
    (primitive/compile-symbol expr)

    (char? expr)
    (primitive/compile-chr expr)

    (list? expr)
    (primitive/compile-defn expr)

    :else (println "Unable to resolve symbol:" expr "in this context")
    ;; (throw (Exception. "Fell through"))
    ))
