// Leetcode Problem 632. Smallest Range Covering Elements from K Lists

#include <bits/stdc++.h>
using namespace std;

/*
    Node structure:
    - data → actual value
    - row  → kis list (array) se aaya
    - col  → us list me kaunsa index hai
*/
class Node
{
public:
    int data;
    int row;
    int col;

    Node(int d, int r, int c)
    {
        data = d;
        row = r;
        col = c;
    }
};

/*
    Custom comparator for min heap
    - priority_queue by default max heap hota hai
    - yaha hum min heap chahte hain
    - isliye smaller element ko top pe rakhne ke liye > use kiya
*/
class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {

        // mini → current range ka minimum element
        // maxi → current range ka maximum element
        int mini = INT_MAX;
        int maxi = INT_MIN;

        /*
            Min Heap:
            - har list ka current element store karega
            - hamesha smallest element top pe milega
        */
        priority_queue<Node *, vector<Node *>, compare> minHeap;

        int k = nums.size(); // total number of lists

        /*
            Step 1:
            - Har list ka first element heap me daalo
            - Saath hi initial mini aur maxi update karo
        */
        for (int i = 0; i < k; i++)
        {
            int element = nums[i][0];

            maxi = max(element, maxi);
            mini = min(element, mini);

            Node *temp = new Node(element, i, 0);
            minHeap.push(temp);
        }

        // Initial answer range
        int ansStart = mini;
        int ansEnd = maxi;

        /*
            Step 2:
            - Heap se smallest element nikaalo
            - Range update karo
            - Us element ke next element ko same list se push karo
        */
        while (!minHeap.empty())
        {

            Node *top = minHeap.top();
            minHeap.pop();

            int topElement = top->data;
            int topRow = top->row;
            int topCol = top->col;

            // Current minimum update (heap ka top hi smallest hai)
            mini = topElement;

            /*
                Check if current range is better (smaller)
                Agar haan → answer update karo
            */
            if (maxi - mini < ansEnd - ansStart)
            {
                ansStart = mini;
                ansEnd = maxi;
            }

            /*
                Same list ke next element pe move karo
                Agar next exist karta hai to hi push karo
            */
            if (topCol + 1 < nums[topRow].size())
            {

                int nextElement = nums[topRow][topCol + 1];

                // Update maxi agar new element bada hai
                maxi = max(maxi, nextElement);

                Node *newNode = new Node(nextElement, topRow, topCol + 1);
                minHeap.push(newNode);
            }
            else
            {
                /*
                    Agar kisi bhi list ka element khatam ho gaya,
                    to valid range banana possible nahi → break
                */
                break;
            }
        }

        // Final answer return
        return {ansStart, ansEnd};
    }
};

int main()
{
    Solution obj;

    /*
        Test Case:
        Har list sorted hai
        Goal: aisa smallest range find karo jo har list se at least 1 element cover kare
    */
    vector<vector<int>> nums = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}};

    vector<int> result = obj.smallestRange(nums);

    cout << "Smallest Range: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}