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


    Object invoke();
    Object invoke(Object arg1);
    Object invoke(Object arg1, Object arg2);
    Object invoke(Object arg1, Object arg2, Object arg3);
    Object invoke(Object arg1, Object arg2, Object arg3, Object arg4);
    Object invoke(Object arg1, Object arg2, Object arg3, Object arg4, Object arg5);
    Object invoke(Object arg1, Object arg2, Object arg3, Object arg4, Object arg5, Object arg6);
    Object invoke(Object arg1, Object arg2, Object arg3, Object arg4, Object arg5, Object arg6, Object arg7);
    Object invoke(Object arg1, Object arg2, Object arg3, Object arg4, Object arg5, Object arg6, Object arg7,
                  Object arg8);
    Object invoke(Object arg1, Object arg2, Object arg3, Object arg4, Object arg5, Object arg6, Object arg7,
                  Object arg8, Object arg9);
    Object invoke(Object arg1, Object arg2, Object arg3, Object arg4, Object arg5, Object arg6, Object arg7,
                  Object arg8, Object arg9, Object arg10);
    Object invoke(Object arg1, Object arg2, Object arg3, Object arg4, Object arg5, Object arg6, Object arg7,
                  Object arg8, Object arg9, Object arg10, Object arg11);
    Object invoke(Object arg1, Object arg2, Object arg3, Object arg4, Object arg5, Object arg6, Object arg7,
                  Object arg8, Object arg9, Object arg10, Object arg11, Object arg12);
    Object invoke(Object arg1, Object arg2, Object arg3, Object arg4, Object arg5, Object arg6, Object arg7,
                  Object arg8, Object arg9, Object arg10, Object arg11, Object arg12, Object arg13);
    Object invoke(Object arg1, Object arg2, Object arg3, Object arg4, Object arg5, Object arg6, Object arg7,
                  Object arg8, Object arg9, Object arg10, Object arg11, Object arg12, Object arg13, Object arg14);
    Object invoke(Object arg1, Object arg2, Object arg3, Object arg4, Object arg5, Object arg6, Object arg7,
                  Object arg8, Object arg9, Object arg10, Object arg11, Object arg12, Object arg13, Object arg14,
                  Object arg15);
    Object invoke(Object arg1, Object arg2, Object arg3, Object arg4, Object arg5, Object arg6, Object arg7,
                  Object arg8, Object arg9, Object arg10, Object arg11, Object arg12, Object arg13, Object arg14,
                  Object arg15, Object arg16);
    Object invoke(Object arg1, Object arg2, Object arg3, Object arg4, Object arg5, Object arg6, Object arg7,
                  Object arg8, Object arg9, Object arg10, Object arg11, Object arg12, Object arg13, Object arg14,
                  Object arg15, Object arg16, Object arg17);
    Object invoke(Object arg1, Object arg2, Object arg3, Object arg4, Object arg5, Object arg6, Object arg7,
                  Object arg8, Object arg9, Object arg10, Object arg11, Object arg12, Object arg13, Object arg14,
                  Object arg15, Object arg16, Object arg17, Object arg18);
    Object invoke(Object arg1, Object arg2, Object arg3, Object arg4, Object arg5, Object arg6, Object arg7,
                  Object arg8, Object arg9, Object arg10, Object arg11, Object arg12, Object arg13, Object arg14,
                  Object arg15, Object arg16, Object arg17, Object arg18, Object arg19);
    Object invoke(Object arg1, Object arg2, Object arg3, Object arg4, Object arg5, Object arg6, Object arg7,
                  Object arg8, Object arg9, Object arg10, Object arg11, Object arg12, Object arg13, Object arg14,
                  Object arg15, Object arg16, Object arg17, Object arg18, Object arg19, Object arg20);
    Object invoke(Object arg1, Object arg2, Object arg3, Object arg4, Object arg5, Object arg6, Object arg7,
                  Object arg8, Object arg9, Object arg10, Object arg11, Object arg12, Object arg13, Object arg14,
                  Object arg15, Object arg16, Object arg17, Object arg18, Object arg19, Object arg20,
                  Object args);
  };
}

#endif
