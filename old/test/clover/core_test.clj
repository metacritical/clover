(ns clover.core-test
  (:require [clojure.test :refer :all]
            [clover.core :refer :all]))

(deftest test-fixnums
  (testing "Fixnum to machine code"
    (is (= 0 1))))
