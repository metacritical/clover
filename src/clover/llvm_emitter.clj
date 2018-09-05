(ns clover.llvm-emitter)

(defn clj-int [num]
  (str "define %struct.Vars* @clj_val() #0 {
    %1 = call %struct.Vars*" "@number(i64 " num ") 
    ret %struct.Vars* %1
  }"))

(defn clj-bool [bool]
  (str "define %struct.Vars* @clj_val() #0 {
    %1 = call %struct.Vars* @boolean(i1 zeroext " bool")
    ret %struct.Vars* %1
  }"))

(defn clj-nil [nl]
  nil)
