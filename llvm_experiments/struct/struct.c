#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum { NIL, Integer, Fraction, String, Boolean, Symbol, Character } Type;

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

Vars *createVars(void){
  Vars *this = malloc(sizeof(Vars));
  return this;
}

Vars *createInteger(long int numb) {
    Vars *this = createVars();
    this->type = Integer;
    this->Val.integer = numb;
    return this;
};

Vars *createBool(bool val){
    Vars *this = createVars();
    this->type = Boolean;
    this->Val.boolean = val;
    return this;
}

Vars *createNIL(void){
  Vars *this = createVars();
  this->type = NIL;
  this->Val.nil = NULL;
  return this;
}

Vars *createFraction(double frac) {
    Vars *this = createVars();
    this->type = Fraction;
    this->Val.fraction = frac;
    return this;
};

Vars *createString(char *str){
    Vars *this = createVars();
    this->type = String;
    this->Val.string = str;
    return this;
}

Vars *createSymbol(char *sym){
    Vars *this = createVars();
    this->type = Symbol;
    this->Val.symbol = sym;
    return this;
}

Vars *number(long int n){
  Vars *numb = createInteger(n);
  return numb;
}

Vars *boolean(bool b){
  Vars *flag = createBool(b);
  return flag; 
}

Vars *string(char *c){
  Vars *str = createString(c);
  return str;
}

Vars *fraction(double d){
  Vars *fractn = createFraction(d);
  return fractn;
}

//Number 
/* Vars *clj_val(){ */
  /* return number(42); */
/* } */

//Boolean
/* Vars *clj_val(){ */
  /* return boolean(true); */
/* } */

//String
/* Vars *clj_val(){ */
  /* return string("Hello World is not enough"); */
/* } */

//Fraction
/* Vars *clj_val(){ */
  /* return fraction(7687713263); */
/* } */

