// 526. Beautiful Arrangement

#include <iostream>
#include <vector>

using namespace std;

// Helper function to count valid arrangements
void countArrangementHelper(vector<int> &v, int n, int &ans, int currNum)
{
    if (currNum == n + 1)
    {
        ans++;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (v[i] == 0 && (currNum % i == 0 || i % currNum == 0))
        { // checks three conditions
            v[i] = currNum;
            countArrangementHelper(v, n, ans, currNum + 1);
            v[i] = 0; // backtrack
        }
    }
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    vector<int> v(n + 1, 0); // index 0 unused
    int ans = 0;

    countArrangementHelper(v, n, ans, 1);

    cout << "Number of beautiful arrangements: " << ans << endl;

    return 0;
}

// Enter a number: 2
// Number of beautiful arrangements: 2
