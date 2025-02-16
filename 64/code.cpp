// Aggressive Cow Problem --(GFG)

#include <bits/stdc++.h> // Importing all standard libraries
using namespace std;

/**
 * Function to check if it is possible to place `k` cows in the stalls
 * such that the minimum distance between any two cows is at least `mid`.
 */
bool isPossible(vector<int> &stalls, int k, int mid)
{
    int count = 1;       // First cow placed at the first stall
    int pos = stalls[0]; // Position of the last placed cow

    // Iterate through stalls and try to place cows at a minimum distance of `mid`
    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - pos >= mid)
        {                    // If the gap is at least `mid`, place a cow
            count++;         // ye cow bhi placed kar di
            pos = stalls[i]; // Update position of last placed cow

            if (count == k)
            { // If all cows are placed successfully, return true
                return true;
            }
        }
    }
    return false; // Not possible to place all cows with given `mid`
}

/**
 * Function to find the largest minimum distance between cows using Binary Search.
 */
int aggressiveCows(vector<int> &stalls, int k)
{
    // Step 1: Sort the stalls in ascending order
    sort(stalls.begin(), stalls.end());

    // Step 2: Define the search space
    int start = 1;                                   // Minimum possible distance (at least 1)
    int end = stalls[stalls.size() - 1] - stalls[0]; // Maximum possible distance
    int ans = -1;                                    // Variable to store the best result

    // Step 3: Apply Binary Search
    while (start <= end)
    {
        int mid = start + (end - start) / 2; // Calculate the middle distance

        if (isPossible(stalls, k, mid))
        {
            // If possible to place cows at distance `mid`, store answer and check for larger distance
            ans = mid;
            start = mid + 1;
        }
        else
        {
            // If not possible, reduce the distance
            end = mid - 1;
        }
    }

    return ans; // Return the largest minimum distance found
}

int main()
{
    int n, k;

    // Input number of stalls
    cout << "Enter the number of stalls: ";
    cin >> n;
    vector<int> stalls(n);

    // Input stall positions
    cout << "Enter the stall positions: ";
    for (int i = 0; i < n; i++)
    {
        cin >> stalls[i];
    }

    // Input number of cows
    cout << "Enter the number of cows: ";
    cin >> k;

    // Call the function to find the largest minimum distance
    int result = aggressiveCows(stalls, k);

    // Print the result
    cout << "The largest minimum distance is: " << result << endl;

    return 0;
}
