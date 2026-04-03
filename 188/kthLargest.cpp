// Leetcode Problem 215. Kth Largest Element in an Array

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;

        // Step 1: first k elements ko min heap me daalo
        for (int i = 0; i < k; i++)
        {
            pq.push(nums[i]);
        }

        // Step 2: remaining elements ke liye check karo
        for (int i = k; i < nums.size(); i++)
        {
            int element = nums[i];

            // agar current element heap ke top se bada hai
            if (element > pq.top())
            {
                pq.pop();         // chhota element hata do
                pq.push(element); // bada element daal do
            }
        }

        // Step 3: heap ka top hi kth largest hoga
        return pq.top();
    }
};

int main()
{
    // Test case 1
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    Solution obj;

    // function call
    int result = obj.findKthLargest(nums, k);

    // output print
    cout << "Kth largest element is: " << result << endl;

    // Expected output:
    // Sorted array: 1, 2, 3, 4, 5, 6
    // 2nd largest element = 5

    // Test case 2
    vector<int> nums2 = {7, 10, 4, 3, 20, 15};
    int k2 = 3;

    int result2 = obj.findKthLargest(nums2, k2);

    cout << "Kth largest element is: " << result2 << endl;

    // Expected output:
    // Sorted array: 3, 4, 7, 10, 15, 20
    // 3rd largest element = 10

    return 0;
}