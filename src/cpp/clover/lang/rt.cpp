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
    return Var::intern(Namespace::findOrCreate(Symbol::intern(NULL, ns)), Symbol::intern(NULL, name), init);
  }

  void RT::init() {
    doInit();
  }
}
