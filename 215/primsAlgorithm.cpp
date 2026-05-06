// Prim's Algorithm Implementation

// ===========================
// Time Complexity (TC):
// ===========================
// -> O(E log E)
//    (Priority Queue operations)

// ===========================
// Space Complexity (SC):
// ===========================
// -> O(V + E)

#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

/*
    Prim's Algorithm (Using Min Heap / Priority Queue)

    Purpose:
    -> Minimum Spanning Tree (MST) ka total minimum cost nikalna

    Idea:
    -> Kisi bhi ek node se start karo (yaha 0 se)
    -> Har step pe minimum weight wali edge choose karo
    -> Jo node MST me nahi hai usko add karo
*/

int primMST(int V, vector<vector<pair<int, int>>> adj)
{
    // Track karega kaunse nodes MST me already included hain
    vector<bool> inMst(V, false);

    // Min Heap (Priority Queue)
    // pair<weight, node>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int minCost = 0; // Final MST ka cost

    // Start from node 0 with weight 0
    pq.push({0, 0}); // {weight, source}

    // Jab tak heap empty nahi hota
    while (!pq.empty())
    {
        auto p = pq.top(); // minimum weight wali entry
        pq.pop();

        int wt = p.first; // edge weight
        int u = p.second; // current node

        // Agar node already MST me include nahi hai
        if (!inMst[u])
        {
            inMst[u] = true; // mark as visited
            minCost += wt;   // cost add karo

            // Ab us node ke neighbors check karo
            for (int i = 0; i < adj[u].size(); i++)
            {
                int v = adj[u][i].first;  // neighbor node
                int w = adj[u][i].second; // weight

                // Sirf un nodes ko push karo jo MST me nahi hai
                if (!inMst[v])
                {
                    pq.push({w, v});
                }
            }
        }
    }

    return minCost;
}

int main()
{
    int V = 4;

    // Adjacency List (vector of vector of pair)
    // pair = {neighbor, weight}
    vector<vector<pair<int, int>>> adj(V);

    // Undirected Weighted Graph
    // Har edge ko dono direction me add karna padta hai

    adj[0].push_back({1, 10});
    adj[1].push_back({0, 10});

    adj[0].push_back({3, 30});
    adj[3].push_back({0, 30});

    adj[0].push_back({2, 15});
    adj[2].push_back({0, 15});

    adj[1].push_back({3, 40});
    adj[3].push_back({1, 40});

    adj[2].push_back({3, 50});
    adj[3].push_back({2, 50});

    // Output MST cost
    cout << "Minimum cost of MST = " << primMST(V, adj) << endl;

    return 0;
}

/*
===========================
Important Points:
===========================
-> Greedy Algorithm hai
-> Cycle avoid karta hai (visited array se)
-> Minimum Spanning Tree banata hai
-> Connected graph hona chahiye

===========================
Expected Output:
===========================
Minimum cost of MST = 55

(Edges selected: 0-1 (10), 0-2 (15), 0-3 (30))
*/