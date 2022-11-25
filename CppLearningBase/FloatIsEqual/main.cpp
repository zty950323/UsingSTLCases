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
 * @since 2022-09-07
 * @date Created: 2022-09-07
 * @date Last modified: 2022-09-07
 *
 * Github: @link https://github.com/zty950323/UsingSTLCases.git @endlink
 * Gitee: @link https://gitee.com/zhaotianyuCoding/using-stlex.git @endlink
 * Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
 * Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
 */

#include <iostream>
#include <iomanip>

using namespace std;

struct Vector2d
{
    double x;
    double y;
};

struct Vector3d
{
    double x;
    double y;
    double z;
};

bool operator==(const Vector2d& src, const Vector2d& other)
{
    return memcmp(&src, &other, sizeof(Vector2d)) == 0;
}

bool operator==(const Vector3d& src, const Vector3d& other) {
    return memcmp(&src, &other, sizeof(Vector3d)) == 0;
}

int main()
{
    double testNum = 192.00000233232222222222222223232424243231312412412341231;
    double copyNum = testNum;
    if (copyNum == testNum) {
        cout << setiosflags(ios::scientific|ios::showpos|ios::showpoint) << copyNum << '\t' << testNum << endl;
    }
    double mul = 1.0000000000000000000000000000000000000000000000000000000000000000000000000000000000001;
    double mulTestNum = testNum * mul;
    auto outFlags = setiosflags(ios::scientific | ios::showpos | ios::showpoint);
    if (mulTestNum == testNum) {
        cout << outFlags << mulTestNum << '\t' << testNum << endl;
    }

    Vector2d v2d1(10.2222, 20.3333);
    Vector2d v2d2 = v2d1;
    if (v2d1 == v2d2) {
        cout << outFlags << v2d1.x << '\t' << v2d1.y << endl;
    }
    Vector3d v3d1(10.2222, 20.3333, 665.3232324242);
    Vector3d v3d2 = v3d1;
    if (v2d1 == v2d2) {
        cout << outFlags << v3d1.x << '\t' << v3d1.y << '\t' << v3d1.z << endl;
    }
    return 0;
}