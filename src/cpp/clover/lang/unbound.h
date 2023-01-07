
#ifndef CLOVER_LANG_UNBOUND_H
#define CLOVER_LANG_UNBOUND_H

#include <iostream>
#include <set>
#include "symbol.h"
#include "afn.h"
#include "var.h"

namespace clover::lang {
  using namespace std;

  class Unbound : public AFn {
    Var var;

  public:
    Unbound();

    void setVar(Var var) : var(var){
      this->var = var;
    }

    string toString();

    Object throwArity(int n);
  };
};

#endif
