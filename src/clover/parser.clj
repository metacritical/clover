(ns clover.parser
  (:require [clover.compiler :as compiler]))

;; Implement these seqs.
;; (1 2 3)
;; (+ 1 2 3)
;; (def x 1)
;; (fn [x] (x))

(defn core-map [key]
  (get {:> "_GT_"
        :< "_LT_"
        := "_EQ_"
        :+ "_PLUS_"
        :* "_STAR_"
        :- "_MINUS_"
        :/ "_SLASH_"
        :fn "_LAMBDA_"
        :def "_BINDING_"
        :defn "_FUNCTION_"
        :cons "_CONS_"
        :conj "_CONJ_"
        :for "_FOR_"
        :if "_IF_"
        :do "_DO_"
        :let "_LET_"
        :quote "_QUOTE_"
        :var "_VAR_"
        :loop "_LOOP_"
        :recur "_RECUR_"
        :throw "_THROW_"
        :try "_TRY_"
        :. "_DOT_"
        :new "_NEW_"
        :set! "_SET_"
        } (keyword key)))

(defn reserved? [key]
  (if (core-map key) true))

(declare parse-list parse-primitives parse-fn)

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

;; Need a cond-let macro here will add it later.
;; (defn parse-list [expr]
  ;; (let [ast (zip/down (zip/vector-zip expr))]
    ;; (let [head (zip/node ast)]
      ;; (println ast)
      ;; (cond
        ;; (primitive? head) (compiler/emit ast (prim-map head))
        ;; (special-form? head) (compiler/emit ast (keyword head))))))
