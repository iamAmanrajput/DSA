// Scratch Implementation of Disjoint Set Union
#include <iostream>
#include <vector>
using namespace std;

class DisjointSetUnion
{
public:
    int n;

    // par -> stores parent of each node
    // rank -> stores height/rank of each set
    vector<int> par, rank;

    // Constructor
    DisjointSetUnion(int n)
    {
        this->n = n;

        // Initially every node is parent of itself
        // and rank is 0
        for (int i = 0; i < n; i++)
        {
            par.push_back(i);
            rank.push_back(0);
        }
    }

    // Union By Rank
    // Used to merge two sets
    void unionByRank(int a, int b)
    {
        // Find ultimate parent of both nodes
        int parA = find(a);
        int parB = find(b);

        // If both belong to same set
        // no need to merge
        if (parA == parB)
            return;

        // Case-1:
        // If both sets have same rank
        // make one parent of another
        // and increase its rank
        if (rank[parA] == rank[parB])
        {
            par[parB] = parA;
            rank[parA]++;
        }

        // Case-2:
        // Parent having greater rank
        // becomes ultimate parent
        else if (rank[parA] > rank[parB])
        {
            par[parB] = parA;
        }

        // Case-3:
        // parB has greater rank
        else
        {
            par[parA] = parB;
        }
    }

    // Find Function
    // Returns ultimate parent of a node
    int find(int x)
    {
        // If node is parent of itself
        // then it is ultimate parent
        if (par[x] == x)
        {
            return x;
        }

        // Path Compression:
        // Directly connect node with
        // its ultimate parent
        return par[x] = find(par[x]);
    }

    // Function to print parent and rank array
    void getInfo()
    {
        // Print parent array
        for (int i = 0; i < n; i++)
        {
            cout << par[i] << " ";
        }
        cout << endl;

        // Print rank array
        for (int i = 0; i < n; i++)
        {
            cout << rank[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    // Create DSU of size 6
    DisjointSetUnion dsu(6);

    // Merge 0 and 2
    dsu.unionByRank(0, 2);

    // Print ultimate parent of 2
    cout << dsu.find(2) << endl;

    // Merge 1 and 3
    dsu.unionByRank(1, 3);

    // Merge 2 and 5
    dsu.unionByRank(2, 5);

    // Merge sets of 0 and 3
    dsu.unionByRank(0, 3);

    // Print ultimate parent of 2
    cout << dsu.find(2) << endl;

    // Merge 0 and 4
    dsu.unionByRank(0, 4);

    // Print parent and rank arrays
    dsu.getInfo();

    return 0;
}

// Output
// 0
// 0
// 0
// 0 0 0 1 0 0
// 2 1 0 0 0 0