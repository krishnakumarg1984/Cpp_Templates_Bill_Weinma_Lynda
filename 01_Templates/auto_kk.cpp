// auto.cpp by Bill Weinman <http://bw.org/>
// updated 2018-11-02
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

int main() {
  // int i = 47;
  // const char *cstr = "this is a c-string.";
  // const string sclass = string("this is a string class string.");

  auto x{"this is a string"};
  decltype(x) y;
  std::cout << "the type of cstr is:" << typeid(cstr).name() << std::endl;
  std::cout << "the type of x is:" << typeid(x).name() << std::endl;

  return 0;
}
