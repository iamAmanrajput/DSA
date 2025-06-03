// 273. Integer to English Words -- (LC-hard)

#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

// Global vector to store mapping of numbers to words
vector<pair<int, string>> mp = {
    {1000000000, "Billion"},
    {1000000, "Million"},
    {1000, "Thousand"},
    {100, "Hundred"},
    {90, "Ninety"},
    {80, "Eighty"},
    {70, "Seventy"},
    {60, "Sixty"},
    {50, "Fifty"},
    {40, "Forty"},
    {30, "Thirty"},
    {20, "Twenty"},
    {19, "Nineteen"},
    {18, "Eighteen"},
    {17, "Seventeen"},
    {16, "Sixteen"},
    {15, "Fifteen"},
    {14, "Fourteen"},
    {13, "Thirteen"},
    {12, "Twelve"},
    {11, "Eleven"},
    {10, "Ten"},
    {9, "Nine"},
    {8, "Eight"},
    {7, "Seven"},
    {6, "Six"},
    {5, "Five"},
    {4, "Four"},
    {3, "Three"},
    {2, "Two"},
    {1, "One"}};

// Function to convert a number into words (recursive)
string numberToWords(int num)
{
    // Base case: if number is 0
    if (num == 0)
    {
        return "Zero";
    }

    // Iterate through the map to find the largest number less than or equal to num
    for (auto it : mp)
    {
        if (num >= it.first)
        {
            string a = "";

            // If number is greater than or equal to 100, recursively convert the left part
            if (num >= 100)
            {
                a = numberToWords(num / it.first) + " ";
            }

            // Word for the current matched value
            string b = it.second;

            string c = "";

            // If there is a remainder, recursively convert the right part
            if (num % it.first != 0)
            {
                c = " " + numberToWords(num % it.first);
            }

            // Combine the parts and return the result
            return a + b + c;
        }
    }

    // This line will never be reached, but added to satisfy return requirements
    return "";
}

// Driver code to test the function
int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    string result = numberToWords(num);
    cout << "Number in words: " << result << endl;

    return 0;
}

// Input: num = 1234567
// Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"