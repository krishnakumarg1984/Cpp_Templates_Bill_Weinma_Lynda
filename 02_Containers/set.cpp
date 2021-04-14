// set.cpp by Bill Weinman <http://bw.org/>
// updated 2018-11-03 for CppSTL
#include <iostream>
#include <set>
#include <string>
#include <unordered_set>  // Does not sort elements & instead provides hash keys for faster access
using namespace std;

// for holding a sorted set of unique elements
// multiset class allows duplicates

// print the elements of the set
template <typename T>
void print_set(T& s) {
    if (s.empty())
        return;
    for (auto x : s)
        cout << x << " ";
    cout << endl;
}

// print a simple message
void message(const char* m) {
    cout << m << endl;
}
template <typename T>
void message(const char* m, const T& v) {
    cout << m << ": " << v << endl;
}

int main() {
    message("construct set set1");
    // set<string> set1 = { "one", "two", "three", "four", "five" };
    multiset<string> set1 = {
        "one", "two", "three", "four",
        "five"};  // allows duplicates, but the insert operation does not return
                  // a pair anymore
    message("size of set", set1.size());
    message("ordered set is alphabetical");
    print_set(set1);  // note: Alphabetical order

    message("insert element six");
    set1.insert("six");
    print_set(set1);

    message("find and erase element six");
    // set<string>::iterator it = set1.find("six");  // Note: the find() method
    // in the set container. Instead of the full syntax, can also use auto
    auto it = set1.find("six");

    if (it != set1.end()) {
        message("erasing", *it);
        set1.erase(it);
    } else {
        cout << "not found" << endl;
    }
    print_set(set1);

    message("inserting duplicate element: 'five'");
    // set1.insert("five");
    auto ret_val = set1.insert(
        "five");  // can also check for failure. the insert() method returns a
                  // pair. 1st element is an iterator pointing to either the new
                  // element or the duplicate element (the element that
                  // prevented the new insert). The 2nd element in the pair is
                  // either a true (success) or false (failure)
    // // Use only with 'set', not 'multiset'
    // if (!ret_val.second) {
    //     message("\nThe insert operation failed! Check if you are inserting
    //     duplicates\n");
    // } else {
    //     print_set(set1);  // Won't allow duplicates for 'set'
    //     cout << endl;
    // }

    print_set(set1);
    cout << endl;

    message("construct unordered set set2");
    // unordered_set<string> set2 = { "one", "two", "three", "four", "five" ,
    // "eight", "seven"}; // Does not allow duplicates
    unordered_multiset<string> set2 = {
        "one",  "two",   "three", "four",
        "five", "eight", "seven"};  // Does not allow duplicates
    message("size of set", set2.size());
    message("unordered set has no defined order");  // Cannot expect any sort of
                                                    // order within the set
    print_set(set2);

    message("insert element six");
    set2.insert("six");  // Will change the previous order
    print_set(set2);

    message("find and erase element six");
    auto it2 = set2.find(
        "six");  // uses hashes internally and therefore shall be faster
    if (it2 != set2.end()) {
        message("erasing", *it2);
        set2.erase(it2);
    } else {
        cout << "not found" << endl;
    }
    print_set(set2);

    message("inserting duplicate element five");
    set2.insert("five");  // Does not allow duplicates for regular 'set'.
                          // However, allowed for unordered multiset
    print_set(set2);
    cout << endl;

    return 0;
}
