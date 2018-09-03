(ns clover.llvm-emitter)

(defn clj-int [num]
  (format (slurp "llvm-bc/clj-int.ll") num))

(defn clj-bool [bool]
  (cond 
    (false? bool) (format (slurp "llvm-bc/clj-bool.ll") false)
    :else (format (slurp "llvm-bc/clj-bool.ll") true)))
