(ns clover.types.special-forms)

(defn emit-def [sign expr]
  (str sign " " expr))

(defn emit-fn [lst]
  (str lst))

(defn emit-cons [lst]
  (str lst))

(defn emit-list [frst rst]
  (str frst rst))
