// modify.cpp by Bill Weinman <http://bw.org/>
// 2018-11-06 for CppSTL
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// For modifying changes to sequences

template <typename T>
void disp_v(const T& v) {
  if (!v.size()) return;
  for (auto e : v) {
    cout << e << " ";
  }
  cout << endl;
}

int main() {
  // prime numbers < 100
  vector<int> v1 = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                    43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
  vector<int> v2(v1.size(), 0);
  disp_v(v1);
  disp_v(v2);

  // copy(v1.begin(), v1.end(), v2.begin());

  // // Result is exactly the same, but the algorithm is copying from back to
  // front copy_backward(v1.begin(), v1.end(), v2.end());

  // Give no. of items to copy
  // copy_n(v1.begin(), 15, v2.begin());

  // reverse_copy(v1.begin(), v1.end(), v2.begin());
  // disp_v(v2);

  // reverse(v1.begin(), v1.end());

  // Fill all but the last 10 elements with the number 83
  // fill(v1.begin(), v1.end() - 10, 83);

  // fill_n(v1.begin(), 14, 92);
  // disp_v(v1);

  // generate(v2.begin(), v2.end(), []() -> int { return rand() % 100; });
  // disp_v(v2);

  // random_shuffle has been deprecated from C++17 onwards
  // random_shuffle(v1.begin(), v1.end());
  random_shuffle(v1.begin(), v1.end(), [](int i) -> int { return rand() % i; });
  disp_v(v1);

  return 0;
}
