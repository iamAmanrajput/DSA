// zig zag conversion -- (LC)

#include <iostream>
#include <vector>
using namespace std;

// Function to convert string into ZigZag pattern based on numRows
string convert(string s, int numRows)
{
    if (numRows == 1)
    { // If only one row, return the string as is
        return s;
    }

    vector<string> zigzag(numRows); // Vector to store characters for each row
    int i = 0, row = 0;
    bool direction = true; // true means moving downwards

    while (true)
    {
        if (direction)
        { // Moving downward in the ZigZag pattern
            while (row < numRows && i < s.size())
            {
                zigzag[row++].push_back(s[i++]);
            }
            row -= 2; // Move up two rows to start going up
        }
        else
        { // Moving upward in the ZigZag pattern
            while (row >= 0 && i < s.size())
            {
                zigzag[row--].push_back(s[i++]);
            }
            row = 1; // Move to the second row to start going down
        }
        if (i >= s.size())
            break;              // Stop when all characters are processed
        direction = !direction; // Change direction
    }

    string ans = "";
    for (int i = 0; i < zigzag.size(); i++)
    { // Combine all rows to form final string
        ans += zigzag[i];
    }
    return ans;
}

int main()
{
    string s = "ABCDEFGHIJ";
    int numRows = 3;
    cout << "Converted string: " << convert(s, numRows) << endl; // Print converted string
    return 0;
}

// output
//  Converted string: AEIBDFHJCG