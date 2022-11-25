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
 * @brief This is a file for learning C++ template definitions in a .cpp file
 * (instead of a header file)
 * @link
 * https://raymii.org/s/snippets/Cpp_template_definitions_in_a_cpp_file_instead_of_header.html
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

#include "template_case_one.h"

#include <iostream>

using std::cout;

// Actual template definiton
template <typename T1, typename T2>
void TestClass::templateFunction(T1 var1, T2 var2) {
  cout << "var1: " << var1 << ", ";
  cout << "var2: " << var2 << ", ";
  cout << "m_bool1: " << m_bool1 << "\n";
}

// Here is the explicit instanciation
template void TestClass::templateFunction<int, int>(int, int);
template void TestClass::templateFunction<char const*, char const*>(
    char const*, char const*);
