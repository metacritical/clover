(ns clover.llvm-emitter)

(defn clj-int [num]
  (format (slurp "llvm_templates/clj-int.ll") num))
