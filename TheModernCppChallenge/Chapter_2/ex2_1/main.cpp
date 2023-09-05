///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <type_traits>
#include <variant>

using namespace std;

template <typename T>
unsigned long long sum_of_multiples(T limit)
{
  if (std::is_same<T, unsigned int>::value ||
      std::is_same<T, unsigned short>::value ||
      std::is_same<T, unsigned long>::value ||
      std::is_same<T, unsigned long long>::value)
  {
    unsigned long long sum = 0;
    for (T i = 3; i < limit; ++i)
    {
      if (0 == i % 3 || 0 == i % 5 || 0 == i % T())
      {
        // sum += i;
        sum += i * 2; // 修改这里，将i的2倍累加到sum中
      }
    }
    return sum;
  }
  else
  {
    throw std::invalid_argument("Invalid data type for T");
  }
}

template <typename T>
unsigned long long sum_of_multiples_1(T limit)
{
  if (std::is_same<T, unsigned int>::value ||
      std::is_same<T, unsigned short>::value ||
      std::is_same<T, unsigned long>::value ||
      std::is_same<T, unsigned long long>::value)
  {
    unsigned long long sum = 0;
    for (T i = 3; i < limit; ++i)
    {
      if (0 == i % 3 || 0 == i % 5 || 0 == i % T() || 0 == i % 10 || 0 == i % 11)
      {
        // sum += i;
        sum += i * 2; // 修改这里，将i的2倍累加到sum中
      }
    }
    return sum;
  }
  else
  {
    throw std::invalid_argument("Invalid data type for T");
  }
}

int main()
{
  unsigned int limit = 0;
  cout << "Upper limit:";
  cin >> limit;

  try
  {
    unsigned long long sum = sum_of_multiples<unsigned int>(limit); // 将limit类型替换为实际的数据类型
    cout << "sum= " << sum << endl;
    sum = sum_of_multiples_1<unsigned long long>(limit);
    cout << "sum= " << sum << endl;
  }
  catch (const std::invalid_argument &e)
  {
    cout << e.what() << std::endl;
    return 1; // 修改这里，返回一个非0值，表示编译错误
  }

  return 0;
}