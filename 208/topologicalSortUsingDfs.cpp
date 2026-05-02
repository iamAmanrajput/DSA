// Gfg Problem Topological Sort 
// Time Complexity:
// - O(V + E)
// Space Complexity:
// - O(V + E)
#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <stack>
using namespace std;

/*
    Topological Sort using DFS

    Idea:
    - Har node ko DFS se visit karo
    - Jab node ke saare neighbours visit ho jayein,
      tab us node ko stack me push karo
    - Last me stack ko pop karke answer milta hai

    NOTE:
    - Works only for DAG (Directed Acyclic Graph)
*/

class Solution
{
public:
    unordered_map<int, list<int>> adj; // adjacency list

    // DFS helper function
    void helper(int node, vector<bool> &vis, stack<int> &s)
    {
        vis[node] = true; // mark current node as visited

        // traverse all neighbours
        for (auto v : adj[node])
        {
            if (!vis[v])
            {
                helper(v, vis, s);
            }
        }

        // push node after visiting all neighbours (post-order)
        s.push(node);
    }

    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {

        vector<bool> vis(V, false); // visited array
        stack<int> s;               // stack to store topo order
        vector<int> ans;            // final answer

        // Step 1: Build graph (adjacency list)
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v); // directed edge u -> v
        }

        // Step 2: Call DFS for all unvisited nodes
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                helper(i, vis, s);
            }
        }

        // Step 3: Pop from stack to get topological order
        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};

/*
    Time Complexity:
    - O(V + E)
    Explanation:
    - Each vertex visited once → O(V)
    - Each edge explored once → O(E)

    Space Complexity:
    - O(V + E)
    Explanation:
    - Adjacency list → O(E)
    - Visited array → O(V)
    - Stack → O(V)
    - Recursion stack (DFS) → O(V)
*/

int main()
{
    Solution obj;

    int V = 6;

    // edges[u, v] means u -> v
    vector<vector<int>> edges = {
        {5, 0},
        {5, 2},
        {4, 0},
        {4, 1},
        {2, 3},
        {3, 1}};

    vector<int> result = obj.topoSort(V, edges);

    cout << "Topological Sort: ";
    for (auto x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}