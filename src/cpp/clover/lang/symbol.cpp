#include "symbol.h"
#include "util.h"
#include <cstdbool>

namespace clover::lang {
	using namespace std;


  string Symbol::toString(){
    if(_str.empty()){
      if(!ns.empty() && ns.length() > 1){
        _str = (ns + "/" + name);
      }else
        _str = name;
    }
    return _str;
  }

  string Symbol::getName() const{
    return this->name;
  }

  string Symbol::getNameSpace() const{
    return this->ns;
  }

  Symbol Symbol::intern(std::nullptr_t ns, string name){
    return Symbol(0, name);
  }

  Symbol Symbol::intern(string ns, string name){
    return Symbol(ns, name);
  }

  Symbol Symbol::intern(string name){
    int i = name.find('/');
    if(i >= 1)
      return Symbol(name.substr(0, i), name.substr(i + 1));
    else
      return Symbol(0, name);
  }

  uint32_t Symbol::hasheq(){
    if(_hasheq == 0){
      //TODO: Use the Murmur3.for hashcode.
      _hasheq = Util::combinedHashCode(name, ns);
    }
    return _hasheq;
  }
}
