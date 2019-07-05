// arithmetic.cpp by Bill Weinman <http://bw.org/>
// 2018-11-06 for CppSTL
#include <algorithm>
#include <functional>  // Note the 'functional' header
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void disp_v(vector<T>& v) {
  if (!v.size()) return;
  for (T e : v) {
    cout << e << " ";
  }
  cout << endl;
}

int main() {
  vector<long> v1 = {26, 52, 79, 114, 183};
  vector<long> v2 = {1, 2, 3, 4, 5};
  vector<long> v3(v1.size(), 0);
  disp_v(v1);
  disp_v(v2);
  disp_v(v3);
  cout << endl;

  // plus<long> f;  // plus functor. Best to define an object (here, f) to get
  // the full value of a functor
  // minus<long> f;
  // multiplies<long> f;
  // divides<long> f;  // integer division only
  // modulus<long> f;
  // transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), f);

  negate<long> f;  // unary functor
  transform(v1.begin(), v1.end(), v3.begin(), f);

  disp_v(v3);

  return 0;
}
