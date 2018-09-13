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
      int param_count;
    } fn;

    //Cons cell
    struct {
      Obj *first;
      Obj *rest;
    }

    //Environment for the datatype.
    Env *env;

  } Val;
} Obj;

Obj *createObj(void){
  Obj *this = malloc(sizeof(Obj));
  return this;
}

Obj *createInteger(long int numb) {
  Obj *this = createObj();
  this->type = Integer;
  this->Val.integer = numb;
  return this;
}

Obj *createBool(bool val){
  Obj *this = createObj();
  this->type = Boolean;
  this->Val.boolean = val;
  return this;
}

Obj *createNIL(void){
  Obj *this = createObj();
  this->type = NIL;
  this->Val.nil = NULL;
  return this;
}

Obj *createFraction(double frac) {
  Obj *this = createObj();
  this->type = Fraction;
  this->Val.fraction = frac;
  return this;
}

Obj *createString(char *str){
  int len = strlen(str) + 1;
  Obj *this = malloc(sizeof(Obj) + sizeof(char)*len);
  this->type = String;
  this->Val.string = str;
  return this;
}

Obj *createSymbol(char *sym){
  Obj *this = createObj();
  this->type = Symbol;
  this->Val.symbol = sym;
  return this;
}

Obj *createKeyword(char* key){
  Obj *this = createObj();
  this->type = Keyword;
  this->Val.keyword = key;
  return this;
}

Obj *createChar(char c){
  Obj *this = createObj();
  this->type = Character;
  this->Val.character = c;
  return this;
}

Obj *cons(char *first){
  Obj *this = createObj();
  this->type = List;
  this->Val.first = *first;
  this->Val.last = *rest;
  return this;
}

Obj *createUnaryFunction(){
  Obj *this = createObj();
  return this;
}

Obj *number(long int n){
  Obj *numb = createInteger(n);
  return numb;
}

Obj *boolean(bool b){
  Obj *flag = createBool(b);
  return flag; 
}

Obj *string(char *c){
  Obj *str = createString(c);
  return str;
}

Obj *fraction(double d){
  Obj *fractn = createFraction(d);
  return fractn;
}

Obj *nil(void){
  Obj *null = createNIL();
  return null;
}

Obj *symbol(char *s){
  Obj *sym = createSymbol(s);
  return sym;
}

Obj *keyword(char *k){
  Obj *key = createKeyword(k);
  return key;
}

Obj *character(char c){
  Obj *chr = createChar(c);
  return chr;
}

//Number 
/* Obj *clj_val(){ */
  /* return number(42); */
/* } */

//Boolean
/* Obj *clj_val(){ */
  /* return boolean(true); */
/* } */

//String
/* Obj *clj_val(){ */
  /* return string("Hello World is not enough"); */
/* } */

//Fraction
/* Obj *clj_val(){ */
  /* return fraction(7687713263); */
/* } */

//Nil
/* Obj *clj_val(){ */
  /* return nil(); */
/* } */

//Symbol
/* Obj *clj_val(){ */
  /* return symbol("awed"); */
/* } */

//Keyword
/* Obj *clj_val(){ */
  /* return keyword(":keyword"); */
/* } */

//Character
/* Obj *clj_val(){ */
  /* return character('a'); */
/* } */




