; Function Attrs: noinline nounwind optnone ssp uwtable
define zeroext i1 @clj_val() #0 {
  %1 = alloca %struct.Vars*, align 8
  %2 = call %struct.Vars* @boolean(i1 zeroext true)
  store %struct.Vars* %2, %struct.Vars** %1, align 8
  %3 = load %struct.Vars*, %struct.Vars** %1, align 8
  %4 = getelementptr inbounds %struct.Vars, %struct.Vars* %3, i32 0, i32 1
  %5 = bitcast %union.values* %4 to i8*
  %6 = load i8, i8* %5, align 8
  %7 = trunc i8 %6 to i1
  ret i1 %7
}
