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

    void dfsHelper(int u, vector<bool> &vis)
    {
        // Step 1: Current node ko visit karo
        cout << u << " ";

        // Step 2: Mark karo ki ye node visit ho chuka hai
        vis[u] = true;

        // Step 3: Is node ke saare neighbors traverse karo
        for (int v : l[u])
        {
            // Step 4: Agar neighbor visit nahi hua hai
            if (!vis[v])
            {
                // Step 5: Us neighbor par recursive DFS call karo
                dfsHelper(v, vis);
            }
        }

        // Base case (implicit):
        // Jab saare neighbors visit ho jaate hain,
        // koi recursive call nahi hoti aur function return ho jata hai
    }

    void dfs()
    {
        int src = 0;
        vector<bool> vis(V, false);
        dfsHelper(0, vis);
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

    // Perform DFS traversal
    g.dfs();

    return 0;
}

// Output:
// 0 1 2 4 3