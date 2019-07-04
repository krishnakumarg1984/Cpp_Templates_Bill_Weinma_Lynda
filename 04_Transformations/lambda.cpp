// lambda.cpp by Bill Weinman <http://bw.org/>
// 2018-09-24 for CppSTL
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void disp_v(vector<T> & v) {
    if (!v.size()) return;
    for (T e :  v) { cout << e << " "; }
    cout << endl;
}

int main()
{
    int accum = 14;
    auto x = [accum](int d) mutable -> int { return accum += d; };  // This is a lambda function
    // capturing this 'accum' variable which is an accumulator.
    // Takes 1 parameter, an integer called 'd'
    // returns an integer (as seen on the RHS of ->)
    // marked as mutable so that the compiler will know that it changes a value
    // Simply returns the accumulation by using the += operator to accumulate the next value

    vector<int> v1 = { 1, 2, 3, 4, 5};
    disp_v(v1);

    vector<int> v2(v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), x);  // operator is 'x' which in this case is the lambda function

    disp_v(v2);

    return 0;
}
