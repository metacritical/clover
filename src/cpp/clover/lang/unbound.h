#ifndef CLOVER_LANG_UNBOUND_H
#define CLOVER_LANG_UNBOUND_H

#include <iostream>
#include <set>
#include "symbol.h"
#include "var.h"

namespace clover::lang {
  using namespace std;

  class Unbound : public Object {
  public:
   //std::set<Var, VarComparator> UNBOUND_VAR;
   Var UNBOUND_VAR[0];

    Unbound(Var v){
      UNBOUND_VAR[0] = v;
    }

    std::string toString(){
      return "Unbound (this->UNBOUND_VAR[0]).toString()";
    }

    Object throwArity(int n){
      throw std::runtime_error("Attempting to call unbound fn: this->UNBOUND_VAR");
    }
  };
};



#endif
