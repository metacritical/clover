%struct.Vars = type { i32, %union.values }
%union.values = type { i64 }

; Function Attrs: noinline nounwind optnone ssp uwtable
define %struct.Vars* @createVars() #0 {
  %1 = alloca %struct.Vars*, align 8
  %2 = call i8* @malloc(i64 16) #2
  %3 = bitcast i8* %2 to %struct.Vars*
  store %struct.Vars* %3, %struct.Vars** %1, align 8
  %4 = load %struct.Vars*, %struct.Vars** %1, align 8
  ret %struct.Vars* %4
}

; Function Attrs: allocsize(0)
declare i8* @malloc(i64) #1

; Function Attrs: noinline nounwind optnone ssp uwtable
define %struct.Vars* @createInteger(i64) #0 {
  %2 = alloca i64, align 8
  %3 = alloca %struct.Vars*, align 8
  store i64 %0, i64* %2, align 8
  %4 = call %struct.Vars* @createVars()
  store %struct.Vars* %4, %struct.Vars** %3, align 8
  %5 = load %struct.Vars*, %struct.Vars** %3, align 8
  %6 = getelementptr inbounds %struct.Vars, %struct.Vars* %5, i32 0, i32 0
  store i32 1, i32* %6, align 8
  %7 = load i64, i64* %2, align 8
  %8 = load %struct.Vars*, %struct.Vars** %3, align 8
  %9 = getelementptr inbounds %struct.Vars, %struct.Vars* %8, i32 0, i32 1
  %10 = bitcast %union.values* %9 to i64*
  store i64 %7, i64* %10, align 8
  %11 = load %struct.Vars*, %struct.Vars** %3, align 8
  ret %struct.Vars* %11
}

; Function Attrs: noinline nounwind optnone ssp uwtable
define %struct.Vars* @createBool(i1 zeroext) #0 {
  %2 = alloca i8, align 1
  %3 = alloca %struct.Vars*, align 8
  %4 = zext i1 %0 to i8
  store i8 %4, i8* %2, align 1
  %5 = call %struct.Vars* @createVars()
  store %struct.Vars* %5, %struct.Vars** %3, align 8
  %6 = load %struct.Vars*, %struct.Vars** %3, align 8
  %7 = getelementptr inbounds %struct.Vars, %struct.Vars* %6, i32 0, i32 0
  store i32 4, i32* %7, align 8
  %8 = load i8, i8* %2, align 1
  %9 = trunc i8 %8 to i1
  %10 = load %struct.Vars*, %struct.Vars** %3, align 8
  %11 = getelementptr inbounds %struct.Vars, %struct.Vars* %10, i32 0, i32 1
  %12 = bitcast %union.values* %11 to i8*
  %13 = zext i1 %9 to i8
  store i8 %13, i8* %12, align 8
  %14 = load %struct.Vars*, %struct.Vars** %3, align 8
  ret %struct.Vars* %14
}

; Function Attrs: noinline nounwind optnone ssp uwtable
define %struct.Vars* @createNIL() #0 {
  %1 = alloca %struct.Vars*, align 8
  %2 = call %struct.Vars* @createVars()
  store %struct.Vars* %2, %struct.Vars** %1, align 8
  %3 = load %struct.Vars*, %struct.Vars** %1, align 8
  %4 = getelementptr inbounds %struct.Vars, %struct.Vars* %3, i32 0, i32 0
  store i32 0, i32* %4, align 8
  %5 = load %struct.Vars*, %struct.Vars** %1, align 8
  %6 = getelementptr inbounds %struct.Vars, %struct.Vars* %5, i32 0, i32 1
  %7 = bitcast %union.values* %6 to i32**
  store i32* null, i32** %7, align 8
  %8 = load %struct.Vars*, %struct.Vars** %1, align 8
  ret %struct.Vars* %8
}

; Function Attrs: noinline nounwind optnone ssp uwtable
define %struct.Vars* @createFraction(double) #0 {
  %2 = alloca double, align 8
  %3 = alloca %struct.Vars*, align 8
  store double %0, double* %2, align 8
  %4 = call %struct.Vars* @createVars()
  store %struct.Vars* %4, %struct.Vars** %3, align 8
  %5 = load %struct.Vars*, %struct.Vars** %3, align 8
  %6 = getelementptr inbounds %struct.Vars, %struct.Vars* %5, i32 0, i32 0
  store i32 2, i32* %6, align 8
  %7 = load double, double* %2, align 8
  %8 = load %struct.Vars*, %struct.Vars** %3, align 8
  %9 = getelementptr inbounds %struct.Vars, %struct.Vars* %8, i32 0, i32 1
  %10 = bitcast %union.values* %9 to double*
  store double %7, double* %10, align 8
  %11 = load %struct.Vars*, %struct.Vars** %3, align 8
  ret %struct.Vars* %11
}

; Function Attrs: noinline nounwind optnone ssp uwtable
define %struct.Vars* @createString(i8*) #0 {
  %2 = alloca i8*, align 8
  %3 = alloca %struct.Vars*, align 8
  store i8* %0, i8** %2, align 8
  %4 = call %struct.Vars* @createVars()
  store %struct.Vars* %4, %struct.Vars** %3, align 8
  %5 = load %struct.Vars*, %struct.Vars** %3, align 8
  %6 = getelementptr inbounds %struct.Vars, %struct.Vars* %5, i32 0, i32 0
  store i32 3, i32* %6, align 8
  %7 = load i8*, i8** %2, align 8
  %8 = load %struct.Vars*, %struct.Vars** %3, align 8
  %9 = getelementptr inbounds %struct.Vars, %struct.Vars* %8, i32 0, i32 1
  %10 = bitcast %union.values* %9 to i8**
  store i8* %7, i8** %10, align 8
  %11 = load %struct.Vars*, %struct.Vars** %3, align 8
  ret %struct.Vars* %11
}

; Function Attrs: noinline nounwind optnone ssp uwtable
define %struct.Vars* @createSymbol(i8*) #0 {
  %2 = alloca i8*, align 8
  %3 = alloca %struct.Vars*, align 8
  store i8* %0, i8** %2, align 8
  %4 = call %struct.Vars* @createVars()
  store %struct.Vars* %4, %struct.Vars** %3, align 8
  %5 = load %struct.Vars*, %struct.Vars** %3, align 8
  %6 = getelementptr inbounds %struct.Vars, %struct.Vars* %5, i32 0, i32 0
  store i32 5, i32* %6, align 8
  %7 = load i8*, i8** %2, align 8
  %8 = load %struct.Vars*, %struct.Vars** %3, align 8
  %9 = getelementptr inbounds %struct.Vars, %struct.Vars* %8, i32 0, i32 1
  %10 = bitcast %union.values* %9 to i8**
  store i8* %7, i8** %10, align 8
  %11 = load %struct.Vars*, %struct.Vars** %3, align 8
  ret %struct.Vars* %11
}

; Function Attrs: noinline nounwind optnone ssp uwtable
define %struct.Vars* @number(i64) #0 {
  %2 = alloca i64, align 8
  %3 = alloca %struct.Vars*, align 8
  store i64 %0, i64* %2, align 8
  %4 = load i64, i64* %2, align 8
  %5 = call %struct.Vars* @createInteger(i64 %4)
  store %struct.Vars* %5, %struct.Vars** %3, align 8
  %6 = load %struct.Vars*, %struct.Vars** %3, align 8
  ret %struct.Vars* %6
}

; Function Attrs: noinline nounwind optnone ssp uwtable
define %struct.Vars* @boolean(i1 zeroext) #0 {
  %2 = alloca i8, align 1
  %3 = alloca %struct.Vars*, align 8
  %4 = zext i1 %0 to i8
  store i8 %4, i8* %2, align 1
  %5 = load i8, i8* %2, align 1
  %6 = trunc i8 %5 to i1
  %7 = call %struct.Vars* @createBool(i1 zeroext %6)
  store %struct.Vars* %7, %struct.Vars** %3, align 8
  %8 = load %struct.Vars*, %struct.Vars** %3, align 8
  ret %struct.Vars* %8
}

define %struct.Vars* @string(i8*) #0 {
  %2 = alloca i8*, align 8
  %3 = alloca %struct.Vars*, align 8
  store i8* %0, i8** %2, align 8
  %4 = load i8*, i8** %2, align 8
  %5 = call %struct.Vars* @createString(i8* %4)
  store %struct.Vars* %5, %struct.Vars** %3, align 8
  %6 = load %struct.Vars*, %struct.Vars** %3, align 8
  ret %struct.Vars* %6
}

define %struct.Vars* @fraction(double) #0 {
  %2 = alloca double, align 8
  %3 = alloca %struct.Vars*, align 8
  store double %0, double* %2, align 8
  %4 = load double, double* %2, align 8
  %5 = call %struct.Vars* @createFraction(double %4)
  store %struct.Vars* %5, %struct.Vars** %3, align 8
  %6 = load %struct.Vars*, %struct.Vars** %3, align 8
  ret %struct.Vars* %6
}

define %struct.Vars* @nil() #0 {
  %1 = alloca %struct.Vars*, align 8
  %2 = call %struct.Vars* @createNIL()
  store %struct.Vars* %2, %struct.Vars** %1, align 8
  %3 = load %struct.Vars*, %struct.Vars** %1, align 8
  ret %struct.Vars* %3
}

define i64 @add_one(i64) #0 {
  %2 = alloca i64, align 8
  store i64 %0, i64* %2, align 8
  %3 = load i64, i64* %2, align 8
  %4 = add nsw i64 %3, 1
  ret i64 %4
}

define i64 @sub_one(i64) #0 {
  %2 = alloca i64, align 8
  store i64 %0, i64* %2, align 8
  %3 = load i64, i64* %2, align 8
  %4 = sub nsw i64 %3, 1
  ret i64 %4
}
