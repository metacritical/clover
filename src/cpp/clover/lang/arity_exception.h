#ifndef CLOVER_LANG_ARITY_EXCEPTION_H
#define CLOVER_LANG_ARITY_EXCEPTION_H

#include <stdexcept>
#include <exception>
#include <string>

namespace clover::lang {
  using std::string;

  class ArityException : public std::exception{
    int actual;
    char name[30];
    char cause[100];

   public:
    ArityException(int actual, string name){
      this->actual = actual;
      std::strcpy(this->name, name.c_str());
      string _msg = "Wrong number of args (" + std::to_string(actual) + ") passed to: " + name;
      std::strcpy(this->cause, _msg.c_str());
    };

    const char * what () const throw (){
    	return this->cause;
    }
  };
};

#endif
