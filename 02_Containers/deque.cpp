// deque.cpp by Bill Weinman <http://bw.org/>
// updated 2018-11-04 for CppSTL
#include <iostream>
#include <deque>
#include <string>
using namespace std;

// semantics of a vector, but optimised as a double ended queue
// report deque info
// Vector is optimised for random access, but deque is optimised for rapid
// push & pop from both its ends, which is why it is the default container for stacks and queues
// However,deque has got full random access & iterator capabilities

template <typename T>
void reportdeq(T & d) {
    size_t sz = d.size();
    cout << "size: " << sz;
    if (sz)
        cout << " front: " << d.front() << " back: " << d.back();
    cout << endl;
}

// print deque
template <typename T>
void printdeq(T & d) {
    if (d.empty())
        return;
    for (auto v : d)
        cout << v << " ";
    cout << endl;
}

// print a simple message
void message(const char * s) { cout << s << endl; }

int main() {
    message("create deque");
    deque<string> d1 = {"one", "two", "three"};

    message("push back values");
    d1.push_back("four");
    d1.push_back("five");

    reportdeq(d1);
    printdeq(d1);

    message("pop from front");
    d1.pop_front();
    printdeq(d1);

    message("pop from back");
    d1.pop_back();
    printdeq(d1);

    message("push front");
    d1.push_front("newfront");
    printdeq(d1);

    message("push back");
    d1.push_back("newback");
    printdeq(d1);

    return 0;
}
