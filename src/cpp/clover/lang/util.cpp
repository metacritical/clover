#include "util.h"

namespace clover::lang {
  using std::string;

  uint32_t Util::hashCode(string str){
    uint32_t h = 0;
    for (int i = 0; i < str.size(); i++) {
      h = (h << 5) | (h >> 27); // 5-bit cyclic shift of the running sum
      h += (int) str[i]; // add in next character
    }
    return h;
  };

  uint32_t Util::stdHashCode(string str){
    return std::hash<std::string>{}(str);
  }

  uint32_t Util::hashCombine(uint32_t h1, uint32_t h2){
    return h1 ^ (h2 << 1);
  }

  uint32_t Util::combinedHashCode(string name, string ns){
    return Util::hashCode(name) ^ (Util::hashCode(ns) << 1);
  }

}
