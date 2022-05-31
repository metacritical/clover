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
    return Var::intern(Symbol::intern(ns), Symbol::intern(name));
  }

  Var RT::var(string ns, string name, Object init){
    Namespace ns_found = Namespace::findOrCreate(Symbol::intern(NULL, ns));
    return Var::intern(ns_found, Symbol::intern(NULL, name), init);
  }

  void RT::init() {
    doInit();
  }
}
