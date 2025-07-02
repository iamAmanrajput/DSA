// combination sum 2 --(LC)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive helper function to find all unique combinations
void findCombination(vector<int> &candidates, int target,
                     vector<vector<int>> &ans, vector<int> &currAns,
                     int index)
{
    if (target == 0)
    {
        ans.push_back(currAns);
        return;
    }

    if (target < 0)
    {
        return;
    }

    // Iterate through the candidates starting from the current index
    for (int i = index; i < candidates.size(); i++)
    {
        // Skip duplicates: if the current candidate is the same as the previous one
        // and it's not the first candidate in this loop, skip it
        // This ensures that combinations are unique
        // alaways i == index but when but hit bc and return then for loop update i++ and the value of i > index and if both cand[i] == cand[i-1] then we skip the value
        if (i > index && candidates[i] == candidates[i - 1])
        {
            continue;
        }

        currAns.push_back(candidates[i]);

        findCombination(candidates, target - candidates[i], ans, currAns, i + 1);

        // Backtrack: remove the last added candidate
        currAns.pop_back();
    }
}

int main()
{
    // Input array and target sum
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    // Sort the array to handle duplicates easily
    sort(candidates.begin(), candidates.end());

    vector<vector<int>> ans;
    vector<int> currAns;

    findCombination(candidates, target, ans, currAns, 0);

    cout << "Unique combinations that sum to " << target << ":\n";
    for (const auto &comb : ans)
    {
        cout << "[ ";
        for (int num : comb)
        {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}

// OutPut

// Unique combinations that sum to 8:
// [ 1 1 6 ]
// [ 1 2 5 ]
// [ 1 7 ]
// [ 2 6 ]