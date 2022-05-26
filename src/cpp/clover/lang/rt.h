#ifndef CLOVER_LANG_RT_H
#define CLOVER_LANG_RT_H

#include <iostream>
#include "object.h"
#include "var.h"

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

    }
  };
}
#endif
