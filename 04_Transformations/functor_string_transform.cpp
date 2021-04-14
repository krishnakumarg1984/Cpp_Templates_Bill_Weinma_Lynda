// string-transform.cpp by Bill Weinman <http://bw.org/>
// 2018-09-25 for CppSTL
#include <algorithm>
#include <iostream>
#include <locale>
#include <string>
#include "./title-case.h"
using namespace std;

int main() {
    string s1 = "this is a string";
    cout << s1 << endl;

    string s2(s1.size(), '.');  // s2 is of the same size as s1, but is filled
                                // with dots (periods)
    cout << s2 << endl;

    // // transform(s1.begin(), s1.end(), s2.begin(), ::toupper);
    // transform(s1.begin(), s1.end(), s2.begin(), title_case());  // () used
    // here because using the class & not the object

    // if you need to use an object, then instead of above
    title_case t;
    transform(s1.begin(), s1.end(), s2.begin(),
              t);  // () used here because using the class & not the object

    cout << s2 << endl;

    return 0;
}
