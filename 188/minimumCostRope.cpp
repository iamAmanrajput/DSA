// Minimum Cost of ropes


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int minCost(vector<int> &arr)
    {
        // Min heap to always get the two smallest elements
        priority_queue<int, vector<int>, greater<int>> pq;

        // Push all elements into the min heap
        for (int i = 0; i < arr.size(); i++)
        {
            pq.push(arr[i]);
        }

        int ans = 0;

        // Keep combining until only one element remains
        while (pq.size() > 1)
        {
            // Get two smallest elements
            int a = pq.top();
            pq.pop();

            int b = pq.top();
            pq.pop();

            // Combine them
            int sum = a + b;

            // Add to total cost
            ans += sum;

            // Push the combined element back into heap
            pq.push(sum);
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    // Test Case 1
    vector<int> arr1 = {4, 3, 2, 6};
    cout << "Minimum cost (Test 1): " << obj.minCost(arr1) << endl;

    // Test Case 2
    vector<int> arr2 = {1, 2, 3, 4, 5};
    cout << "Minimum cost (Test 2): " << obj.minCost(arr2) << endl;

    // Test Case 3 (edge case: single element)
    vector<int> arr3 = {10};
    cout << "Minimum cost (Test 3): " << obj.minCost(arr3) << endl;

    // Test Case 4 (all same values)
    vector<int> arr4 = {5, 5, 5, 5};
    cout << "Minimum cost (Test 4): " << obj.minCost(arr4) << endl;

    return 0;
}