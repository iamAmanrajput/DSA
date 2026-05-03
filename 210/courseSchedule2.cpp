// Leetcode Problem 210. Course Schedule II
/*
-------------------------------
TIME & SPACE COMPLEXITY
-------------------------------

Time Complexity:
- Building graph: O(E)
- Cycle detection (DFS): O(V + E)
- Topological sort (DFS): O(V + E)

Overall: O(V + E)

Space Complexity:
- Adjacency list: O(V + E)
- Visited arrays: O(V)
- Recursion stack: O(V)
- Stack for topo sort: O(V)

Overall: O(V + E)
*/

#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM STATEMENT:

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
You are given an array prerequisites where prerequisites[i] = [ai, bi]
indicates that you must take course bi first if you want to take course ai.

Return the ordering of courses you should take to finish all courses.
If there are many valid answers, return any of them.
If it is impossible to finish all courses, return an empty array.
*/

class Solution
{
public:
    unordered_map<int, list<int>> adj;

    // DFS to detect cycle in directed graph
    bool isCycle(int src, vector<bool> &vis, vector<bool> &recPath)
    {
        vis[src] = true;
        recPath[src] = true;

        for (int v : adj[src])
        {
            if (!vis[v])
            {
                if (isCycle(v, vis, recPath))
                {
                    return true;
                }
            }
            else if (recPath[v])
            {
                return true; // cycle found
            }
        }
        recPath[src] = false;
        return false;
    };

    // DFS for Topological Sort
    void topologicalSort(int src, vector<bool> &vis, stack<int> &s)
    {
        vis[src] = true;

        for (int v : adj[src])
        {
            if (!vis[v])
            {
                topologicalSort(v, vis, s);
            }
        }

        // push after visiting all neighbours
        s.push(src);
    };

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<bool> vis(numCourses, false);
        vector<bool> recPath(numCourses, false);
        vector<int> ans;
        stack<int> s;

        // Build graph
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int v = prerequisites[i][0];
            int u = prerequisites[i][1];
            adj[u].push_back(v);
        }

        // Cycle detection
        bool cyclePresent = false;

        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i])
            {
                if (isCycle(i, vis, recPath))
                {
                    cyclePresent = true;
                }
            }
        }

        // If cycle exists, return empty array
        if (cyclePresent)
        {
            return ans;
        };

        // Reset visited for topo sort
        fill(vis.begin(), vis.end(), false);

        // Topological Sort
        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i])
            {
                topologicalSort(i, vis, s);
            }
        }

        // Store result from stack
        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    int numCourses = 4;

    // Example Test Case:
    // To take course 1 -> must take 0
    // To take course 2 -> must take 0
    // To take course 3 -> must take 1 and 2
    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 0},
        {3, 1},
        {3, 2}};

    vector<int> result = obj.findOrder(numCourses, prerequisites);

    // Print result
    if (result.size() == 0)
    {
        cout << "Cycle detected. No valid ordering possible.\n";
    }
    else
    {
        cout << "Course Order: ";
        for (int x : result)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}