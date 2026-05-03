// Kahn's Algorithm for finding Topological sort using BFS
#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph
{
    int V;        // Number of vertices (nodes)
    list<int> *l; // Adjacency list

public:
    // Constructor: initialize graph with V vertices
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V]; // create array of lists
    }

    // Function to add directed edge u -> v
    void addEdge(int u, int v)
    {
        l[u].push_back(v); // only directed edges
    }

    // Kahn's Algorithm (BFS based Topological Sort)
    void topoSort()
    {
        vector<int> res; // stores final topological order

        // Step 1: Calculate indegree of each node
        // indegree = number of incoming edges
        vector<int> indeg(V, 0);

        for (int u = 0; u < V; u++)
        {
            for (int v : l[u])
            {
                indeg[v]++; // increase indegree of neighbour
            }
        }

        // Step 2: Push all nodes with indegree = 0 into queue
        // These nodes have no dependencies
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }

        // Step 3: BFS Traversal
        while (q.size() > 0)
        {
            int curr = q.front(); // get front node
            q.pop();

            res.push_back(curr); // add to result

            // Traverse all neighbours
            for (int v : l[curr])
            {
                indeg[v]--; // remove dependency

                // If indegree becomes 0, push into queue
                if (indeg[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        // Step 4: Print result (Topological Order)
        for (int val : res)
        {
            cout << val << " ";
        }
    }
};

int main()
{
    Graph g(6); // Graph with 6 nodes (0 to 5)

    // Adding edges (Directed Graph)
    g.addEdge(3, 1);
    g.addEdge(2, 3);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(5, 0);
    g.addEdge(5, 2);

    // Perform Topological Sort
    g.topoSort();

    return 0;
}