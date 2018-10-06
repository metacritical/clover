(ns clover.parser
  (:require [clojure.tools.analyzer :as ana]
            [clover.types.primitive :as prim]
            [clojure.tools.analyzer.ast :as ast]
            [clojure.tools.analyzer.env :as env]
            [clover.types.special-forms :as special]
            [clojure.tools.analyzer.jvm :as anal.jvm])
  (:use [io.aviso.repl]
        [io.aviso.ansi]))

(install-pretty-exceptions)

(def core-map
  #{:> :< := :+ :* :- :/ :fn :def :defn
    :cons :conj :for :if :do :let :quote
    :var :loop :recur :throw :try :. :new
    :set!})

(defn analyze [expr]
  (let [nodes (ast/nodes (anal.jvm/analyze expr))]
    (loop [[frst & rst] nodes]
      (if (empty? rst)
        (clojure.pprint/pprint frst)
        (do
          (clojure.pprint/pprint frst)
          (recur rst))))))

;; (defmulti parse
  ;; "Parse and emit given program to assembly and compile with runtime."
  ;; (fn var-dispatch
    ;; ([form] (:op form))))

;; (defmulti parse
;;   "Parse and emit given program to assembly and compile with runtime."
;;   (fn var-dispatch
;;     ([form] (type form))
;;     ([form signature] [(type form) signature])))

;; (defmethod parse Long
;;   [expr]
;;   (prim/emit-long expr))

;; (defmethod parse Double
;;   [expr]
;;   (prim/emit-double expr))

;; (defmethod parse String
;;   [expr]
;;   (prim/emit-string expr))

;; (defmethod parse Boolean
;;   [expr]
;;   (prim/emit-bool expr))

;; (defmethod parse nil
;;   [expr]
;;   (prim/emit-nil))

;; (defmethod parse Character
;;   [expr]
;;   (prim/emit-chr expr))

;; (defmethod parse clojure.lang.Keyword
;;   [expr]
;;   (prim/emit-keyword expr))

;; (defmethod parse clojure.lang.Symbol
;;   [expr]
;;   (prim/emit-symbol expr))

;; (defmethod parse clojure.lang.Cons
;;   [expr]
;;   (special/emit-cons expr))

;; (defmethod parse clojure.lang.PersistentList
;;   [expr]
;;   (special/emit-list (first expr) (rest expr)))

;; (defmethod parse clojure.lang.PersistentList$EmptyList
;;   [expr]
;;   (prim/emit-nil))

;; (defmethod parse [clojure.lang.PersistentList :def]
;;   [expr sign]
;;   (special/emit-def (parse sign) (parse expr)))

;; (defmethod parse [clojure.lang.PersistentList :fn]
;;   [expr sign]
;;   (special/emit-fn expr))

;; ;; (defn reserved? [key]
  ;; (contains? core-map (keyword key)))

;; (declare parse-list parse-primitives parse-fn)

;; (defmulti parse (fn [form] (type form)))

;; (defmethod parse clojure.lang.Keyword
  ;; [expr]
  ;; (compiler/emit expr))

;; (defmethod parse clojure.lang.Cons
  ;; [[head & rst]]
  ;; (compiler/emit (cons head rst)))

;; (defmethod parse clojure.lang.PersistentList
  ;; [expr]
  ;; (let [[head & rst] expr]
    ;; (cond
      ;; (reserved? head) (compiler/emit rst (keyword head))
      ;; :else (compiler/emit expr))))

;; (defmethod parse :default [expr] (compiler/emit expr))

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
