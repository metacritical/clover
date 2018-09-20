(ns clover.parser
  (:require [clojure.zip :as zip]
            [clojure.walk :as walk]
            [clojure.string :as str]
            [clover.compiler :as compiler]))

;; Implement these seqs.
;; (1 2 3)
;; (+ 1 2 3)
;; (def x 1)
;; (fn [x] (x))

(defn char-map [sym]
  (get {:<    "_GT_"
        :>    "_LT_"
        :=    "_EQ_"
        :def  "_DEF_"
        :*    "_STAR_"
        :+    "_PLUS_"
        :defn "_FUNC_"
        :-    "_MINUS_"
        :/    "_SLASH_"
        } sym))

(declare parse-list)

(defmulti parse (fn [form] (type form)))

(defmethod parse clojure.lang.Keyword
  [expr]
  (case expr
    :reload (do (require 'clover.core :reload-all) :ok)
    :exit (System/exit 0)
    expr))

(defmethod parse clojure.lang.Cons
  [expr]
  (parse-list expr))

(defmethod parse clojure.lang.PersistentList
  [expr]
  (parse-list expr))

(defmethod parse :default [expr] expr)

(defn parse-list [expr]
  (let [root (zip/vector-zip (into [] expr))]
    (let [ast (zip/down root)]
      ast)))
