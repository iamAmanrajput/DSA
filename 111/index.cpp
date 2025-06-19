// N Quen Problem --(LC)

#include <iostream>
#include <vector>
using namespace std;

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
    int i = row;
    int j = col;

    // check row
    while (j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        j--;
    }

    // check upper left diagonal
    i = row;
    j = col;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        j--;
        i--;
    }

    // check bottom left diagonal
    i = row;
    j = col;
    while (i < n && j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        j--;
        i++;
    }

    // if queen not found , then we can place the queen
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
            // recurion call for next queen place in next col
            solve(board, col + 1, n);
            // backtracking
            board[row][col] = '-';
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