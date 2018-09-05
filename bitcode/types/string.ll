@.str = private unnamed_addr constant [26 x i8] c"Hello World is not enough\00", align 1

; Function Attrs: noinline nounwind optnone ssp uwtable
define %struct.Vars* @clj_val() #0 {
  %1 = call %struct.Vars* @string(i8* getelementptr inbounds ([26 x i8], [26 x i8]* @.str, i32 0, i32 0))
  ret %struct.Vars* %1
}
