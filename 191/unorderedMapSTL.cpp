// Unordered Map STL
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    // Creation of unordered_map (key = string, value = int)
    unordered_map<string, int> m;

    // Insertion methods

    // Method 1: Using make_pair
    pair<string, int> p = make_pair("Scorpio", 9);
    m.insert(p);

    // Method 2: Direct pair initialization
    pair<string, int> p2("alto", 2);
    m.insert(p2);

    // Method 3: Using [] operator
    m["fortuner"] = 10;

    // Access elements

    cout << m.at("alto") << endl;
    // at() throws error if key not found

    // cout << m.at("scorpio") << endl;
    // Error because keys are case-sensitive ("Scorpio" != "scorpio")

    cout << m["fortuner"] << endl;
    // 10

    // Search operations

    cout << m.count("Scorpio") << endl;
    // count() returns 1 if present, else 0

    if (m.find("fortuner") != m.end())
    {
        cout << "Fortuner Found" << endl;
    }
    else
    {
        cout << "Fortuner not found" << endl;
    }

    // Size of map

    cout << m.size() << endl;
    // current size = 3

    cout << m["hummer"] << endl;
    // if key doesn't exist → inserts with default value (0)

    cout << m.size() << endl;
    // now size = 4

    // Iteration over map

    for (auto i : m)
    {
        cout << i.first << " -> " << i.second << endl;
    }

    return 0;
}