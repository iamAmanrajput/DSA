// cycle detection in undirected graph using BFS
#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph
{
    int V;        // Total number of vertices (nodes)
    list<int> *l; // Adjacency list

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    // Add edge (undirected)
    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    // BFS Cycle Detection
    // BFS based cycle detection in undirected graph
    bool isCycleUndirectedbfs(int src, vector<bool> &vis)
    {
        // Queue will store {current_node, parent_node}
        // Parent is important to avoid false cycle detection
        queue<pair<int, int>> Q;

        // Start BFS from source node
        Q.push({src, -1}); // src ka parent -1 (no parent)
        vis[src] = true;   // mark source as visited

        // Standard BFS loop
        while (!Q.empty())
        {
            int u = Q.front().first;       // current node
            int parent = Q.front().second; // parent of current node
            Q.pop();

            // Traverse all neighbours of current node
            for (auto v : l[u])
            {
                // Case 1: If neighbour is NOT visited
                if (!vis[v])
                {
                    vis[v] = true;  // mark visited
                    Q.push({v, u}); // push neighbour with current as parent
                }
                // Case 2: If neighbour is already visited
                // and it is NOT the parent → cycle exists
                else if (v != parent)
                {
                    return true;
                }
            }
        }

        // If BFS completes without finding cycle
        return false;
    }

    bool isCycle()
    {
        vector<bool> vis(V, false);

        // Handle disconnected graph
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (isCycleUndirectedbfs(i, vis))
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
    cout << "===== TEST CASE 1: Graph WITH cycle =====\n";

    Graph g1(5);

    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(2, 3); // cycle here
    g1.addEdge(2, 4);

    if (g1.isCycle())
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";

    cout << "\n===== TEST CASE 2: Graph WITHOUT cycle =====\n";

    Graph g2(5);

    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.addEdge(3, 4);

    if (g2.isCycle())
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";

    return 0;
}