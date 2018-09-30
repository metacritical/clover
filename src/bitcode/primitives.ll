%struct.Obj = type { i32, %union.values }
%union.values = type { %struct.anon }
%struct.anon = type { {}*, %struct.Obj*, %struct.Obj*, i32 }
%struct._GHashTable = type opaque

; Function Attrs: noinline nounwind optnone ssp uwtable
define %struct.Obj* @createObj() #0 {
  %1 = alloca %struct.Obj*, align 8
  %2 = call i8* @malloc(i64 40) #3
  %3 = bitcast i8* %2 to %struct.Obj*
  store %struct.Obj* %3, %struct.Obj** %1, align 8
  %4 = load %struct.Obj*, %struct.Obj** %1, align 8
  ret %struct.Obj* %4
}

; Function Attrs: allocsize(0)
declare i8* @malloc(i64) #1

; Function Attrs: noinline nounwind optnone ssp uwtable
define %struct.Obj* @createInteger(i64) #0 {
  %2 = alloca i64, align 8
  %3 = alloca %struct.Obj*, align 8
  store i64 %0, i64* %2, align 8
  %4 = call %struct.Obj* @createObj()
  store %struct.Obj* %4, %struct.Obj** %3, align 8
  %5 = load %struct.Obj*, %struct.Obj** %3, align 8
  %6 = getelementptr inbounds %struct.Obj, %struct.Obj* %5, i32 0, i32 0
  store i32 7, i32* %6, align 8
  %7 = load i64, i64* %2, align 8
  %8 = load %struct.Obj*, %struct.Obj** %3, align 8
  %9 = getelementptr inbounds %struct.Obj, %struct.Obj* %8, i32 0, i32 1
  %10 = bitcast %union.values* %9 to i64*
  store i64 %7, i64* %10, align 8
  %11 = load %struct.Obj*, %struct.Obj** %3, align 8
  ret %struct.Obj* %11
}

; Function Attrs: noinline nounwind optnone ssp uwtable
define %struct.Obj* @createBool(i1 zeroext) #0 {
  %2 = alloca i8, align 1
  %3 = alloca %struct.Obj*, align 8
  %4 = zext i1 %0 to i8
  store i8 %4, i8* %2, align 1
  %5 = call %struct.Obj* @createObj()
  store %struct.Obj* %5, %struct.Obj** %3, align 8
  %6 = load %struct.Obj*, %struct.Obj** %3, align 8
  %7 = getelementptr inbounds %struct.Obj, %struct.Obj* %6, i32 0, i32 0
  store i32 6, i32* %7, align 8
  %8 = load i8, i8* %2, align 1
  %9 = trunc i8 %8 to i1
  %10 = load %struct.Obj*, %struct.Obj** %3, align 8
  %11 = getelementptr inbounds %struct.Obj, %struct.Obj* %10, i32 0, i32 1
  %12 = bitcast %union.values* %11 to i8*
  %13 = zext i1 %9 to i8
  store i8 %13, i8* %12, align 8
  %14 = load %struct.Obj*, %struct.Obj** %3, align 8
  ret %struct.Obj* %14
}

; Function Attrs: noinline nounwind optnone ssp uwtable
define %struct.Obj* @createNIL() #0 {
  %1 = alloca %struct.Obj*, align 8
  %2 = call %struct.Obj* @createObj()
  store %struct.Obj* %2, %struct.Obj** %1, align 8
  %3 = load %struct.Obj*, %struct.Obj** %1, align 8
  %4 = getelementptr inbounds %struct.Obj, %struct.Obj* %3, i32 0, i32 0
  store i32 0, i32* %4, align 8
  %5 = load %struct.Obj*, %struct.Obj** %1, align 8
  %6 = getelementptr inbounds %struct.Obj, %struct.Obj* %5, i32 0, i32 1
  %7 = bitcast %union.values* %6 to i32**
  store i32* null, i32** %7, align 8
  %8 = load %struct.Obj*, %struct.Obj** %1, align 8
  ret %struct.Obj* %8
}

; Function Attrs: noinline nounwind optnone ssp uwtable
define %struct.Obj* @createFraction(double) #0 {
  %2 = alloca double, align 8
  %3 = alloca %struct.Obj*, align 8
  store double %0, double* %2, align 8
  %4 = call %struct.Obj* @createObj()
  store %struct.Obj* %4, %struct.Obj** %3, align 8
  %5 = load %struct.Obj*, %struct.Obj** %3, align 8
  %6 = getelementptr inbounds %struct.Obj, %struct.Obj* %5, i32 0, i32 0
  store i32 8, i32* %6, align 8
  %7 = load double, double* %2, align 8
  %8 = load %struct.Obj*, %struct.Obj** %3, align 8
  %9 = getelementptr inbounds %struct.Obj, %struct.Obj* %8, i32 0, i32 1
  %10 = bitcast %union.values* %9 to double*
  store double %7, double* %10, align 8
  %11 = load %struct.Obj*, %struct.Obj** %3, align 8
  ret %struct.Obj* %11
}

; Function Attrs: noinline nounwind optnone ssp uwtable
define %struct.Obj* @createString(i8*) #0 {
  %2 = alloca i8*, align 8
  %3 = alloca i32, align 4
  %4 = alloca %struct.Obj*, align 8
  store i8* %0, i8** %2, align 8
  %5 = load i8*, i8** %2, align 8
  %6 = call i64 @strlen(i8* %5)
  %7 = add i64 %6, 1
  %8 = trunc i64 %7 to i32
  store i32 %8, i32* %3, align 4
  %9 = load i32, i32* %3, align 4
  %10 = sext i32 %9 to i64
  %11 = mul i64 1, %10
  %12 = add i64 40, %11
  %13 = call i8* @malloc(i64 %12) #3
  %14 = bitcast i8* %13 to %struct.Obj*
  store %struct.Obj* %14, %struct.Obj** %4, align 8
  %15 = load %struct.Obj*, %struct.Obj** %4, align 8
  %16 = getelementptr inbounds %struct.Obj, %struct.Obj* %15, i32 0, i32 0
  store i32 4, i32* %16, align 8
  %17 = load i8*, i8** %2, align 8
  %18 = load %struct.Obj*, %struct.Obj** %4, align 8
  %19 = getelementptr inbounds %struct.Obj, %struct.Obj* %18, i32 0, i32 1
  %20 = bitcast %union.values* %19 to i8**
  store i8* %17, i8** %20, align 8
  %21 = load %struct.Obj*, %struct.Obj** %4, align 8
  ret %struct.Obj* %21
}

declare i64 @strlen(i8*) #2

; Function Attrs: noinline nounwind optnone ssp uwtable
define %struct.Obj* @createSymbol(i8*) #0 {
  %2 = alloca i8*, align 8
  %3 = alloca %struct.Obj*, align 8
  store i8* %0, i8** %2, align 8
  %4 = call %struct.Obj* @createObj()
  store %struct.Obj* %4, %struct.Obj** %3, align 8
  %5 = load %struct.Obj*, %struct.Obj** %3, align 8
  %6 = getelementptr inbounds %struct.Obj, %struct.Obj* %5, i32 0, i32 0
  store i32 3, i32* %6, align 8
  %7 = load i8*, i8** %2, align 8
  %8 = load %struct.Obj*, %struct.Obj** %3, align 8
  %9 = getelementptr inbounds %struct.Obj, %struct.Obj* %8, i32 0, i32 1
  %10 = bitcast %union.values* %9 to i8**
  store i8* %7, i8** %10, align 8
  %11 = load %struct.Obj*, %struct.Obj** %3, align 8
  ret %struct.Obj* %11
}

; Function Attrs: noinline nounwind optnone ssp uwtable
define %struct.Obj* @createKeyword(i8*) #0 {
  %2 = alloca i8*, align 8
  %3 = alloca %struct.Obj*, align 8
  store i8* %0, i8** %2, align 8
  %4 = call %struct.Obj* @createObj()
  store %struct.Obj* %4, %struct.Obj** %3, align 8
  %5 = load %struct.Obj*, %struct.Obj** %3, align 8
  %6 = getelementptr inbounds %struct.Obj, %struct.Obj* %5, i32 0, i32 0
  store i32 5, i32* %6, align 8
  %7 = load i8*, i8** %2, align 8
  %8 = load %struct.Obj*, %struct.Obj** %3, align 8
  %9 = getelementptr inbounds %struct.Obj, %struct.Obj* %8, i32 0, i32 1
  %10 = bitcast %union.values* %9 to i8**
  store i8* %7, i8** %10, align 8
  %11 = load %struct.Obj*, %struct.Obj** %3, align 8
  ret %struct.Obj* %11
}

; Function Attrs: noinline nounwind optnone ssp uwtable
define %struct.Obj* @createChar(i8 signext) #0 {
  %2 = alloca i8, align 1
  %3 = alloca %struct.Obj*, align 8
  store i8 %0, i8* %2, align 1
  %4 = call %struct.Obj* @createObj()
  store %struct.Obj* %4, %struct.Obj** %3, align 8
  %5 = load %struct.Obj*, %struct.Obj** %3, align 8
  %6 = getelementptr inbounds %struct.Obj, %struct.Obj* %5, i32 0, i32 0
  store i32 9, i32* %6, align 8
  %7 = load i8, i8* %2, align 1
  %8 = load %struct.Obj*, %struct.Obj** %3, align 8
  %9 = getelementptr inbounds %struct.Obj, %struct.Obj* %8, i32 0, i32 1
  %10 = bitcast %union.values* %9 to i8*
  store i8 %7, i8* %10, align 8
  %11 = load %struct.Obj*, %struct.Obj** %3, align 8
  ret %struct.Obj* %11
}

; Function Attrs: noinline nounwind optnone ssp uwtable
define %struct.Obj* @number(i64) #0 {
  %2 = alloca i64, align 8
  %3 = alloca %struct.Obj*, align 8
  store i64 %0, i64* %2, align 8
  %4 = load i64, i64* %2, align 8
  %5 = call %struct.Obj* @createInteger(i64 %4)
  store %struct.Obj* %5, %struct.Obj** %3, align 8
  %6 = load %struct.Obj*, %struct.Obj** %3, align 8
  ret %struct.Obj* %6
}

; Function Attrs: noinline nounwind optnone ssp uwtable
define %struct.Obj* @boolean(i1 zeroext) #0 {
  %2 = alloca i8, align 1
  %3 = alloca %struct.Obj*, align 8
  %4 = zext i1 %0 to i8
  store i8 %4, i8* %2, align 1
  %5 = load i8, i8* %2, align 1
  %6 = trunc i8 %5 to i1
  %7 = call %struct.Obj* @createBool(i1 zeroext %6)
  store %struct.Obj* %7, %struct.Obj** %3, align 8
  %8 = load %struct.Obj*, %struct.Obj** %3, align 8
  ret %struct.Obj* %8
}

; Function Attrs: noinline nounwind optnone ssp uwtable
define %struct.Obj* @string(i8*) #0 {
  %2 = alloca i8*, align 8
  %3 = alloca %struct.Obj*, align 8
  store i8* %0, i8** %2, align 8
  %4 = load i8*, i8** %2, align 8
  %5 = call %struct.Obj* @createString(i8* %4)
  store %struct.Obj* %5, %struct.Obj** %3, align 8
  %6 = load %struct.Obj*, %struct.Obj** %3, align 8
  ret %struct.Obj* %6
}

; Function Attrs: noinline nounwind optnone ssp uwtable
define %struct.Obj* @fraction(double) #0 {
  %2 = alloca double, align 8
  %3 = alloca %struct.Obj*, align 8
  store double %0, double* %2, align 8
  %4 = load double, double* %2, align 8
  %5 = call %struct.Obj* @createFraction(double %4)
  store %struct.Obj* %5, %struct.Obj** %3, align 8
  %6 = load %struct.Obj*, %struct.Obj** %3, align 8
  ret %struct.Obj* %6
}

; Function Attrs: noinline nounwind optnone ssp uwtable
define %struct.Obj* @nil() #0 {
  %1 = alloca %struct.Obj*, align 8
  %2 = call %struct.Obj* @createNIL()
  store %struct.Obj* %2, %struct.Obj** %1, align 8
  %3 = load %struct.Obj*, %struct.Obj** %1, align 8
  ret %struct.Obj* %3
}

; Function Attrs: noinline nounwind optnone ssp uwtable
define %struct.Obj* @symbol(i8*) #0 {
  %2 = alloca i8*, align 8
  %3 = alloca %struct.Obj*, align 8
  store i8* %0, i8** %2, align 8
  %4 = load i8*, i8** %2, align 8
  %5 = call %struct.Obj* @createSymbol(i8* %4)
  store %struct.Obj* %5, %struct.Obj** %3, align 8
  %6 = load %struct.Obj*, %struct.Obj** %3, align 8
  ret %struct.Obj* %6
}

; Function Attrs: noinline nounwind optnone ssp uwtable
define %struct.Obj* @keyword(i8*) #0 {
  %2 = alloca i8*, align 8
  %3 = alloca %struct.Obj*, align 8
  store i8* %0, i8** %2, align 8
  %4 = load i8*, i8** %2, align 8
  %5 = call %struct.Obj* @createKeyword(i8* %4)
  store %struct.Obj* %5, %struct.Obj** %3, align 8
  %6 = load %struct.Obj*, %struct.Obj** %3, align 8
  ret %struct.Obj* %6
}

; Function Attrs: noinline nounwind optnone ssp uwtable
define %struct.Obj* @character(i8 signext) #0 {
  %2 = alloca i8, align 1
  %3 = alloca %struct.Obj*, align 8
  store i8 %0, i8* %2, align 1
  %4 = load i8, i8* %2, align 1
  %5 = call %struct.Obj* @createChar(i8 signext %4)
  store %struct.Obj* %5, %struct.Obj** %3, align 8
  %6 = load %struct.Obj*, %struct.Obj** %3, align 8
  ret %struct.Obj* %6
}
