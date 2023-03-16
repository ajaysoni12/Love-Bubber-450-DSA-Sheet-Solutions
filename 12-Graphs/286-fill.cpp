#include <bits/stdc++.h>
using namespace std;

/* method 1 (using dfs) */
void dfs(int row, int col, vector<vector<bool>> &vis, vector<vector<char>> mat, int n, int m)
{
    // mark as visited
    vis[row][col] = true;

    // four direction
    int dx[] = {-1, 0, +1, 0};
    int dy[] = {0, +1, 0, -1};

    // check for top, right, bottom, left
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + dx[i];
        int ncol = col + dy[i];
        if (nrow >= 0 and ncol >= 0 and nrow < n and ncol < m and mat[nrow][ncol] == 'O' and !vis[nrow][ncol])
            dfs(nrow, ncol, vis, mat, n, m);
    }
}
vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    // traverse first and last row
    for (int j = 0; j < m; j++)
    {
        // first row
        if (mat[0][j] == 'O' and !vis[0][j])
            dfs(0, j, vis, mat, n, m);
        // last row
        if (mat[n - 1][j] == 'O' and !vis[n - 1][j])
            dfs(n - 1, j, vis, mat, n, m);
    }

    // traverse first and last col
    for (int i = 0; i < n; i++)
    {
        // first col
        if (mat[i][0] == 'O' and !vis[i][0])
            dfs(i, 0, vis, mat, n, m);
        // last col
        if (mat[i][m - 1] == 'O' and !vis[i][m - 1])
            dfs(i, m - 1, vis, mat, n, m);
    }

    // if not visited then mark 'O'
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j])
                mat[i][j] = 'X';
            else
                mat[i][j] = 'O';
        }
    }
    return mat;
    /* TC-O(n*m*4 + n*m) SC-O(n*m + n*m) */
}