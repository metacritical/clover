#include "object.h"
#include "util.h"
#include <string>

namespace clover::lang {
  uint32_t Object::hashCode(){
    Object obj;
    static intptr_t objAddr = intptr_t(&obj);
    string str = std::to_string(objAddr);
    return Util::hashCode(str);
  }
}
