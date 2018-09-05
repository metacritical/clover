#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum { NIL, Integer, Fraction, String, Boolean, Symbol } Type;

typedef struct Vars {
  Type type;
  union values {
    long int integer;
    double fraction;
    bool boolean;
    char *string;
    char *symbol;
    int *nil;
  } Val;
} Vars;

Vars *clj_val();

static void print_clj(Vars *obj){
  if(obj->type == Integer){
    printf("%ld\n", obj->Val.integer);
  }else if(obj->type == Fraction){
   printf("%lf\n", obj->Val.fraction); 
  }else if(obj->type == Boolean){
    if(obj->Val.boolean == 1){
      printf("true\n");
    }else{
      printf("false\n");
    }
  }else if(obj->type == String){
    printf("%s\n", obj->Val.string);
  }else{
    printf("Unknown Type.\n");
  }
}

int main(int argc, char** argv){
  print_clj(clj_val());
  return 0;
}
