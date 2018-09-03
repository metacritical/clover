#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Struct if type val stores infomation about the data
//clj_val returns the value and dispatches data accordingly.
typedef enum { NIL, Integer, Fraction, String, Boolean, Symbol, Cons } Type;

typedef struct Vars {
  Type type;
  union {
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

Vars *createNIL(void){
  Vars *this = createVars();
  this->type = NIL;
  this->Val.nil = NULL;
  return this;
}

Vars *createInteger(long int numb) {
    Vars *this = createVars();
    this->type = Integer;
    this->Val.integer = numb;
    return this;
};

Vars *createFraction(double frac) {
    Vars *this = createVars();
    this->type = Fraction;
    this->Val.fraction = frac;
    return this;
};

Vars *boolBool(bool val){
    Vars *this = createVars();
    this->type = Boolean;
    this->Val.boolean = val;
    return this;
}

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


//Val clj_val();

int main(int argc, char** argv){
  printf("%d\n", clj_val());
  return 0;
}
