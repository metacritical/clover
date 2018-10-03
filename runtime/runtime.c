#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <glib.h>
#include "runtime.h"

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
  GHashTable* namespaces = g_hash_table_new(g_str_hash, g_str_equal);
  GHashTable* core_ns = g_hash_table_new(g_str_hash, g_str_equal);
  g_hash_table_insert(core_ns, "*ns*", "clojure.core");
  g_hash_table_insert(namespaces, "clojure.core", core_ns);

  print_clj(clj_val(core_ns));
  return 0;
}
