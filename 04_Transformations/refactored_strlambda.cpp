// lambda.cpp by Bill Weinman <http://bw.org/>
// 2018-09-24 for CppSTL
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

template <typename T>
void disp_v(vector<T> & v) {
    if(!v.size()) return;
    for(T e :  v) { cout << e << " "; }
    cout << endl;
}

size_t strsz(string &s) {
    return s.size();
}

int main()
{

    vector<string> v1 = {"one","two","three","four","five"};
    disp_v(v1);

    vector<size_t> v2(v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), strsz);  // 'x' in this case is a lambda function

    disp_v(v2);

    return 0;
}
