// stack.cpp by Bill Weinman <http://bw.org/>
// updated 2018-09-14 for CppSTL
#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <string>
using namespace std;

// A stack is a container adapter (wrapper) which uses an underlying container to hold its contents

// Implements a LIFO stack. Pushed & popped at the back (which is the last
// element). Not a random access container

template <typename T>
void report_stack(T & stk) {
    cout << "size: " << stk.size() << " top: " << stk.top() << endl;  // top element is the back of the underlying container
}

// print a simple message
void message(const char * s) { cout << s << endl; }

int main() {
    // vector
    message("stk1");
    vector<int> v1 = {1, 2, 3, 4, 5};
    stack<int, vector<int>> stk1(v1);  // 2 args, a: the type of stack & b: type of underlying container
    report_stack(stk1);
    message("stk1 push 42");
    stk1.push(42);
    report_stack(stk1);
    message("stk1 pop");
    stk1.pop();
    report_stack(stk1);

    message("stk2 default stack (deque)");
    stack<string> stk2;
    for (string s : {"one", "two", "three", "four", "five", "six"}) {
        stk2.push(s);
    }
    report_stack(stk2);
    message("stk2 push forty-two");
    stk2.push("forty-two");
    report_stack(stk2);
    message("stk2 pop");
    stk2.pop();
    report_stack(stk2);

    return 0;
}
