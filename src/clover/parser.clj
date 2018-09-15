(ns clover.parser
  (:use [clojure.walk]))

(defn parse-list [expr]
  (walk/postwalk #() expr))
