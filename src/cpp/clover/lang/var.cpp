#include "object.h"
#include "var.h"
#include "namespace.h"

namespace clover::lang{

  bool Var::dynamic = false;
  int Var::rev = 0;

  Var::Var(Namespace ns, Symbol sym) : ns(ns), sym(sym){
    this->ns = ns;
    this->sym = sym;
  }

  Var Var::intern(Namespace ns, Symbol sym){
    return ns.intern(sym);
  }

  Var Var::intern(Symbol nsName, Symbol sym){
    Namespace ns = Namespace::findOrCreate(nsName);
    return intern(ns, sym);
  }

  Var Var::intern(Namespace ns, Symbol sym, Object root){
    return intern(ns, sym, root, true);
  }

  Var Var::intern(Namespace ns, Symbol sym, Object root, bool replaceRoot){
    Var dvout = ns.intern(sym);
    if(!dvout.hasRoot() || replaceRoot){
      dvout.bindRoot(root);
    }
    return dvout;
  }

  Var Var::setDynamic(){
    this->dynamic = true;
    return *this;
  }

  Var Var::setDynamic(bool b){
    this->dynamic = b;
    return *this;
  }

}
