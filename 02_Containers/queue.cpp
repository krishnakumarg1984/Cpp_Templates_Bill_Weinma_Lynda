// queue.cpp by Bill Weinman <http://bw.org/>
// updated 2018-09-14 for CppSTL
#include <deque>
#include <iostream>
#include <list>
#include <queue>
#include <string>
using namespace std;

// A queue is a container adapter which uses an underlying container to hold
// its contents

// Implements a FIFO queue. Push onto back, and pop from front
// Not a random access container

template <typename T>
void report_queue(T& q) {
    size_t sz = q.size();
    cout << "size: " << sz;
    if (sz)
        cout << " front: " << q.front() << " back: " << q.back();
    cout << endl;
}

// print a simple message
void message(const char* s) {
    cout << s << endl;
}

int main() {
    // queue from list (list as underlying container)
    // message("initialize queue from list");
    // list<int> l1 = {1, 2, 3, 4, 5};
    // queue<int, list<int>> q1(l1);    // constructor copies to new list
    // report_queue(q1);

    // But the default container for a queue is a deque since it is optimized
    // for this kind of use. This is why deque even exists
    message("initialize queue from deque");
    deque<int> l1 = {1, 2, 3, 4, 5};
    queue<int, deque<int>> q1(l1);  // constructor copies to new deque
    report_queue(q1);

    message("pop all from q1");
    while (!q1.empty()) {
        cout << q1.front() << " ";
        q1.pop();
    }
    cout << endl;
    report_queue(q1);

    // default queue (deque)
    queue<string>
        q2;  // Note: unlike above, the underlying container is not specified
    message("push strings onto q2");
    for (string s : {"one", "two", "three", "four", "five", "six"}) {
        q2.push(s);
    }
    report_queue(q2);

    message("pop all from q2");
    while (!q2.empty()) {
        cout << q2.front() << " ";
        q2.pop();
    }
    cout << endl;
    report_queue(q2);

    return 0;
}
