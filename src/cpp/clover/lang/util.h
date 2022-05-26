#include <string>
#include "symbol.h"


#ifndef CLOVER_LANG_UTIL_H
#define CLOVER_LANG_UTIL_H

namespace clover::lang {
  using std::string;

  class Util{
    public:
    uint32_t static hashCode(string s);
    uint32_t static stdHashCode(string s);
    uint32_t static hashCombine(uint32_t h1, uint32_t h2);
    uint32_t static combinedHashCode(string str1, string str2);
  };
}

#endif
