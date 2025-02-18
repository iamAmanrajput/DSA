// EKO PROBLEM --- SPOJ PLATFORM

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossibleSolution(const vector<long long int> &trees, long long int m, long long int mid)
{
    long long int woodCollect = 0;
    for (long long int i = 0; i < trees.size(); i++)
    {
        if (trees[i] > mid)
        { // tree ki height badi hai sawbalde ki height se to wood cut karenge
            woodCollect += (trees[i] - mid);
        }
    }
    return woodCollect >= m; // required wood or cut karke collected wood equal hoga to true warna false
}

int maxSawBladeHeight(const vector<long long int> &trees, long long int m)
{
    long long int start = 0, end, ans = -1;
    end = *max_element(trees.begin(), trees.end());

    while (start <= end)
    {
        long long int mid = start + (end - start) / 2;
        if (isPossibleSolution(trees, m, mid))
        {
            ans = mid;
            start = mid + 1; // Try to maximize the height
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{

    // n = size of array
    //  m = required wood
    long long int n, m;
    cin >> n >> m;
    vector<long long int> trees(n); // Initialize vector with size n

    for (long long int i = 0; i < n; i++)
    {
        cin >> trees[i];
    }

    cout << maxSawBladeHeight(trees, m) << endl;

    return 0;
}

// output

// input
// 4 7
// 20 15 10 17

// ouput
//  15