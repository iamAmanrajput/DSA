// Minimum costs for tickets -- (Lc)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive helper function to calculate the minimum cost from day i
int minCostTicketHelper(vector<int> &days, vector<int> &costs, int i)
{
    // Base case: If all days are covered, return 0
    if (i >= days.size())
        return 0;

    // Option 1: Take 1-day pass
    int cost1 = costs[0] + minCostTicketHelper(days, costs, i + 1);

    // Option 2: Take 7-day pass
    int passEndDay = days[i] + 7 - 1;
    int j = i;
    while (j < days.size() && days[j] <= passEndDay)
    {
        j++;
    }
    int cost7 = costs[1] + minCostTicketHelper(days, costs, j);

    // Option 3: Take 30-day pass
    passEndDay = days[i] + 30 - 1;
    j = i;
    while (j < days.size() && days[j] <= passEndDay)
    {
        j++;
    }
    int cost30 = costs[2] + minCostTicketHelper(days, costs, j);

    // Return the minimum of all options
    return min(min(cost1, cost7), cost30);
}

// Entry function to start computation
int mincostTickets(vector<int> &days, vector<int> &costs)
{
    return minCostTicketHelper(days, costs, 0);
}

int main()
{
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};
    cout << mincostTickets(days, costs) << endl;
    return 0;
}

// Input: days = [1,4,6,7,8,20], costs = [2,7,15]
// Output: 11
// Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
// On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
// On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
// On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
// In total, you spent $11 and covered all the days of your travel.