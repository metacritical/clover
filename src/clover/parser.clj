(ns clover.parser
  (:require [clojure.string :as str]
            [clojure.walk :as walk]
            [clojure.zip :as zip]))

;; Implement these seqs.
;; (1 2 3)
;; (+ 1 2 3)
;; (def x 1)
;; (fn [x] (x))

(defmulti parse (fn [form] (type form)))

(defmethod parse clojure.lang.Keyword
  [expr]
  (case expr
    :reload (do (require 'clover.core :reload-all) :ok)
    :exit (System/exit 0)
    expr))

(defmethod parse clojure.lang.PersistentList
  [expr]
  (let [root (zip/vector-zip (into [] expr))]
    (str (zip/down root))))

(defmethod parse :default [expr] expr)
