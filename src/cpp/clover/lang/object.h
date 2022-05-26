#ifndef CLOVER_LANG_OBJECT_H
#define CLOVER_LANG_OBJECT_H

#include <iostream>
#include <map>

namespace clover::lang{
  using std::string;
  using std::map;

  class Object{
    uint32_t _hasheq;
    string _str;
    map<string , string> _meta;

    public:

    static uint32_t hashCode();
  };
}

#endif
