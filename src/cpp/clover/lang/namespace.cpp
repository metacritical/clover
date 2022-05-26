#include "symbol.h"
#include "namespace.h"
#include "var.h"
#include "util.h"

namespace clover::lang{
  string Namespace::toString(){
    return name.toString();
  }

  Namespace Namespace::findOrCreate(Symbol name){
    ns_found = namespaces.find(name);
    if(ns_found == namespaces.end()){
      namespaces.insert(std::pair<Symbol, Namespace>(name, Namespace(name)));
      return namespaces.find(name)->second;
    }else{
      return ns_found->second;
    }
  }

  Var Namespace::intern(Symbol sym){
    return Var(sym, sym);
  }

  Symbol Namespace::getName(){
    return name;
  }
}
