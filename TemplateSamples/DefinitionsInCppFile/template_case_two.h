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
 * @since 2022-06-02
 * @date Created: 2022-06-02
 * @date Last modified: 2022-06-02
 *
 * Github: @link https://github.com/zty950323/UsingSTLCases.git @endlink
 * Gitee: @link https://gitee.com/zhaotianyuCoding/using-stlex.git @endlink
 * Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
 * Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
 */

#ifndef TEST_CLASS_TWO_H
#define TEST_CLASS_TWO_H

#include "template_case_one.h"

class TestClass2 {
 private:
  bool m_abc1{false};

 public:
  void printTest();
};

#endif  // TEST_CLASS_TWO_H
