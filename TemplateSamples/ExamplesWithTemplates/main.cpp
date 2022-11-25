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
 * @brief This is a file for learning Templates in C++ with Examples
 * @link https://www.geeksforgeeks.org/templates-cpp/ @endlink
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

using std::cout;
using std::endl;
using std::swap;

using UINT = unsigned int;

class Lessons {
 public:
  Lessons(UINT chineseScore = 0, UINT mathScore = 0, UINT englishScore = 0,
          UINT historyScore = 0)
      : m_chineseScore(chineseScore),
        m_mathScore(mathScore),
        m_englishScore(englishScore),
        m_historyScore(historyScore),
        m_totalScore(chineseScore + mathScore + englishScore + historyScore) {}
  ~Lessons() = default;

  bool operator>(const Lessons& other) const {
    if (m_totalScore > other.m_totalScore) {
      return true;
    } else {
      return false;
    }
  }

  bool operator<(const Lessons& other) const {
    if (m_totalScore < other.m_totalScore) {
      return true;
    } else {
      return false;
    }
  }

  UINT totalScore() const { return m_totalScore; }

 private:
  UINT m_chineseScore = 0;
  UINT m_mathScore = 0;
  UINT m_englishScore = 0;
  UINT m_historyScore = 0;
  UINT m_totalScore = 0;
};

namespace MyMax {
// One function works for all data types. This would work
// even for user defined types if operator '>' is overloaded.
template <typename T>
T myMax(T x, T y) {
  return (x > y) ? x : y;
}

void testCase() {
  cout << myMax<int>(3, 7) << endl;                 // Call myMax for int
  cout << myMax<double>(3.0, 7.0) << endl;          // call myMax for double
  cout << myMax<char>('g', 'e') << endl;            // call myMax for char
  cout << myMax<float>(10.333f, 10.3334f) << endl;  // call myMax for float
  Lessons personA(88, 55, 66, 77);
  Lessons personB(99, 66, 88, 55);
  cout << myMax<Lessons>(personA, personB).totalScore()
       << endl;  // call myMax for Lessons class object.
}
}  // namespace MyMax

namespace BubbleSort {
// A template function to implement bubble sort.
// We can use this for any data type that supports
// comparison operator < and swap works for it.
template <class T>
void bubbleSort(T a[], int n) {
  for (int i = 0; i < n - 1; i++)
    for (int j = n - 1; i < j; j--)
      if (a[j] < a[j - 1]) swap(a[j], a[j - 1]);
}

void testCase() {
  // using bubble sort by int.
  int a[5] = {10, 50, 30, 40, 20};
  int n = sizeof(a) / sizeof(a[0]);

  // calls template function
  bubbleSort<int>(a, n);

  cout << " Sorted array a : ";
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << endl;

  // using bubble sort by double.
  double b[5] = {11.11, 555.666, 33.44, 22.33, 44.55};
  n = sizeof(b) / sizeof(b[0]);

  // calls template function
  bubbleSort<double>(b, n);

  cout << " Sorted array b : ";
  for (int i = 0; i < n; i++) cout << b[i] << " ";
  cout << endl;

  // using bubble sort by Lessons.
  Lessons l[5] = {Lessons(99, 22, 44, 55), Lessons(89, 72, 55, 100),
                  Lessons(66, 77, 56, 45), Lessons(56, 33, 94, 85),
                  Lessons(88, 92, 94, 95)};
  n = sizeof(l) / sizeof(l[0]);

  // calls template function
  bubbleSort<Lessons>(l, n);
  cout << " Sorted array l : ";
  for (int i = 0; i < n; i++) cout << l[i].totalScore() << " ";
  cout << endl;
}
}  // namespace BubbleSort

namespace TemplateClass {
template <typename T>
class Array {
 public:
  Array(T arr[], int s);
  void print();

 private:
  T* ptr;
  int size;
};
}  // namespace TemplateClass

int main() {
  MyMax::testCase();
  BubbleSort::testCase();
  return 0;
}
