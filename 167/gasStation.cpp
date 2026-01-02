// Leetcode Problem 134. Gas Station
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        // kitna petrol kam pad gya
        int deficit = 0;

        // kitna petrol bacha huaa hai
        int balance = 0;

        // circuit kaha se start huaa hai
        int start = 0;

        for (int i = 0; i < gas.size(); i++)
        {
            balance += gas[i] - cost[i];

            // agar petrol negative ho gaya
            if (balance < 0)
            {
                deficit += balance; // jo loss hua usko deficit me add
                start = i + 1;      // next station se start try karenge
                balance = 0;        // balance reset
            }
        }

        // total petrol (balance + deficit) agar >= 0 hai
        if (deficit + balance >= 0)
        {
            return start;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    Solution sol;

    // Test Case 1
    vector<int> gas1 = {1, 2, 3, 4, 5};
    vector<int> cost1 = {3, 4, 5, 1, 2};
    cout << "Output 1: " << sol.canCompleteCircuit(gas1, cost1) << endl;
    // Expected Output: 3

    // Test Case 2
    vector<int> gas2 = {2, 3, 4};
    vector<int> cost2 = {3, 4, 3};
    cout << "Output 2: " << sol.canCompleteCircuit(gas2, cost2) << endl;
    // Expected Output: -1

    // Test Case 3
    vector<int> gas3 = {5};
    vector<int> cost3 = {4};
    cout << "Output 3: " << sol.canCompleteCircuit(gas3, cost3) << endl;
    // Expected Output: 0

    return 0;
}
