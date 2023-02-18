#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  const double PI = 3.14159;
  double a, b; // a为椭圆的长半轴 b为椭圆的短半轴 cout << "Please enter the long semi-axis: ";
  cin >> a;
  cout << "Please enter the short semi-axis: ";
  cin >> b;
  double area = PI * a * b; // 椭圆面积公式
  cout << "The area of elliptical is: " << area << endl;
  return 0;
}
