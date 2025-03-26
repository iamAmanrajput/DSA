// Subsequences of a string

#include <iostream>
using namespace std;

void printSubsequences(string str, string output, int i)
{
    // base case
    if (i >= str.length())
    {
        cout << output << endl;
        return;
    }

    // if we write include above then it's necessary to remove from output
    // include
    //   output.push_back(str[i]);
    //   printSubsequences(str, output, i + 1);
    // output.pop_back();

    // exclude
    printSubsequences(str, output, i + 1);

    // include
    output.push_back(str[i]);
    printSubsequences(str, output, i + 1);
}

int main()
{

    string str = "abc";
    string output = "";

    int index = 0;
    printSubsequences(str, output, index);

    return 0;
}
// output

//
// c
// b
// bc
// a
// ac
// ab
// abc