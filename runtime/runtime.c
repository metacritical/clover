#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum { NIL, Integer, Fraction,
	       String, Boolean, Symbol,
	       Character, PersistentList,
	       Function, Keyword } Type;

typedef struct Obj {
  Type type;
  union values {
    long int integer;
    double fraction;
    bool boolean;
    const char *string;
    const char *symbol;
    const char *keyword;
    char character;
    int *nil;
  } Val;
} Obj;

Obj *clj_val();

static void print_clj(Obj *obj){
  //Integer
  if(obj->type == Integer){
    printf("%ld\n", obj->Val.integer);
  }else 
    //Fraction
    if(obj->type == Fraction){
      printf("%lf\n", obj->Val.fraction); 
      //Boolean
    }else if(obj->type == Boolean){
      if(obj->Val.boolean == 1){
	printf("true\n");
      }else{
	printf("false\n");
      }
      //String
    }else if(obj->type == String){
      printf("\"%s\"\n", obj->Val.string);
      //Nil
    }else if(obj->type == NIL){
      printf("nil\n");
      //Symbol
    }else if(obj->type == Symbol){
      printf("%s => Symbol\n", obj->Val.symbol);
      //Keyword
    }else if(obj->type == Keyword){
      printf("%s\n", obj->Val.keyword);
      //Character
    }else if(obj->type == Character){
      printf("\\%c\n", obj->Val.character);
      //Unknown
    }else {
      puts("Unknown Type.");
    }
}

int main(int argc, char** argv){
  print_clj(clj_val());
  return 0;
}
