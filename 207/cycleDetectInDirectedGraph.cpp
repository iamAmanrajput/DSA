// Cycle Detection in Directed Graph using DFS
// Time Complexity : O(V + E)
// Space Complexity: O(V)

#include <iostream>
#include <vector>
#include <list>
using namespace std;

/*
Approach:
- Directed graph me cycle detect karne ke liye DFS use karte hain
- 2 arrays use karte hain:
    1. vis[] → node visited hai ya nahi
    2. recPath[] → current recursion path (DFS stack)

- Agar DFS ke dauran koi node dubara milta hai
  aur wo current recursion path me hai → cycle present

Time Complexity: O(V + E)
- V = vertices, E = edges
- Har node aur edge ek baar traverse hota hai

Space Complexity: O(V)
- vis[] + recPath[] + recursion stack
*/

class Graph
{
    int V;        // Total number of vertices (nodes)
    list<int> *l; // Adjacency list

public:
    // Constructor
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    // Add directed edge u → v
    void addEdge(int u, int v)
    {
        l[u].push_back(v);
    }

    // DFS function to detect cycle
    bool isCycleDirectedDFS(int curr, vector<bool> &vis, vector<bool> &recPath)
    {
        vis[curr] = true;     // mark visited
        recPath[curr] = true; // mark in current path

        // traverse all neighbors
        for (int v : l[curr])
        {
            // if not visited → DFS call
            if (!vis[v])
            {
                if (isCycleDirectedDFS(v, vis, recPath))
                {
                    return true;
                }
            }
            // if visited and in recursion path → cycle found
            else if (recPath[v])
            {
                return true;
            }
        }

        recPath[curr] = false; // backtrack (remove from path)
        return false;
    }

    // Function to check cycle in whole graph
    bool isCycle()
    {
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        // check all components
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (isCycleDirectedDFS(i, vis, recPath))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    Graph g(5); // nodes: 0 to 4

    // Test Case:
    // 1 → 0 → 2 → 3 → 0 (cycle present)
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);

    if (g.isCycle())
    {
        cout << "Cycle Detected" << endl;
    }
    else
    {
        cout << "No Cycle" << endl;
    }

    return 0;
}