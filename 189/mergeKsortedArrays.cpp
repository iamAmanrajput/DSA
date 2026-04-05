// GFG Problem Merge k Sorted Arrays

#include <bits/stdc++.h>
using namespace std;

// Node class to store:
// data → value
// i → row index
// j → column index
class Node
{
public:
    int data;
    int i;
    int j;

    // Constructor to initialize node
    Node(int data, int row, int col)
    {
        this->data = data; // store value
        this->i = row;     // store row index
        this->j = col;     // store column index
    }
};

// Comparator for min heap
// Smallest element will come at top
class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data; // min heap
    }
};

class Solution
{
public:
    vector<int> mergeArrays(vector<vector<int>> &mat)
    {

        int k = mat.size(); // number of rows
        vector<int> ans;    // final merged sorted array

        // Min heap (stores Node*)
        priority_queue<Node *, vector<Node *>, compare> minHeap;

        // Step 1: Insert first element of each row into heap
        for (int i = 0; i < k; i++)
        {
            Node *temp = new Node(mat[i][0], i, 0);
            minHeap.push(temp);
        }

        // Step 2: Process heap
        while (!minHeap.empty())
        {

            // Get smallest element
            Node *temp = minHeap.top();
            minHeap.pop();

            // Add to answer
            ans.push_back(temp->data);

            int i = temp->i;
            int j = temp->j;

            // If next element exists in same row, push it
            if (j + 1 < mat[i].size())
            {
                Node *newNode = new Node(mat[i][j + 1], i, j + 1);
                minHeap.push(newNode);
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    // Test case
    vector<vector<int>> mat = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}};

    vector<int> result = obj.mergeArrays(mat);

    cout << "Merged Sorted Array: ";
    for (int x : result)
    {
        cout << x << " ";
    }

    return 0;
}

// Merged Sorted Array: 1 2 3 4 5 6 7 8 9