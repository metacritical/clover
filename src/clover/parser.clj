(ns clover.parser
  (:require [clojure.string :as str]
            [clojure.walk :as walk]
            [clojure.zip :as z]))

;; Implement these seqs.
;; (1 2 3)
;; (+ 1 2 3)
;; (def x 1)
;; (fn [x] (x))

(declare parse-list)

(defn parse
  [expr]
  (case (seq? expr)
    true (parse-list expr)
    expr))

(defn parse-list [lst]
  (str "List : "lst))
