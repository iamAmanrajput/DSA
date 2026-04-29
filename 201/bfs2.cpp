#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
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

    void bfs(T start)
    {
        unordered_map<T, bool> visited;
        queue<T> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            T node = q.front();
            q.pop();

            cout << node << " ";

            for (auto neighbour : adj[node])
            {
                if (!visited[neighbour])
                {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    Graph<int> g;

    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(2, 4, 0);

    g.bfs(0);

    return 0;
}