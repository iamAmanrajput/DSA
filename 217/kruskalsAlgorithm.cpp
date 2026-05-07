// Scratch Implementation of Kruskal's Algorithm
// TC of Kruskal's Algorithm = 0(E log E) -> sorting edges
// SC = O(V + E)

#include <iostream>
#include <vector>
#include <algorithm> // for sort()
using namespace std;

// Edge class
// Stores source node(u), destination node(v), and weight(wt)
class Edge
{
public:
    int u, v, wt;

    // Constructor
    Edge(int u, int v, int wt)
    {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }

    // Comparator for sorting edges according to weight
    bool operator<(const Edge &other)
    {
        return this->wt < other.wt;
    }
};

class Graph
{
public:
    int V; // total vertices

    vector<Edge> edges;

    // DSU Arrays
    vector<int> par, rank;

    // Constructor
    Graph(int V)
    {
        this->V = V;

        // Initially every node is its own parent
        // Rank = 0
        for (int i = 0; i < V; i++)
        {
            par.push_back(i);
            rank.push_back(0);
        }
    }

    // Add edge in graph
    void addEdge(int u, int v, int wt)
    {
        edges.push_back(Edge(u, v, wt));
    }

    // Find function with Path Compression
    // Finds ultimate parent of node
    int find(int x)
    {
        // If node is parent of itself
        if (par[x] == x)
        {
            return x;
        }

        // Path Compression
        return par[x] = find(par[x]);
    }

    // Union By Rank
    // Combines two sets
    void unionByRank(int a, int b)
    {
        int parA = find(a);
        int parB = find(b);

        // If already in same set
        if (parA == parB)
            return;

        // If ranks are same
        // Make one parent of another and increase rank
        if (rank[parA] == rank[parB])
        {
            par[parB] = parA;
            rank[parA]++;
        }

        // Higher rank becomes parent
        else if (rank[parA] > rank[parB])
        {
            par[parB] = parA;
        }
        else
        {
            par[parA] = parB;
        }
    }

    // Kruskal's Algorithm
    // Finds Minimum Spanning Tree(MST)
    void kruskal()
    {
        // Sort edges according to weight
        sort(edges.begin(), edges.end());

        int mstCost = 0;
        int count = 0;

        // Traverse all edges
        for (int i = 0; i < edges.size() && count < V - 1; i++)
        {
            Edge e = edges[i];

            int parU = find(e.u);
            int parV = find(e.v);

            // If parents are different
            // then no cycle exists
            if (parU != parV)
            {
                unionByRank(e.u, e.v);

                mstCost += e.wt;
                count++;

                // Printing selected edge
                cout << e.u << " - " << e.v
                     << " : " << e.wt << endl;
            }
        }

        cout << "MST Cost: " << mstCost << endl;
    }
};

int main()
{
    Graph graph(4);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);

    graph.kruskal();

    return 0;
}

/*
Output:

2 - 3 : 4
0 - 3 : 5
0 - 1 : 10
MST Cost: 19

*/