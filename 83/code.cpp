// largest number (LC)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Custom comparator function to determine sorting order
bool myComp(string a, string b)
{
    string t1 = a + b;
    string t2 = b + a;
    return t1 > t2; // Sorting in descending order based on concatenation result
}

// Function to form the largest possible number from an array of integers
string largestNumber(vector<int> &nums)
{
    vector<string> snums;
    for (auto num : nums)
    {
        snums.push_back(to_string(num)); // Convert integers to strings
    }

    sort(snums.begin(), snums.end(), myComp); // Sort using custom comparator

    if (snums[0] == "0")
        return "0"; // Edge case: If the largest number is "0", return "0"

    string ans = "";
    for (auto str : snums)
    {
        ans += str; // Concatenate sorted strings
    }
    return ans;
}

int main()
{
    vector<int> nums = {3, 30, 34, 5, 9};                      // Example input
    cout << "Largest Number: " << largestNumber(nums) << endl; // Print the largest possible number
    return 0;
}

// output

// Largest Number: 9534330