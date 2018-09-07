(ns clover.llvm-emitter)

(defn clj-int [num]
  (str
   "define %struct.Vars* @clj_val() #0 {"
   "  %1 = call %struct.Vars*" "@number(i64 " num ")"
   "  ret %struct.Vars* %1"
   "}"))

(defn clj-bool [bool]
  (str
   "define %struct.Vars* @clj_val() #0 {"
   "  %1 = call %struct.Vars* @boolean(i1 zeroext " bool ")"
   "  ret %struct.Vars* %1"
   "}"))

(defn clj-str [string]
  (let [len (inc (count string))]
    (str
     "@.str = private unnamed_addr constant [" len " x i8] "
     "c\"" string "\\00\", align 1"

      "define %struct.Vars* @clj_val() #0 {"
      "  %1 = call %struct.Vars* @string(i8* getelementptr inbounds ([" len " x i8], [" len " x i8]* @.str, i32 0, i32 0))"
      "  ret %struct.Vars* %1"
      "}")))

(defn clj-nil []
  (str 
   "define %struct.Vars* @clj_val() #0 {"
   "  %1 = call %struct.Vars* @nil()"
   "  ret %struct.Vars* %1"
   "}"))

(defn clj-double [num]
  (str
   "define %struct.Vars* @clj_val() #0 {"
   "  %1 = call %struct.Vars* @fraction(double " num ")"
   "  ret %struct.Vars* %1"
   "}"))

(defn clj-char [chr]
  "")

(defn clj-inc [num]
  str
  "define i64 @inc() #0 {"
  "  %1 = call i64 @add_one(i64 " num ")"
  "  ret i64 %1"
  "}")


(defn clj-dec [num]
  str
  "define i64 @dec() #0 {"
  "  %1 = call i64 @sub_one(i64 " num ")"
  "  ret i64 %1"
  "}")

