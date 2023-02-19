#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach) */
bool isSafe(int row, int col, vector<string> &board, int n)
{
    // keep duplicate row and col value
    int dupRow = row;
    int dupCol = col;

    // left upper diagonal
    while (row >= 0 and col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    // left direction
    row = dupRow;
    col = dupCol;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }

    // left lower diagonal
    row = dupRow;
    col = dupCol;
    while (row < n and col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }

    return true; // is safe
}

void solve(int col, vector<string> &board, vector<vector<int>> &ans, int n, vector<int> &res)
{
    // if all col, queen place successfully
    if (col == n)
    {
        // keep index
        for (int i = 0; i < col; i++)
            for (int j = 0; j < col; j++)
                if (board[j][i] == 'Q')
                    res.push_back(j + 1);
        ans.push_back(res);
        res.clear(); // remove all index
        return;
    }

    // othwise fill on all col
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q'; // mark queen
            solve(col + 1, board, ans, n, res);
            board[row][col] = '.'; // after operation remove queen
        }
    }
}

vector<vector<int>> nQueen(int n)
{
    vector<vector<int>> ans; // store all queen placed answer
    vector<int> res;         // store single queen ans
    vector<string> board(n); // this will use for kept marking of queen
    string s(n, '.');        // initally it's fill as a dot's
    for (int i = 0; i < n; i++)
        board[i] = s; // in all row
    solve(0, board, ans, n, res);
    sort(ans.begin(), ans.end());
    return ans;
}

/* method 2 (optimized approach) */
void solve(int col, vector<string> &board, vector<vector<int>> &ans, int n, vector<int> &res, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal)
{
    // if all col, queen place successfully
    if (col == n)
    {
        // keep index
        for (int i = 0; i < col; i++)
            for (int j = 0; j < col; j++)
                if (board[j][i] == 'Q')
                    res.push_back(j + 1);
        ans.push_back(res);
        res.clear(); // remove all index
        return;
    }

    // othwise fill on all col
    for (int row = 0; row < n; row++)
    {
        if (leftRow[row] == 0 and lowerDiagonal[row + col] == 0 and upperDiagonal[(n - 1) + col - row] == 0)
        {
            board[row][col] = 'Q'; // mark queen
            leftRow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[(n - 1) + col - row] = 1;

            solve(col + 1, board, ans, n, res);
            board[row][col] = '.'; // after operation remove queen
            leftRow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[(n - 1) + col - row] = 0;
        }
    }
}

vector<vector<int>> nQueen(int n)
{
    vector<vector<int>> ans; // store all queen placed answer
    vector<int> res;         // store single queen ans
    vector<string> board(n); // this will use for kept marking of queen
    string s(n, '.');        // initally it's fill as a dot's
    for (int i = 0; i < n; i++)
        board[i] = s; // in all row,

    vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
    solve(0, board, ans, n, res, leftRow, upperDiagonal, lowerDiagonal);
    sort(ans.begin(), ans.end());
    return ans;
}