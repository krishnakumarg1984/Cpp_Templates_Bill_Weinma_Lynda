// auto.cpp by Bill Weinman <http://bw.org/>
// updated 2018-11-02
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

template <typename lT, typename rT>
auto tf(const lT &lhs, const rT &rhs) {
  return lhs + rhs;
}

int main() {
  int i = 47;
  const char *cstr = "this is a c-string.";
  const string sclass = string("this is a string class string.");

  auto x = "this is a c-string";  // Auto keyword used here to declare the type
  decltype(x) y;  // declaring that variable 'y' shall be of the same type as
                  // variable 'x'

  cout << "type of i is " << typeid(i).name() << endl;
  cout << "type of cstr is " << typeid(cstr).name() << endl;
  cout << "type of sclass is " << typeid(sclass).name() << endl;
  cout << "type of x is " << typeid(x).name() << endl;
  cout << "type of y is " << typeid(y).name() << endl;

  for (auto it = sclass.begin(); it != sclass.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  for (auto c : sclass) {
    std::cout << c << " ";
  }
  std::cout << std::endl;

  auto z = tf<string, const char *>(sclass, cstr);
  std::cout << "z is: " << z << std::endl;
  std::cout << "type of z is:" << typeid(z).name() << std::endl;

  return 0;
}
