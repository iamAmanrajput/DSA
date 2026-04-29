#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

template <typename T>
class Graph
{
public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool direction)
    {
        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }

    // DFS Helper (Recursive Function)
    void dfsHelper(T node, unordered_map<T, bool> &visited)
    {
        // Step 1: current node ko print karo
        cout << node << " ";

        // Step 2: mark karo visited
        visited[node] = true;

        // Step 3: saare neighbours par jao
        for (auto neighbour : adj[node])
        {
            // Step 4: agar neighbour visit nahi hua hai
            if (!visited[neighbour])
            {
                // Step 5: recursive DFS call
                dfsHelper(neighbour, visited);
            }
        }

        // Base case (implicit):
        // jab koi unvisited neighbour nahi milta,
        // function automatically return ho jata hai
    }

    // DFS Function (handles disconnected graph also)
    void dfs()
    {
        unordered_map<T, bool> visited;

        // Har node ke liye check (important for disconnected graph)
        for (auto i : adj)
        {
            T node = i.first;

            if (!visited[node])
            {
                dfsHelper(node, visited);
            }
        }
    }
};

int main()
{
    int n;
    cout << "Enter the number of nodes" << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges" << endl;
    cin >> m;

    Graph<int> g;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        g.addEdge(u, v, 0);
    }

    g.printAdjList();

    cout << "\nDFS Traversal: ";
    g.dfs();

    return 0;
}