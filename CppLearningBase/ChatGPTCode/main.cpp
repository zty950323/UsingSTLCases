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
 * @brief This file generate a code from ChatMoss tools in visual studio code. For the question:
 * 帮我用C++写一段浮点数大数相加的算法，两个大数至少是32位的整数位。
 * @file basic_config_service.h
 * @author Tom Zhao(18872770445@163.com)
 * @since 2023-03-18
 * @date Created: 2023-03-18
 * @date Last modified: 2023-03-18
 *
 * Github: @link https://github.com/zty950323/UsingSTLCases @endlink
 * Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
 * Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
 */

#include <iostream>
#include <string>

using namespace std;

// 字符串反转函数
void Reverse(string &s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }
}

// 大数相加函数
string Add(string a, string b) {
    // 将a和b字符串反转并补齐位数
    Reverse(a);
    Reverse(b);
    while (a.length() < b.length()) {
        a += '0';
    }
    while (a.length() > b.length()) {
        b += '0';
    }

    // 进行相加操作
    string c = "";
    int carry = 0;
    int n = a.length();
    for (int i = 0; i < n; i++) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        c += to_string(sum % 10);
        carry = sum / 10;
    }
    if (carry > 0) {
        c += to_string(carry);
    }

    // 反转结果并返回
    Reverse(c);
    return c;
}

int main() {
    string a = "123456789012345678901234567890";
    string b = "987654321098765432109876543210";
    cout << Add(a, b) << endl;
    return 0;
}
