// search.cpp by Bill Weinman <http://bw.org/>
// 2018-09-30 for CppSTL
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
bool is_odd(const T& n) {
  return ((n % 2) == 1);
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
  // prime numbers < 100
  // const vector<int> v1 = {2,  3,  4,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37,
  //                         41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89,
  //                         97};

  // const vector<int> v1 = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
  //                         43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
  const vector<int> v1 = {2,  3,  5,  7, 11, 13, 17, 19, 23, 29, 31, 37,
                          41, 43, 47, 7, 53, 59, 7,  61, 67, 68, 42, 32,
                          48, 7,  71, 7, 73, 79, 83, 7,  89, 97};
  disp_v(v1);

  // const vector<int> v2 = {31, 37, 41, 43, 47};

  // does a sequential search using the = comparison. If found, returns an
  // iterator pointing to the value, otherwise returns the end-point iterator
  // auto it = find(v1.begin(), v1.end(), 41);

  // Finds the 1st one matching the conditional results of a unary operator
  // auto it = find_if(v1.begin(), v1.end(), is_odd<int>);

  // auto it = find_if_not(v1.begin(), v1.end(), is_odd<int>);

  // Search for the 2nd range within the 1st range
  // auto it = search(v1.begin(), v1.end(), v2.begin(), v2.end());
  //
  // if (it != v1.end()) {
  //   size_t index = it - v1.begin();
  //   cout << "found at index " << index << ": " << *it << endl;
  // } else {
  //   cout << "not found" << endl;
  // }

  // Counting functions (counting for no. of occurrences etc)
  // auto c = count(v1.begin(), v1.end(), 7);
  auto c = count_if(v1.begin(), v1.end(), is_odd<int>);

  std::cout << "found " << c << " occurrences" << std::endl;

  return 0;
}
