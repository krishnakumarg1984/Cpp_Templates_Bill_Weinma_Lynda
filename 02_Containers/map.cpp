// map.cpp by Bill Weinman <http://bw.org/>
// updated 2018-11-03 for CppSTL
#include <iostream>
#include <string>
#include <map>
using namespace std;

// Map-class provides a sorted set of key-value pairs like an associative
// array

// print a pair
template <typename T1, typename T2>
void print_pair(pair<T1,T2> & p) {
    cout << p.first << ": " << p.second << endl;
}

// print the elements of the map
template<typename T>
void print_map(T & m) {
    if (m.empty()) return;
    for (auto x : m) print_pair(x);
    cout << endl;
}

// print a simple message
void message(const char * m) { cout << m << endl; }
template <typename T>
void message(const char * m, const T & v) { cout << m << ": " << v << endl; }

// MARK: - main

int main() {
    message("map of strings from initializer list");
    // map<string, string> mapstr = { { "George", "Father" }, { "Ellen", "Mother" },
    multimap<string, string> mapstr = { { "George", "Father" }, { "Ellen", "Mother" },
        { "Ruth", "Daughter" }, { "Spike", "Neighbor's Son" } };  // both key & value are strings

    // multimap allows duplicates
    message("size", mapstr.size());
    message("get some values");

    // message("George", mapstr["George"]);  // does not work with multimap (since the keys are not guaranteed to be unique)
    // message("Ellen", mapstr.at("Ellen"));  // does not work with multimap (since the keys are not guaranteed to be unique)

    message("Spike", mapstr.find("Spike")->second);
    message("print_map:");
    print_map(mapstr);  // sorted. Very valuable in storing usernames & other database keys

    message("insert an element");
    mapstr.insert({ "Luke", "Neighbor" });
    message("size", mapstr.size());
    print_map(mapstr);

    cout << "insert a duplicate:" << endl;
    mapstr.insert({ "Luke", "Neighbor" });  // This will fail for map (will succeed for multimap). First element in the returned pair is an iterator that points to the inserted element
    // auto rp = mapstr.insert({ "Luke", "Neighbor" });  // This will fail for map (will succeed for multimap). First element in the returned pair is an iterator that points to the inserted element
    // cout << "insert an element:" << endl;
    // auto rp = mapstr.insert({ "Leia", "Neighbor" });  // This will succeed anyway since this is a non-duplicate. First element in the returned pair is an iterator that points to the inserted element

    // Not necessary with multimap
    // if (rp.second) {
    //     message("insert succeeded");
    //     print_pair(*rp.first);
    // } else {
    //     message("insert failed");
    // }

    message("size", mapstr.size());
    print_map(mapstr);

    message("find and erase Spike");
    auto it = mapstr.find("Spike");
    if (it != mapstr.end()) {
        message("Found the key in the map!");
        print_pair(*it);
        mapstr.erase(it);
        message("Erased this key!");
    } else {
        message("not found");
    }
    message("size", mapstr.size());
    print_map(mapstr);

    return 0;
}
