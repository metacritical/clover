define i64 @sub_one(i64) #0 {
  %2 = alloca i64, align 8
  store i64 %0, i64* %2, align 8
  %3 = load i64, i64* %2, align 8
  %4 = sub nsw i64 %3, 1
  ret i64 %4
}

define i64 @dec() #0 {
  %1 = call i64 @sub_one(i64 42)
  ret i64 %1
}
