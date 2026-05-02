// Leetcode Problem 207. Course Schedule
// Using Dfs cycle detection approach
// Time Complexity: O(V + E)
// Space Complexity : O(V + E)

#include <iostream>
#include <vector>
using namespace std;

/*
    Problem: Course Schedule (LeetCode 207)

    Idea:
    - Graph banao (adjacency list)
    - DFS use karke cycle detect karo
    - Agar cycle milti hai → courses complete nahi ho sakte (return false)
    - Agar cycle nahi → possible (return true)

    Technique:
    - vis[] → visited nodes track karega
    - recPath[] → current recursion stack track karega
*/

class Solution
{
public:
    // DFS function to detect cycle in directed graph
    bool isCycleDFS(int src, vector<bool> &vis, vector<bool> &recPath,
                    vector<vector<int>> &adj)
    {

        vis[src] = true;     // mark node visited
        recPath[src] = true; // mark in current recursion path

        // traverse all neighbours
        for (auto v : adj[src])
        {

            // agar neighbour visited nahi hai → DFS call
            if (!vis[v])
            {
                if (isCycleDFS(v, vis, recPath, adj))
                {
                    return true; // cycle found
                }
            }
            // agar neighbour recursion stack me hai → cycle
            else if (recPath[v])
            {
                return true;
            }
        }

        recPath[src] = false; // backtrack (remove from path)
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        // Step 1: Build adjacency list
        vector<vector<int>> adj(numCourses);

        // p = [a, b] → b -> a
        for (auto &p : prerequisites)
        {
            int a = p[0];
            int b = p[1];
            adj[b].push_back(a);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> recPath(numCourses, false);

        // Step 2: Check cycle in each component
        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i])
            {
                if (isCycleDFS(i, vis, recPath, adj))
                {
                    return false; // cycle present
                }
            }
        }

        return true; // no cycle → all courses possible
    }
};

/*
    Time Complexity: O(V + E)
    - Har node ek baar visit hota hai → O(V)
    - Har edge ek baar traverse hoti hai → O(E)

    Space Complexity: O(V + E)
    - Adjacency list → O(E)
    - vis + recPath → O(V)
    - Recursion stack → O(V)
*/

int main()
{

    Solution obj;

    // Test Case 1 (Valid - No cycle)
    int numCourses1 = 2;
    vector<vector<int>> prerequisites1 = {
        {1, 0}};

    cout << "Test Case 1: "
         << (obj.canFinish(numCourses1, prerequisites1) ? "true" : "false")
         << endl;

    // Test Case 2 (Invalid - Cycle present)
    int numCourses2 = 2;
    vector<vector<int>> prerequisites2 = {
        {1, 0},
        {0, 1}};

    cout << "Test Case 2: "
         << (obj.canFinish(numCourses2, prerequisites2) ? "true" : "false")
         << endl;

    return 0;
}