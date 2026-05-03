// Dijkstra Algorithm - Greedy Method and using BFS
// TC O( ( V + E ) log V)
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <limits.h>
using namespace std;

// Edge class: stores neighbour node and weight
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

// Dijkstra Algorithm (Greedy + Priority Queue)
void dijkastra(int src, vector<vector<Edge>> g, int V)
{
    // Step 1: Initialize distance array
    // Initially sab nodes ka distance infinite
    vector<int> dist(V, INT_MAX);

    // Source ka distance 0 hota hai
    dist[src] = 0;

    // Min Heap (Priority Queue)
    // stores pair: {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Push source node
    pq.push({0, src});

    // Step 2: Process nodes
    while (!pq.empty())
    {
        // Get node with minimum distance
        int u = pq.top().second;
        pq.pop();

        // Traverse all neighbours of u
        for (Edge e : g[u])
        {
            // Edge Relaxation
            // Check if better path exists via u
            if (dist[e.v] > dist[u] + e.wt)
            {
                // Update shortest distance
                dist[e.v] = dist[u] + e.wt;

                // Push updated distance into PQ
                pq.push({dist[e.v], e.v});
            }
        }
    }

    // Step 3: Print shortest distances from source
    for (int i = 0; i < V; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main()
{
    int V = 6;

    // Adjacency List (Weighted Graph)
    vector<vector<Edge>> g(V);

    // Adding edges (u -> v, weight)
    g[0].push_back(Edge(1, 2));
    g[0].push_back(Edge(2, 4));

    g[1].push_back(Edge(2, 1));
    g[1].push_back(Edge(3, 7));

    g[2].push_back(Edge(4, 3));

    g[3].push_back(Edge(5, 1));

    g[4].push_back(Edge(3, 2));
    g[4].push_back(Edge(5, 5));

    // Run Dijkstra from source node 0
    dijkastra(0, g, V);

    return 0;
}

// 0 2 3 8 6 9