(ns clover.parser
  (:require [clover.compiler :as compiler]))

(def core-map
  #{:> :< := :+ :* :- :/ :fn :def :defn
    :cons :conj :for :if :do :let :quote
    :var :loop :recur :throw :try :. :new
    :set!})

(defn reserved? [key]
  (contains? core-map (keyword key)))

(declare parse-list parse-primitives parse-fn)

;; TODO
;; Should implement some kind of Hindley-Milner Type Inference system
;; For parsing these types more efficiently.

(defmulti parse (fn [form] (type form)))

(defmethod parse clojure.lang.Keyword
  [expr]
  (compiler/emit expr))

(defmethod parse clojure.lang.Cons
  [[head & rst]]
  (compiler/emit (cons head rst)))

(defmethod parse clojure.lang.PersistentList
  [expr]
  (let [[head & rst] expr]
    (cond
      (reserved? head) (compiler/emit rst (keyword head))
      :else (compiler/emit expr))))

(defmethod parse :default [expr] (compiler/emit expr))

;; Implement these seqs.
;; (1 2 3)
;; (+ 1 2 3)
;; (def x 1)
;; (fn [x] (x))

;; Need a cond-let macro here will add it later.
;; (defn parse-list [expr]
  ;; (let [ast (zip/down (zip/vector-zip expr))]
    ;; (let [head (zip/node ast)]
      ;; (println ast)
      ;; (cond
        ;; (primitive? head) (compiler/emit ast (prim-map head))
        ;; (special-form? head) (compiler/emit ast (keyword head))))))
