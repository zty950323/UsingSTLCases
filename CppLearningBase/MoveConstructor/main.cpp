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
 * @brief This is a file for learning Micosoft's Templates (C++)
 * @link https://docs.microsoft.com/zh-cn/cpp/cpp/move-constructors-and-move-assignment-operators-cpp @endlink
 * @file main.cpp
 * @author Tom Zhao(18872770445@163.com)
 * @since 2022-07-04
 * @date Created: 2022-07-04
 * @date Last modified: 2022-07-04
 *
 * Github: @link https://github.com/zty950323/UsingSTLCases.git @endlink
 * Gitee: @link https://gitee.com/zhaotianyuCoding/using-stlex.git @endlink
 * Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
 * Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
 */

#include "MemoryBlock.h"
#include <vector>

using namespace std;

namespace TzSoft
{
  void TestMemoryBlockCase()
  {
    vector<MemoryBlock> v;
    // Create a vector object and add a few elements to it.
    v.push_back(MemoryBlock(10));
    v.push_back(MemoryBlock(20));
    v.push_back(MemoryBlock(30));
    v.push_back(MemoryBlock(25));
    v.push_back(MemoryBlock(15));
    v.push_back(MemoryBlock(5));

    // Insert a new element into the second position of the vector.
    v.insert(v.begin() + 1, MemoryBlock(50));
  }
} // namespace TzSoft

int main() {
  TzSoft::TestMemoryBlockCase();
  return 0;
}