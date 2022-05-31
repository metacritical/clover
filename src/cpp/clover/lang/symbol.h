#ifndef CLOVER_LANG_SYMBOL_H
#define CLOVER_LANG_SYMBOL_H

#include <iostream>
#include <string>
#include <map>
#include "object.h"
#include "arity_exception.h"
#include "util.h"

namespace clover::lang{
  using std::string;
  using std::map;

  class Symbol : public Object {
    string ns;
    string name;
    uint32_t _hasheq;
    string _str;
    map<string , string> _meta;

  public:
    string getName() const;
    string getNameSpace() const;
    static Symbol intern(string nsname);
    static Symbol intern(string ns, string nsname);
    static Symbol intern(std::nullptr_t ns, string nsname);
    uint32_t hasheq();
    string toString();

    bool operator<(Symbol& sym){
      //if (this->getName() == sym.getName() && this->getNameSpace() == sym.getNameSpace()) return true;
      //else return false;
      return getName() < sym.getName() && getNameSpace() < sym.getNameSpace();
    }

    bool operator==(const Symbol& sym) const{
      //if (this->getName() == sym.getName() && this->getNameSpace() == sym.getNameSpace()) return true;
      //else return false;
      return getName() == sym.getName() && getNameSpace() == sym.getNameSpace();
    }

    friend std::ostream& operator<<(std::ostream& os, Symbol& s){
      return os << s.name;
    };

    struct SymHash{
      size_t operator()(const Symbol& sym) const{
        size_t h1 = std::hash<std::string>()(sym.getName());
        size_t h2 = std::hash<std::string>()(sym.getNameSpace());
        // std::cout << "Carroted " << (h1 ^ h2) << std::endl;
        // std::cout << "Combined " <<  Util::combinedHashCode(std::to_string(h1), std::to_string(h2)) << std::endl;
        return Util::combinedHashCode(std::to_string(h1), std::to_string(h2));
      }
    };

    Symbol(string ns){
      this->ns = ns;
      this->_meta.clear();
    }

    Symbol(int ns, string nsname){
      this->ns = ns;
      this->name = nsname;
      this->_meta.clear();
    }

    Symbol(string ns, string nsname){
      this->ns = ns;
      this->name = nsname;
      this->_meta.clear();
    }

    Symbol(std::map<string, string> meta, string ns, string nsname){
      this->ns = ns;
      this->name = nsname;
      this->_meta = meta;
    };
  };
}

#endif
