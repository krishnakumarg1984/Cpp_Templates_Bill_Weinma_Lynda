// list.cpp by Bill Weinman <http://bw.org/>
// updated 2018-09-12 for CppSTL

// list is a sequence container like a vector but optimized for rapid inset &
// remove operations. Do not support random access unlike vectors.
#include <iostream>
#include <list>
using namespace std;

// print the elements of the list
template<typename T>
void printl(list<T> & l) {
    if (l.empty()) return;
    for (T &i : l) cout << i << " ";
    cout << endl;
}

// print a simple message
void message(const char * s) { cout << s << endl; }
void message(const char * s, const int n) { cout << s << ": " << n << endl; }

int main() {
    list<int> l1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    printl(l1);
    message("size", (int) l1.size());
    message("front", l1.front());
    message("back", l1.back());

    message("push back 47");
    l1.push_back(47);
    printl(l1);

    // need an iterator to insert and erase
    message("insert:");  // Goal is to insert 112 before the element with the value of 5
    list<int>::iterator it1 = l1.begin();  // Can also use auto
    while ((*++it1 != 5) && (it1 != l1.end()))
        continue;  // Skip (move along the list) until the value pointed to by the iterator is 5
    if (it1 != l1.end()) {
        message("insert 112 before 5");
        l1.insert(it1, 112);
    }
    printl(l1);

    // find element with the value value 3 & erase it from the list
    it1 = l1.begin();
    message("\nThe value of *++it1 is now", static_cast<int>(*++it1));
    // cout << *++it1 << endl;
    // while ((*++it1 != 7) && (it1 != l1.end()));
    while ((*++it1 != 3) && (it1 != l1.end()));
    if (it1 != l1.end()) {
        message("erase 3");
        l1.erase(it1);
    }
    printl(l1);

    // remove all elements with the value 8
    l1.remove(8);  // This is a convenience function that will do the above task for us (ie search the list for all the elements with the given value & remove them)
    message("remove 8");
    printl(l1);

    message("erase everything between value 112 & value 9");
    auto it2 = it1 = l1.begin();  // Note: the use of 'auto' here
    while ( ( *++it1 != 112) && (it1 != l1.end() ) )
        continue;  // Skip until 'it1' is pointing to 112
    while ( ( *++it2 != 9) && (it2 != l1.end() ) )
        continue;  // Skip until 'it2' is pointing to 9
    if (it1 != l1.end() && it2 != l1.end()) {
        l1.erase(it1, it2);  // exclusive of it2 (but includes it1)
        printl(l1);
    }

    cout << endl;

    return 0;
}
