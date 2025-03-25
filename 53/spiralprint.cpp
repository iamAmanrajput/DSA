// Spiral print a matrix

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> arr = {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18},
        {19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30}};

    int startingrow = 0;
    int startingcol = 0;
    int endingrow = arr.size() - 1;    // 4
    int endingcol = arr[0].size() - 1; // 5

    int count = 0;
    int totalelement = arr.size() * arr[0].size();
    vector<int> ans;

    while (count < totalelement)
    {
        // Print starting row
        for (int i = startingcol; i <= endingcol && count < totalelement; i++)
        {
            ans.push_back(arr[startingrow][i]);
            count++;
        }
        startingrow++;

        // Print ending column
        for (int i = startingrow; i <= endingrow && count < totalelement; i++)
        {
            ans.push_back(arr[i][endingcol]);
            count++;
        }
        endingcol--;

        // Print ending row
        for (int i = endingcol; i >= startingcol && count < totalelement; i--)
        {
            ans.push_back(arr[endingrow][i]);
            count++;
        }
        endingrow--;

        // Print starting column
        for (int i = endingrow; i >= startingrow && count < totalelement; i--)
        {
            ans.push_back(arr[i][startingcol]);
            count++;
        }
        startingcol++;
    }

    // Print the spiral order
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
