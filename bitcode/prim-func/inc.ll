define i64 @inc() #0 {
  %1 = call i64 @add_one(i64 42)
  ret i64 %1
}
