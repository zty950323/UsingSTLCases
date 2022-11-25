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
 * @link https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/memcmp-wmemcmp?view=msvc-170
 * @file main.cpp
 * @author Tom Zhao(18872770445@163.com)
 * @since 2022-09-16
 * @date Created: 2022-09-16
 * @date Last modified: 2022-09-16
 *
 * Github: @link https://github.com/zty950323/UsingSTLCases.git @endlink
 * Gitee: @link https://gitee.com/zhaotianyuCoding/using-stlex.git @endlink
 * Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
 * Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
 */

#include <iostream>

using namespace std;

typedef char ZCHAR;
typedef wchar_t ZWCHAR;
typedef unsigned char ZUCHAR;

void logInfo(const ZCHAR* fm)
{
    if (fm)
    {
        auto fmSize = sizeof(fm);
        if (fmSize)
        {
            cout << fmSize << '\t' << *fm << endl;
        }
    }
}

int main()
{
    ZCHAR testChar = '0';
    return 0;
}