// GFG Problem K-th Largest Sum Contiguous Subarray

#include <bits/stdc++.h>
using namespace std;

// Function to find K-th largest subarray sum
class Solution
{
public:
    int kthLargest(vector<int> &arr, int k)
    {

        // Min Heap (size k) → stores k largest sums
        priority_queue<int, vector<int>, greater<int>> mh;

        // Generate all subarrays
        for (int i = 0; i < arr.size(); i++)
        {
            int sum = 0; // running sum for subarray

            for (int j = i; j < arr.size(); j++)
            {
                sum += arr[j]; // add current element

                // If heap size is less than k → directly push
                if (mh.size() < k)
                {
                    mh.push(sum);
                }
                else
                {
                    // If current sum is greater than smallest in heap
                    if (sum > mh.top())
                    {
                        mh.pop();     // remove smallest
                        mh.push(sum); // insert new sum
                    }
                }
            }
        }

        // Top of min heap = k-th largest element
        return mh.top();
    }
};

int main()
{
    Solution obj;

    vector<int> arr = {1, 2, 6, 4, 3};
    int k = 3;

    int result = obj.kthLargest(arr, k);

    cout << "K-th Largest Subarray Sum: " << result << endl;

    return 0;
}