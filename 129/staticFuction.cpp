// Static Functions

#include <iostream>
using namespace std;

class Counter
{
private:
    static int count; // yeh sabhi objects ke liye common hai

public:
    Counter()
    {
        count++; // jab bhi object banta hai, count badh jaata hai
    }

    // Static function jo count show karega
    static void showCount()
    {
        cout << "Objects ban chuke hain: " << count << endl;
    }
};

// Static variable ko class ke bahar initialize karte hain
int Counter::count = 0;

int main()
{
    Counter c1, c2; // 2 objects ban gaye

    // Static function ko class name se call kar sakte ho
    Counter::showCount(); // Output: Objects ban chuke hain: 2

    Counter c3;     // ek aur object
    c3.showCount(); // object se bhi call kar sakte ho, Output: 3

    return 0;
}

// output

// Objects ban chuke hain: 2
// Objects ban chuke hain: 3