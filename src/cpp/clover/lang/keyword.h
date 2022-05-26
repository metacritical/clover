#ifndef CLOVER_LANG_KEYWORD_H
#define CLOVER_LANG_KEYWORD_H

#include "symbol.h"

namespace clover::lang{
  using std::string;

  class Keyword : Object {
    public:
    Symbol sym;
    int hasheq;
    string _str;

    Keyword(Symbol sym) : sym(sym) {
      this->sym = sym;
      this->hasheq = sym.hasheq() + 0x9e3779b9;
    }
  };
}

#endif
