// GFG Problem Bottom View of Binary Tree
// TC → O(N log N) (map insertion)
// SC → O(N) (queue + map)

#include <bits/stdc++.h>
using namespace std;

// Definition of Binary Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        
        // Queue for BFS traversal
        // Stores pair of (Node pointer, Horizontal Distance)
        queue<pair<Node*,int>> q;

        // Map to store latest node at each Horizontal Distance (HD)
        // key = HD, value = node->data
        // NOTE: Bottom view me har HD pe LAST node store karna hai
        map<int,int> m;
        
        // Start with root node at HD = 0
        q.push({root,0});
        
        // Level order traversal (BFS)
        while(q.size() > 0){

            // Get front node and its HD
            Node* curr = q.front().first;
            int currHd = q.front().second;
            
            // IMPORTANT:
            // Har baar overwrite kar rahe hain
            // Isse same HD pe jo last node milega (bottom-most), wahi store hoga
            m[currHd] = curr->data;
            
            // Remove node from queue
            q.pop();
             
            // Push left child with HD - 1
            if(curr->left != NULL){
                q.push({curr->left, currHd - 1});
            }
             
            // Push right child with HD + 1
            if(curr->right != NULL){
                q.push({curr->right, currHd + 1});
            }
        }
        
        // Store result in sorted order of HD (map auto-sorted hota hai)
        vector<int> ans;
        
        for(auto it : m){
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main() {
    /*
            Binary Tree:
            
                1
               / \
              2   3
             / \   \
            4   5   6

        Horizontal Distances:
        4(-2), 2(-1), 1(0), 3(+1), 6(+2)

        Bottom View = 4 2 5 3 6
    */

    // Create tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution obj;

    // Get bottom view
    vector<int> result = obj.bottomView(root);

    // Print result
    cout << "Bottom View: ";
    for(int x : result){
        cout << x << " ";
    }

    return 0;
}