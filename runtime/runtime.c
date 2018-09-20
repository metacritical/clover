#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <glib.h>

typedef enum {
      NIL,
      ENV,
      List,
      Symbol,
      String,
      Keyword,
      Boolean,
      Integer,
      Fraction,
      Character,
      EmptyList,
      Function,
} Type;

typedef struct Env { struct Env *up; GHashTable *vars; } Env;

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

    //Function attributes and code.
    struct {
      struct Obj (*ptr)(void *root, Env *env, struct Obj *args);
      struct Obj *params;
      struct Obj *body;
      int arity;
    } fn;

    //Cons cell
    struct {
      struct Obj *first;
      struct Obj *rest;
    };

    //Environment for the datatype.
    Env *env;

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
      printf("Unknown Type #< %d >\n", obj->type);
    }
}

int main(int argc, char** argv){
  print_clj(clj_val());
  return 0;
}
