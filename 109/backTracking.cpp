// Find Permutation of a string using backtracking

#include <iostream>
using namespace std;

void printPermutation(string &str, int i)
{

    // base case
    if (i >= str.length())
    {
        cout << str << " ";
        return;
    }

    // swapping
    for (int j = i; j < str.length(); j++)
    {
        // swap
        swap(str[i], str[j]);

        // recursive call
        printPermutation(str, i + 1);

        // backtracking
        swap(str[i], str[j]);
    }
};

int main()
{

    int i = 0;
    string str = "abc";

    printPermutation(str, i);

    return 0;
}

// output
// abc acb bac bca cba cab