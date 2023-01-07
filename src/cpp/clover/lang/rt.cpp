#include "object.h"
#include "rt.h"
#include "var.h"
#include "symbol.h"
#include "namespace.h"
#include <iostream>

namespace clover::lang{
  using namespace std;

  bool RT::INIT = false;
  
  Var RT::var(string ns, string name){
    Symbol ns_sym = Symbol::intern(NULL, ns);
    Symbol ref_sym = Symbol::intern(NULL, name);
    return Var::intern(Namespace::findOrCreate(ns_sym), ref_sym);
  }

  Var RT::var(string ns, string name, Object init){
    Namespace ns_found = Namespace::findOrCreate(Symbol::intern(NULL, ns));
    return Var::intern(ns_found, Symbol::intern(NULL, name), init);
  }

  void RT::init() {
    doInit();
  }
}
