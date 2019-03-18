(ns clover.types.primitive)

;;TODO : The inline emitter code with Static IR should be defined
;; with clojure native functions.

(defn emit-long [num]
  (str
   "define %struct.Obj* @clj_val() #0 {"
   "  %1 = call %struct.Obj*" "@number(i64 " num ")"
   "  ret %struct.Obj* %1"
   "}"))

(defn emit-bool [bool]
  (str
   "define %struct.Obj* @clj_val() #0 {"
   "  %1 = call %struct.Obj* @boolean(i1 zeroext " bool ")"
   "  ret %struct.Obj* %1"
   "}"))

(defn emit-string [string]
  (let [len (inc (count string))]
    (str
     "@.str = private unnamed_addr constant [" len " x i8] "
     "c\"" string "\\00\", align 1"

     "define %struct.Obj* @clj_val() #0 {"
     "  %1 = call %struct.Obj* @string(i8* getelementptr inbounds ([" len " x i8], [" len " x i8]* @.str, i32 0, i32 0))"
     "  ret %struct.Obj* %1"
     "}")))

(defn emit-nil []
  (str 
   "define %struct.Obj* @clj_val() #0 {"
   "  %1 = call %struct.Obj* @nil()"
   "  ret %struct.Obj* %1"
   "}"))

(defn emit-double [num]
  (str
   "define %struct.Obj* @clj_val() #0 {"
   "  %1 = call %struct.Obj* @fraction(double " num ")"
   "  ret %struct.Obj* %1"
   "}"))

(defn emit-symbol [sym]
  (let [len (inc (count (str sym)))]
    (str
     "@.str = private unnamed_addr constant [" len " x i8] "
     "c\"" sym "\\00\", align 1"

     "define %struct.Obj* @clj_val() #0 {"
     "  %1 = call %struct.Obj* @symbol(i8* getelementptr inbounds ([" len " x i8], [" len " x i8]* @.str, i32 0, i32 0))"
     "  ret %struct.Obj* %1"
     "}")))

(defn emit-keyword [key]
  (let [len (inc (count (str ":" (name key))))]
    (str
     "@.str = private unnamed_addr constant [" len " x i8] "
     "c\"" key "\\00\", align 1"

     "define %struct.Obj* @clj_val() #0 {"
     "  %1 = call %struct.Obj* @keyword(i8* getelementptr inbounds ([" len " x i8], [" len " x i8]* @.str, i32 0, i32 0))"
     "  ret %struct.Obj* %1"
     "}")))

(defn emit-chr [ch]
  (str
   "define %struct.Obj* @clj_val() #0 {"
   "%1 = call %struct.Obj* @character(i8 signext " (int ch) ")"
   "ret %struct.Obj* %1"
   "}"))
