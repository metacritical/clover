@a = weak constant i32 42
define i32 @main(){
  %x = load i32, i32* @a, align 4
  ret i32 %x
}
