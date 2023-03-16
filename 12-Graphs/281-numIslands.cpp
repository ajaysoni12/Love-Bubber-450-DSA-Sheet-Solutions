#include <bits/stdc++.h>
using namespace std;

/* method 1 (using dfs + recursion) */
bool isSafe(int i, int j, int n, int m)
{
    // check we can safe or not
    if (i >= 0 and j >= 0 and i < n and j < m)
        return true;
    return false;
}
void dfs(int i, int j, vector<vector<char>> &grid, int n, int m, vector<vector<int>> &vis)
{
    // mark visited
    vis[i][j] = true;

    // these all are 8 direction
    int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
    int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

    // check for every direction
    for (int k = 0; k < 8; k++)
    {
        int nrow = i + dx[k];
        int ncol = j + dy[k];

        // if it is safe and contain 1 and not visited
        if (isSafe(nrow, ncol, n, m) and grid[nrow][ncol] == '1' and !vis[nrow][ncol])
            dfs(nrow, ncol, grid, n, m, vis);
    }
}
int numIslands(vector<vector<char>> &grid)
{
    int cnt = 0; // total island
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // if it is '1' and not visited
            if (grid[i][j] == '1' and !vis[i][j])
            {
                cnt++;                      // banks of islands
                dfs(i, j, grid, n, m, vis); // then mark visited how many lands are connected to each other
            }
        }
    }
    return cnt;
    /* TC-O(n*m*8*(n+m)) SC-O(n*m + n*m) */
}