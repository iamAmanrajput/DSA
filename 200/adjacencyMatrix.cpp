#include <iostream>
#include <vector>
using namespace std;

class Graph
{
public:
    int totalNodes;             // total number of vertices (nodes)
    vector<vector<int>> matrix; // adjacency matrix

    // Constructor to initialize graph
    Graph(int nodesCount)
    {
        totalNodes = nodesCount;

        // Create a nodesCount x nodesCount matrix filled with 0
        // 0 means no edge exists between nodes
        matrix.resize(totalNodes, vector<int>(totalNodes, 0));
    }

    // Function to add edge between two nodes
    void addEdge(int source, int destination, bool isDirected)
    {
        // source = starting node
        // destination = ending node
        // isDirected = true (directed graph), false (undirected graph)

        // Add edge from source to destination
        matrix[source][destination] = 1;

        // If graph is undirected, also add reverse edge
        if (!isDirected)
        {
            matrix[destination][source] = 1;
        }
    }

    // Function to print adjacency matrix
    void printAdjacencyMatrix()
    {
        cout << "\nAdjacency Matrix:\n";

        for (int row = 0; row < totalNodes; row++)
        {
            for (int col = 0; col < totalNodes; col++)
            {
                cout << matrix[row][col] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int numberOfNodes;
    cout << "Enter number of nodes: ";
    cin >> numberOfNodes;

    int numberOfEdges;
    cout << "Enter number of edges: ";
    cin >> numberOfEdges;

    // Create graph object
    Graph graph(numberOfNodes);

    // Input edges
    for (int edgeIndex = 0; edgeIndex < numberOfEdges; edgeIndex++)
    {
        int sourceNode, destinationNode;
        cin >> sourceNode >> destinationNode;

        // false = undirected graph
        graph.addEdge(sourceNode, destinationNode, false);
    }

    // Print adjacency matrix
    graph.printAdjacencyMatrix();

    return 0;
}

/*

================= SAMPLE INPUT =================
Enter number of nodes: 4
Enter number of edges: 3
0 1
1 2
2 3

================= EXPECTED OUTPUT =================

Adjacency Matrix:
0 1 0 0
1 0 1 0
0 1 0 1
0 0 1 0

==================================================
Explanation:
- 0 connected to 1
- 1 connected to 0 and 2
- 2 connected to 1 and 3
- 3 connected to 2
*/