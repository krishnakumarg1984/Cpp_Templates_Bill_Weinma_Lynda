// input-iterator.cpp by Bill Weinman <http://bw.org/>
// 2018-09-18 for CppSTL
#include <iostream>
#include <iterator>  // output & input iterators are defined here
using namespace std;

// An input iterator is the simplest form of iterator. May be used to read the
// value of an object once and then increment. Capable of reading, but not
// writing, incrementing but not decrementing. Once a value is read, it cannot
// be read again.

void message(const char* m) {
    cout << m << endl;
}

int main() {
    double d1 = 0, d2 = 0;

    cout << "Enter two numeric values: " << flush;
    cin.clear();
    istream_iterator<double> eos;       // default constructor is end-of-stream
    istream_iterator<double> iit(cin);  // stdin iterator

    if (iit == eos) {
        message("no values");
        return 0;
    } else {
        d1 = *iit++;
    }

    if (iit == eos) {
        message("no second value");
        return 0;
    } else {
        d2 = *iit;
    }

    cin.clear();
    cout << d1 << " * " << d2 << " = " << d1 * d2 << endl;

    return 0;
}
