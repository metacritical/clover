#include "symbol.h"
#include "var.h"
#include "rt.h"
#include <iostream>
#include "assert.h"
#include <typeinfo>

using namespace std;
using namespace clover::lang;

int main(int argc, char **argv){
  static Symbol CLOVER_MAIN = Symbol::intern("clover.main/main'");
  static Var REQUIRE =  RT::var("clover.core", "require");
  static Var LEGACY_REPL = RT::var("clojure.main", "legacy-repl");
  static Var LEGACY_SCRIPT = RT::var("clojure.main", "legacy-script");
  static Var MAIN = RT::var("clojure.main", "main");
  RT::init();

  // std::cout << REQUIRE << endl;
  // std::cout << CLOVER_MAIN.getName() << endl;
  // std::cout << "Namespace:" << CLOVER_MAIN.getNameSpace() << endl;
  // std::cout << "Combined HashCode: " << CLOVER_MAIN.hasheq() << endl;
  // std::cout << "Symbol HashCode: " << CLOVER_MAIN.hashCode() << endl;
  // std::cout << "Object HashCode: " << Object::hashCode() << endl;
  // std::cout << "toString : " << CLOVER_MAIN.toString() << endl;
  // std::cout << MAIN.toString() << endl;

  assert(REQUIRE.toString() == "#'require/require");
  assert(CLOVER_MAIN.getName() == "main'");
  assert(CLOVER_MAIN.getNameSpace() == "clover.main");
  assert(typeid((int)CLOVER_MAIN.hasheq()) == typeid(int));
  assert(typeid((int)CLOVER_MAIN.hashCode()) == typeid(int));
  assert(typeid((int)Object::hashCode()) == typeid(int));
  assert(CLOVER_MAIN.toString() == "clover.main/main'");
  assert(MAIN.toString() == "#'main/main");
  // throw ArityException(0, "fn_name");
  return 0;
}
