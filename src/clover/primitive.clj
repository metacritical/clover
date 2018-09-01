(ns clover.primitive
  (:require [clover.llvm-emitter :as emitter]))

 
(defn compile-fixnum [num]
  "Emit llvm fixnum code from template."
  (emitter/clj-int num))
