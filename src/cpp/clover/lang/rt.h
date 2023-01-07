#ifndef CLOVER_LANG_RT_H
#define CLOVER_LANG_RT_H

#include <iostream>
#include "object.h"
#include "var.h"
#include <exception>

namespace clover::lang{
  using namespace std;

  class RT : public Object{
  public:
    static bool INIT;

    static Var var(string ns, string name);
    static Var var(string ns, string name, Object init);
    static void init();

    private:

    static void doInit(){
      if(INIT) return; else INIT=true;

      try{
        Symbol USER = Symbol::intern("user");
        Symbol CLOJURE = Symbol::intern("clojure.core");
        Var in_ns = var("clojure.core", "in-ns");
        Var refer = var("clojure.core", "refer");
        // in_ns.invoke(USER);
        //
      }catch(std::exception e){
        throw std::exception(e);
      }
    }
  };
};
#endif
