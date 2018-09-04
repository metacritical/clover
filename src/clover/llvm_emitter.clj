(ns clover.llvm-emitter)

(defn clj-int [num]
  (format (slurp "bitcode/number.ll") num))

(defn clj-bool [bool]
  (cond 
    (false? bool) (format (slurp "llvm-bc/clj-bool.ll") false)
    :else (format (slurp "llvm-bc/clj-bool.ll") true)))
