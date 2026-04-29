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

    // BFS Traversal starting from node 0
    void bfs()
    {
        queue<int> Q;               // Queue for BFS (FIFO)
        vector<bool> vis(V, false); // Visited array

        Q.push(0);     // Start from node 0
        vis[0] = true; // Mark node 0 as visited

        while (!Q.empty())
        {
            int u = Q.front(); // Get front node
            Q.pop();           // Remove it from queue

            cout << u << " "; // Process (print) node

            // Traverse all neighbours of current node
            for (auto v : l[u])
            {
                // If neighbour not visited
                if (!vis[v])
                {
                    vis[v] = true; // Mark visited
                    Q.push(v);     // Add to queue
                }
            }
        }

        cout << endl;
    }
};

int main()
{
    Graph g(5); // Create graph with 5 nodes (0 to 4)

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    // Perform BFS traversal
    g.bfs();

    return 0;
}

// Output:
// 0 1 2 3 4