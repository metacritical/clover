#ifndef CLOVER_LANG_VAR_H
#define CLOVER_LANG_VAR_H

#include <iostream>
#include <map>
#include "symbol.h"
#include "namespace.h"
#include "util.h"

namespace clover::lang {
  template<typename Base, typename T> inline bool instanceof(const T *ptr) {
    return dynamic_cast<const Base*>(ptr) != nullptr;
  }

  class Var : public Object{
    Namespace ns;
    Symbol sym;
    Object root;

  public:
    static int rev;
    static Var intern(Namespace ns, Symbol sym);
    static Var intern(Symbol nsName, Symbol sym);
    static Var intern(Namespace ns, Symbol sym, Object root);
    static Var intern(Namespace ns, Symbol sym, Object root, bool replaceRoot);
    static bool dynamic;

    Var(Namespace ns, Symbol sym);

    Var(Namespace ns, Symbol sym, Object root) : ns(ns), sym(sym), root(root) {
      this->intern(ns, sym);
      this->root = root;
      rev > 0 ? ++rev : rev = 0;
    };


    Var setDynamic();
    Var setDynamic(bool b);

    bool hasRoot(){
      return !(instanceof<Object>(&(this->root)));
    }

    //TODO: Implement synchronized in C++ for bindRoot function.
    void bindRoot(Object root){
      //validate(getValidator(), root);
      Object oldroot = this->root;
      this->root = root;
      ++Var::rev;
      //alterMeta(dissoc, RT.list(macroKey));
      //notifyWatches(oldroot,this.root);
    }

    friend std::ostream& operator<<(std::ostream& os, Var& v){
      if(v.ns.getName().toString().empty())
        return os << "#<Var: " + (!v.sym.getName().empty() ? v.sym.getName() : "--unnamed--") + ">";
      return os << "#'" + v.ns.getName().toString() + "/" + v.sym.getName();
    };
  };

  struct VarComparator{
    bool operator()(const Var &left, const Var &right) const{
      return (left.hashCode() > right.hashCode());
    }
  };
};


#include "unbound.h"

#endif
