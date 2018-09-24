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

(defn char-map [key]
  (get {:> "_GT_"
        :< "_LT_"
        := "_EQ_"
        :+ "_PLUS_"
        :* "_STAR_"
        :- "_MINUS_"
        :/ "_SLASH_"} (keyword key)))

(defn primitive? [key]
  (if (char-map key) true))

(defn special-map [key]
  (get {:fn "_LAMBDA_"
        :def "_BINDING_"
        :defn "_FUNCTION_"
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

(defn special-form? [key]
  (if (special-map key) true))

(declare parse-list parse-primitives parse-fn)

(defmulti parse (fn [form] (type form)))

(defmethod parse clojure.lang.Keyword
  [expr]
  (case expr
    :reload (do (require 'clover.core :reload-all) :ok)
    :exit (System/exit 0)
    expr))

(defmethod parse clojure.lang.Cons
  [expr]
  (parse-list (into [] expr)))

(defmethod parse clojure.lang.PersistentList
  [expr]
  (parse-list (into [] expr)))

(defmethod parse :default [expr] expr)

;; Need a cond-let macro here will add it later.
(defn parse-list [expr]
  (let [ast (zip/down (zip/vector-zip expr))]
    (let [head (zip/node ast)]
      (cond
        (primitive? head) (parse-fn ast)
        (special-form? head) (parse-fn ast)))))

(defn parse-fn
  ([ast]
   (let [head (zip/node ast) rst (rest ast)]
     (str "First : " head " " "Rest : " rst))))
