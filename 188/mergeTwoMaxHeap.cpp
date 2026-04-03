// GFG Problem Merge two binary Max heaps


#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // iterative heapify function (max heap)
    void heapify(vector<int> &arr, int index)
    {
        int n = arr.size();

        while (true)
        {
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            // check left child
            if (left < n && arr[left] > arr[largest])
            {
                largest = left;
            }

            // check right child
            if (right < n && arr[right] > arr[largest])
            {
                largest = right;
            }

            // agar already correct position par hai to break
            if (largest == index)
                break;

            // swap and move downward
            swap(arr[index], arr[largest]);
            index = largest;
        }
    }

    // function to merge two max heaps
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {

        vector<int> ans;

        // Step 1: first heap copy karo
        for (int i = 0; i < a.size(); i++)
        {
            ans.push_back(a[i]);
        }

        // Step 2: second heap copy karo
        for (int i = 0; i < b.size(); i++)
        {
            ans.push_back(b[i]);
        }

        // Step 3: build max heap using bottom-up heapify
        int size = ans.size();

        // last non-leaf node se start
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(ans, i);
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    // Test case 1
    vector<int> heap1 = {10, 5, 6, 2};
    vector<int> heap2 = {12, 7, 9};

    vector<int> result = obj.mergeHeaps(heap1, heap2, heap1.size(), heap2.size());

    cout << "Merged Max Heap: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    // Expected:
    // Output ek valid max heap hoga (order fixed nahi hota)
    // Example: 12 10 9 2 5 7 6

    // Test case 2
    vector<int> heap3 = {50, 30, 40};
    vector<int> heap4 = {20, 10, 35};

    vector<int> result2 = obj.mergeHeaps(heap3, heap4, heap3.size(), heap4.size());

    cout << "Merged Max Heap: ";
    for (int val : result2)
    {
        cout << val << " ";
    }
    cout << endl;

    // Expected:
    // Valid max heap, example: 50 30 40 20 10 35

    return 0;
}