// output-iterator.cpp by Bill Weinman <http://bw.org/>
// 2018-09-18 for CppSTL
#include <iostream>
#include <iterator>  // output & input iterators are defined here
using namespace std;

// output iterator can be used to write a value once & then increment

int main() {
    ostream_iterator<int> output(
        cout, " ");  // <space> is used as the separator (delimiter)

    for (int i : {3, 197, 42}) {
        *output++ = i;
    }
    cout << endl;

    return 0;
}
