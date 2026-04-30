#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph
{
    int V;        // Total number of vertices (nodes)
    list<int> *l; // Adjacency list (array of linked lists)

public:
    // Constructor: initialize graph with V vertices
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V]; // create array of lists
    }

    // Function to add edge (undirected graph)
    void addEdge(int u, int v)
    {
        l[u].push_back(v); // edge u -> v
        l[v].push_back(u); // edge v -> u (undirected)
    }

    // DFS helper to detect cycle
    bool isCycleUndirectedDfs(int src, int parent, vector<bool> &vis)
    {
        vis[src] = true;
        list<int> neighbours = l[src];

        for (int v : neighbours)
        {
            if (!vis[v])
            {
                if (isCycleUndirectedDfs(v, src, vis))
                {
                    return true;
                }
            }
            else if (v != parent) // visited and not parent -> cycle
            {
                return true;
            }
        }
        return false;
    }

    // Function to check cycle in whole graph
    bool isCycle()
    {
        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (isCycleUndirectedDfs(i, -1, vis))
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
    // -------- TEST CASE 1 (No Cycle) --------
    Graph g1(5);

    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(2, 4);

    cout << "Graph 1 has cycle? ";
    if (g1.isCycle())
        cout << "Yes\n";
    else
        cout << "No\n";

    // -------- TEST CASE 2 (With Cycle) --------
    Graph g2(5);

    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.addEdge(3, 0); // creates cycle
    g2.addEdge(3, 4);

    cout << "Graph 2 has cycle? ";
    if (g2.isCycle())
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}

/*
Expected Output:
Graph 1 has cycle? No
Graph 2 has cycle? Yes
*/