// Kth Smallest

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int kthSmallest(vector<int> &arr, int k)
    {
        priority_queue<int> pq;

        // Step 1: first k elements ko heap me daalo
        for (int i = 0; i < k; i++)
        {
            pq.push(arr[i]);
        }

        // Step 2: remaining elements ke liye check karo
        for (int i = k; i < arr.size(); i++)
        {
            int element = arr[i];

            // agar current element chhota hai heap ke top se
            if (element < pq.top())
            {
                pq.pop();         // bada element hata do
                pq.push(element); // chhota element daal do
            }
        }

        // Step 3: heap ka top hi kth smallest hoga
        return pq.top();
    }
};

int main()
{
    // Test case 1
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;

    Solution obj;

    // function call
    int result = obj.kthSmallest(arr, k);

    // output print
    cout << "Kth smallest element is: " << result << endl;

    // Expected output:
    // Sorted array: 3, 4, 7, 10, 15, 20
    // 3rd smallest element = 7

    return 0;
}