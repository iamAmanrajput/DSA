// Bellman Ford Algorithm
// TC 0( V * E )
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Edge class: represents a directed edge u -> v with weight wt
class Edge
{
public:
    int v;  // destination node
    int wt; // weight of edge

    Edge(int v, int wt)
    {
        this->v = v;
        this->wt = wt;
    }
};

// Bellman-Ford function to find shortest distance from source
void bellmanFord(int src, vector<vector<Edge>> &g, int V)
{
    // Step 1: Initialize distance array
    vector<int> dist(V, INT_MAX);
    dist[src] = 0; // distance to source is always 0

    // Step 2: Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++)
    {
        for (int u = 0; u < V; u++) // iterate over all vertices
        {
            for (Edge e : g[u]) // iterate over all edges from u
            {
                // Relaxation condition
                // IMPORTANT: check dist[u] != INT_MAX to avoid overflow
                if (dist[u] != INT_MAX && dist[e.v] > dist[u] + e.wt)
                {
                    dist[e.v] = dist[u] + e.wt;
                }
            }
        }
    }

    // Step 3 (optional but important): Detect negative weight cycle
    for (int u = 0; u < V; u++)
    {
        for (Edge e : g[u])
        {
            if (dist[u] != INT_MAX && dist[e.v] > dist[u] + e.wt)
            {
                cout << "Negative weight cycle detected!" << endl;
                return;
            }
        }
    }

    // Step 4: Print shortest distances from source
    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < V; i++)
    {
        cout << "Node " << i << " -> " << dist[i] << endl;
    }
}

int main()
{
    int V = 5;

    // Adjacency list representation
    vector<vector<Edge>> g(V);

    // Adding edges (directed graph)
    g[0].push_back(Edge(1, 2));
    g[0].push_back(Edge(2, 4));

    g[1].push_back(Edge(4, -1));
    g[1].push_back(Edge(2, -4));

    g[2].push_back(Edge(3, 2));

    g[3].push_back(Edge(4, 4));

    // Call Bellman-Ford from source node 0
    bellmanFord(0, g, V);

    return 0;
}

// 0 2 -2 0 1