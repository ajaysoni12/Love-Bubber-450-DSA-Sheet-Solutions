#include <bits/stdc++.h>
using namespace std;

/* method 1 (using dfs) */
void dfs(int row, int col, vector<vector<bool>> &vis, vector<vector<int>> &grid, int n, int m)
{
    vis[row][col] = true; // mark as visited

    // four diection up, right, bottom, left
    int dx[] = {-1, 0, +1, 0};
    int dy[] = {0, +1, 0, -1};

    for (int i = 0; i < 4; i++)
    {
        int nrow = row + dx[i];
        int ncol = col + dy[i];
        // is safe and !vis and grid contain 1
        if (nrow >= 0 and ncol >= 0 and nrow < n and ncol < m and !vis[nrow][ncol] and grid[nrow][ncol] == 1)
            dfs(nrow, ncol, vis, grid, n, m);
    }
}
int numberOfEnclaves(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    // traverse first and last row
    for (int j = 0; j < m; j++)
    {
        // first row
        if (!vis[0][j] and grid[0][j] == 1)
            dfs(0, j, vis, grid, n, m);
        // last row
        if (!vis[n - 1][j] and grid[n - 1][j] == 1)
            dfs(n - 1, j, vis, grid, n, m);
    }

    // traverse first and last col
    for (int i = 0; i < n; i++)
    {
        // first col
        if (!vis[i][0] and grid[i][0] == 1)
            dfs(i, 0, vis, grid, n, m);
        // last col
        if (!vis[i][m - 1] and grid[i][m - 1] == 1)
            dfs(i, m - 1, vis, grid, n, m);
    }

    // count no of enclaves
    int noOfEnclaves = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 and !vis[i][j])
                noOfEnclaves++;
        }
    }
    return noOfEnclaves;
    /* TC-O(3*n*m*4) SC-O(n*m + n*m) */
}

/* method 2 (using bfs) */
int numberOfEnclaves(vector<vector<int>> &grid)
{
    // taking a queue data structure stroing the rows and columns
    queue<pair<int, int>> q;
    
    // size of the grid
    int n = grid.size();
    int m = grid[0].size();
    
    // created a visited matrix
    int vis[n][m] = {0};
    
    // traversing all boundry around the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // first row, first column, last row, last column
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
    }
    // string all direction of row and column
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};

    // now traversing queue while not empty()
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        
        // now traversing all the four direction
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow > 0 && nrow < n && ncol > 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
            {
                // push nrow and ncol into queue
                q.push({nrow, ncol});
                // then go and mark them as visited in vis[n][m]
                vis[nrow][ncol] = 1;
            }
        }
    }

    int cnt = 0;
    // checking all 1 in grid matrix are zero or one in visited matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && vis[i][j] == 0)
                cnt++;
        }
    }
    return cnt;
}