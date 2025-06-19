// OPTIMIZED WAY OF N QUEEN PROBLEM USING UNORDERED_MAP -- (LC)

// N Quen Problem --(LC)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, bool> rowCheck;
unordered_map<int, bool> upperLeftDiagonalCheck;
unordered_map<int, bool> bottomLeftDiagonalCheck;

void printSol(vector<vector<char>> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int row, int col, vector<vector<char>> &board, int n)
{
    // checking , can i place queen in current cell
    if (rowCheck[row] == true)
    {
        return false;
    }
    if (upperLeftDiagonalCheck[n - 1 + col - row] == true)
    {
        return false;
    }
    if (bottomLeftDiagonalCheck[row + col] == true)
    {
        return false;
    }
    return true;
}

void solve(vector<vector<char>> &board, int col, int n)
{
    // base
    if (col >= n)
    {
        printSol(board, n);
        return;
    }

    // handling 1 condition
    // trying to place queen in every position in a row
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            // place the queen
            board[row][col] = 'Q';
            rowCheck[row] = true;
            upperLeftDiagonalCheck[n - 1 + col - row] = true;
            bottomLeftDiagonalCheck[row + col] = true;
            // recurion call for next queen place in next col
            solve(board, col + 1, n);
            // backtracking
            board[row][col] = '-';
            rowCheck[row] = false;
            upperLeftDiagonalCheck[n - 1 + col - row] = false;
            bottomLeftDiagonalCheck[row + col] = false;
        }
    }
}

int main()
{
    int n = 4;
    // making empty board of nxn
    vector<vector<char>> board(n, vector<char>(n, '-'));
    int col = 0;
    // - -> empty cell
    // Q -> Queen at a cell
    solve(board, col, n);
    return 0;
}

// output
// - - Q -
// Q - - -
// - - - Q
// - Q - -

// - Q - -
// - - - Q
// Q - - -
// - - Q -