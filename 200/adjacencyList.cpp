#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

// Generic Graph class (template use kiya hai taaki kisi bhi data type ke nodes use kar sake)
template <typename T>
class Graph
{
public:
    // Adjacency List:
    // Key = node
    // Value = us node ke saare neighbouring nodes ki list
    unordered_map<T, list<T>> adj;

    // Function to add edge in graph
    void addEdge(T u, T v, bool direction)
    {
        // u = source node
        // v = destination node
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph

        // Edge from u to v
        adj[u].push_back(v);

        // Agar undirected graph hai to reverse edge bhi add karenge (v -> u)
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    // Function to print adjacency list
    void printAdjList()
    {
        // Loop through each node in map
        for (auto i : adj)
        {
            // i.first = current node
            cout << i.first << " -> ";

            // i.second = list of neighbours of that node
            for (auto j : i.second)
            {
                cout << j << ", ";
            }

            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter the number of nodes" << endl;
    cin >> n;
    // n = total number of nodes (vertices) in the graph

    int m;
    cout << "Enter the number of edges" << endl;
    cin >> m;
    // m = total number of edges (connections between nodes)

    Graph<int> g;

    // Loop to take input of edges
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // u = starting node of edge
        // v = ending node of edge

        // Undirected graph bana rahe hain (0 pass kiya)
        g.addEdge(u, v, 0);
    }

    // Print adjacency list representation of graph
    g.printAdjList();

    return 0;
}

// Input
// Enter the number of nodes
// 5
// Enter the number of edges
// 6
// 0 1
// 1 2
// 2 3
// 3 1
// 3 4
// 0 4

// Output
// 4->3, 0,
// 3->2, 1, 4,
// 2->1, 3,
// 1->0, 2, 3,
// 0->1, 4,