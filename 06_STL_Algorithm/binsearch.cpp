// binsearch.cpp by Bill Weinman <http://bw.org/>
// 2018-11-06 for CppSTL
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
bool gtcomp(const T& lh, const T& rh) {
  return lh > rh;
}

template <typename T>
void disp_v(const T& v) {
  if (!v.size()) return;
  for (auto e : v) {
    cout << e << " ";
  }
  cout << endl;
}

int main() {
  int n = 47;
  // int n = 48;

  // prime numbers < 100
  vector<int> v1 = {83, 53, 47, 23, 13, 59, 29, 41, 19, 71, 31, 67, 11, 2, 97,
                    7,  61, 47, 73, 3,  47, 79, 47, 37, 43, 17, 5,  47, 89};
  disp_v(v1);

  sort(v1.begin(), v1.end());
  // sort(v1.begin(), v1.end(), gtcomp<int>);
  disp_v(v1);

  cout << "searching for " << n << " ... ";
  if (binary_search(v1.begin(), v1.end(), n)) {
    // if (binary_search(v1.begin(), v1.end(), n, gtcomp<int>)) {
    cout << "found ";
  } else {
    cout << "not found";
  }
  cout << endl;

  // iterator to 1st value that it finds that matches the search parameter
  auto it = lower_bound(v1.begin(), v1.end(), n);
  std::cout << "lower bound: " << *it << std::endl;

  it = upper_bound(v1.begin(), v1.end(), n);
  std::cout << "upper bound: " << *it << std::endl;

  // Can obtain both bounds as a pair in 1 shot
  auto pr = equal_range(v1.begin(), v1.end(), n);
  std::cout << "lower bound: " << *pr.first << std::endl;
  std::cout << "upper bound: " << *pr.second << std::endl;

  return 0;
}
