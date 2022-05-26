#include "symbol.h"
#include "var.h"
#include "rt.h"
#include <iostream>

using namespace std;
using namespace clover::lang;

int main(int argc, char **argv){
  static Symbol CLOVER_MAIN = Symbol::intern("clover.core/-main");
  static Var REQUIRE =  RT::var("clover.core", "require");
  static Var LEGACY_REPL = RT::var("clojure.main", "legacy-repl");
  static Var LEGACY_SCRIPT = RT::var("clojure.main", "legacy-script");
  static Var MAIN = RT::var("clojure.main", "main");    RT::init();
  std::cout << REQUIRE << endl;
  std::cout << CLOVER_MAIN.getName() << endl;
  std::cout << "Namespace:" << CLOVER_MAIN.getNameSpace() << endl;
  std::cout << "Combined HashCode: " << CLOVER_MAIN.hasheq() << endl;
  std::cout << "toString : " << CLOVER_MAIN.toString() << endl;
  std::cout << "HashCode: " << Object::hashCode() << endl;
  // throw ArityException(0, "fn_name");
  return 0;
}