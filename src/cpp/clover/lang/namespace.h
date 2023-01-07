#ifndef CLOVER_LANG_NAMESPACE_H
#define CLOVER_LANG_NAMESPACE_H

#include <iostream>
#include "symbol.h"
#include <unordered_map>

namespace clover::lang{
  using namespace std;

  class Var;

  class Namespace : public Object {
    Symbol name;
  public:
    Symbol getName();
    string toString();
    static  Namespace findOrCreate(Symbol name);
    static inline std::unordered_map<Symbol, Namespace, Symbol::SymHash> namespaces;
    static inline std::unordered_map<Symbol, Namespace, Symbol::SymHash>::const_iterator ns_found;

    Var intern(Symbol sym);
    Namespace();
    Namespace(Symbol n) : name(n){
      this->name = n;
    };

    friend std::ostream& operator<<(ostream& output, Namespace& ns){
      return output << ns.toString();
    };

    bool operator==(Namespace& ns){
      return name.getName() == ns.name.getName() && name.getNameSpace() == ns.name.getNameSpace();
    }
  };
}

#endif
