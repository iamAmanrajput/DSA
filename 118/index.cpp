// Combination Sum --(LC)

#include <iostream>
#include <vector>

using namespace std;

void findCombination(vector<int> &candidates, int target,
                     vector<vector<int>> &ans, vector<int> &currAns, int index)
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

    for (int i = index; i < candidates.size(); i++)
    {
        currAns.push_back(candidates[i]);
        findCombination(candidates, target - candidates[i], ans, currAns, i);
        currAns.pop_back();
    }
}

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans;
    vector<int> currAns;

    findCombination(candidates, target, ans, currAns, 0);

    cout << "Combinations:\n";
    for (const auto &comb : ans)
    {
        for (int num : comb)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

// Combinations:
// 2 2 3
// 7