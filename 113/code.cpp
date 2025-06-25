// Count Inversion -- Hacker Rank
//  # Approach 1
// TC - (N^2)

#include <iostream>
#include <vector>
using namespace std;

long countInversions(vector<int> arr)
{
    long count = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                count++;
            }
        }
    }

    return count;
}

int main()
{
    vector<int> arr = {2, 1, 3, 1, 2};
    long result = countInversions(arr);
    cout << result << endl; // Output: 4
    return 0;
}
