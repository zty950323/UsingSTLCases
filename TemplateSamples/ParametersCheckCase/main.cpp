/**
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 1. You can modify and use this program at will.
 * 2. But it is suggested that it is more suitable for learning and teaching
 * purposes.
 *
 * @version 1.0
 * @brief This is a file for learning Template Parameters Checking.
 * @link https://dawnarc.com/2019/12/c-template-parameters-checking/ @endlink
 * @link
 * https://stackoverflow.com/questions/257288/is-it-possible-to-write-a-template-to-check-for-a-functions-existence
 * @endlink
 * @link
 * https://stackoverflow.com/questions/13636540/how-to-check-for-the-type-of-a-template-parameter
 * @endlink
 * @file main.cpp
 * @author Tom Zhao(18872770445@163.com)
 * @since 2022-05-24
 * @date Created: 2022-05-24
 * @date Last modified: 2022-05-24
 *
 * Github: @link https://github.com/zty950323/UsingSTLCases.git @endlink
 * Gitee: @link https://gitee.com/zhaotianyuCoding/using-stlex.git @endlink
 * Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
 * Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
 */

#include <iostream>
#include <string>
#include <type_traits>

using std::cout;
using std::declval;
using std::endl;
using std::string;

class TestToStringBase {
 public:
  string toString() const {
    return string("This is a Test class for toString template.");
  }
};

class TestToStringChild : public TestToStringBase {
 public:
  string toString_child() const {
    return string("This is a Test class for toString template.");
  }
};

class NomalClass {
 public:
  int printNumber() const {
    cout << 100 << endl;
    return 100;
  }
  string toString() const {
    return string("This is a Test class for toString template.");
  }
};

#ifdef _HAS_CXX17
#if 0
// In Pre-C++20 we can use detection toolkit:
template <typename T>
using toString_t = decltype(declVal<T&>().toString());
template <typename T>
constexpr bool has_toString_out =
    std::experimental::is_detected<toString_t, T>::value;
#endif
#endif

class UsingTempalteCheckCase {
 public:
#ifdef _HAS_CXX20
  // In c++ 20 we can use requires expressions:
  template <class T>
  static string optionalToString(T* pObj) {
    constexpr bool has_toString = requires(const T& t) { t.toString(); };
    if constexpr (has_toString) {
      return pObj->toString();
    }
    else {
      return "toString not defined";
    }
  }
#endif
#ifdef _HAS_CXX17
#if 0
  template <class T>
  static string optionalToString_17(T* pObj) {
    if constexpr (has_toString_out) {
      return pObj->toString();
    } else {
      return "toString not defined";
    }
  }
#endif
#endif

  // Before C++17 we can use is_same:
  template <class T>
  static string optionalToString_nomal(T* pObj) {
    if (std::is_same_v<T*, TestToStringBase*>) {
      return pObj->toString();
    } else {
      return "toString not defined";
    }
  }
};

void usingTemplateCheckCase() {
  TestToStringChild tObj;
  NomalClass nObj;
  cout << UsingTempalteCheckCase::optionalToString<TestToStringBase>(&tObj)
       << '\t'
       << UsingTempalteCheckCase::optionalToString_nomal<TestToStringBase>(
              &tObj)
       << endl;
  cout << UsingTempalteCheckCase::optionalToString<NomalClass>(&nObj) << '\t'
       << UsingTempalteCheckCase::optionalToString_nomal<NomalClass>(&nObj)
       << endl;
}

int main() {
  usingTemplateCheckCase();
  return 0;
}
