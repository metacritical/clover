define i64 @dec() #0 {
  %1 = call i64 @sub_one(i64 42)
  ret i64 %1
}
