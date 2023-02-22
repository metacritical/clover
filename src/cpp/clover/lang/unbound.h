#include <iostream>
#include <set>
#include "symbol.h"
#include "afn.h"
#include "var.h"

#ifndef CLOVER_LANG_UNBOUND_H
#define CLOVER_LANG_UNBOUND_H

namespace clover::lang {
  using namespace std;

  Var *var();
  
  class Unbound : public AFn {

  public:
    Unbound();

    void setVar(Var *var){
      Var *_this;
      _this = var;
    }

    string toString();

    Object throwArity(int n);
  };
};

#endif
