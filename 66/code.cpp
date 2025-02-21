// Paratha  --(spoj)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if we can make 'nP' pratas within 'mid' minutes
bool isPossibleSolution(vector<int> &cookRanks, int nP, int mid)
{
    int currParatha = 0; // Counter for the total pratas made

    // Iterate over each cook
    for (int i = 0; i < cookRanks.size(); i++)
    {
        int R = cookRanks[i]; // Rank of the current cook
        int timeTaken = 0;
        int j = 1; // This represents how many pratas this cook has made

        // Try making pratas until the time limit 'mid' is reached
        while (true)
        {
            if (timeTaken + j * R <= mid)
            {
                currParatha++;      // One more prata is cooked
                timeTaken += j * R; // Update total time taken
                j++;                // Move to the next prata for this cook
            }
            else
            {
                break; // If next prata cannot be made in the given time, stop
            }
        }

        // If we have already made required pratas, return true
        if (currParatha >= nP)
        {
            return true;
        }
    }
    return false; // If we couldn't make 'nP' pratas in 'mid' minutes
}

// Function to find the minimum time required to make all parathas
int minTimeToCompleteOrder(vector<int> &cookRanks, int nP)
{
    int start = 1; // Minimum time required should be at least 1 minute
    int highestRank = *max_element(cookRanks.begin(), cookRanks.end());

    // Maximum time required (slowest cook makes all parathas)
    int end = highestRank * (nP * (nP + 1) / 2);
    int ans = -1; // Store the best possible answer

    // Apply Binary Search on the time
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isPossibleSolution(cookRanks, nP, mid))
        {
            ans = mid;     // Store the minimum possible time found
            end = mid - 1; // Try to find a smaller time
        }
        else
        {
            start = mid + 1; // Increase time if we couldn't make enough pratas
        }
    }
    return ans;
}

int main()
{
    int T; // Number of test cases
    cin >> T;

    while (T--)
    {
        int nP, nC; // Number of pratas and number of cooks
        cin >> nP >> nC;

        vector<int> cookRanks(nC); // Store the rank of each cook

        // Read ranks properly (Fixing the push_back issue)
        for (int i = 0; i < nC; i++)
        {
            cin >> cookRanks[i];
        }

        // Find and print the minimum time required
        cout << minTimeToCompleteOrder(cookRanks, nP) << endl;
    }

    return 0;
}

// input
//  1 test case
//  10 paratha
//  4 no.of cooks
//  1 2 3 4 ranks
// output
//  12 min time
