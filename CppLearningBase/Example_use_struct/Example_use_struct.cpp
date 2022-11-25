///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <map>

using namespace std;

struct book {
  double price;
  char* title;

  void display();
};

void testMap() {
  std::map<const double, book> priceBooks;
  std::map<double, book> priceBooks1;
  book b1;
  b1.price = 100;
  book b2;
  b2.price = 200;
  priceBooks[100] = b1;
  priceBooks[200] = b2;
  priceBooks1[100] = b1;
  priceBooks1[200] = b2;
  for (const auto& b : priceBooks) {
    cout << b.first << endl;
  }
  for (const auto& book : priceBooks1) {
    cout << book.first << endl;
  }
}

void book::display() { cout << title << ", price: " << price << endl; }

int main() {
  book Alice;
  Alice.price = 29.9;                                      // It's OK
  Alice.title = const_cast<char*>("Alice in wonderland");  // It's OK
  Alice.display();                                         // It's OK
  return 0;
}