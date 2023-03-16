#include <bits/stdc++.h>
using namespace std;

/* method 1 (using dfs) */
void dfs(int row, int col, int brow, int bcol, vector<vector<int>> &grid, vector<vector<int>> &visited, vector<pair<int, int>> &temp)
{
    int n = grid.size();
    int m = grid[0].size();

    // mark visited
    visited[row][col] = 1;

    // unique path value, that we disticnt
    pair<int, int> p;
    p.first = row - brow;
    p.second = col - bcol;
    temp.push_back(p);

    // direction
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + dx[i];
        int ncol = col + dy[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && visited[nrow][ncol] == 0)
            dfs(nrow, ncol, brow, bcol, grid, visited, temp);
    }
}
int countDistinctIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> st; // store unique path
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 0 && grid[i][j] == 1)
            {
                vector<pair<int, int>> temp;
                dfs(i, j, i, j, grid, visited, temp);
                st.insert(temp); // insert
            }
        }
    }
    return st.size(); // distinct islands
    /* TC-O(n*m*4) SC-O(n*m + st.size() + n*m) */
}

/* method 2 (using bfs) */
bool isValid(int r, int c, int n, int m)
{
    return (r >= 0 && c >= 0 && r < n && c < m);
}
void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int, int>> &vec, int delrow[], int delcol[], int row0, int col0)
{
    vis[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    q.push({row, col});
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        vec.push_back({row - row0, col - col0});
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (isValid(nrow, ncol, n, m) &&
                !vis[nrow][ncol] && grid[nrow][ncol] == 1)
            {
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
    }
}
int countDistinctIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0)); // n x m
    set<vector<pair<int, int>>> st; // n x m

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0 && grid[i][j] == 1)
            {
                vector<pair<int, int>> vec;
                // n x m x 4
                bfs(i, j, vis, grid, vec, delrow, delcol, i, j);
                st.insert(vec);
            }
        }
    }
    // n x m + (n x m x 4)
    return st.size();
}