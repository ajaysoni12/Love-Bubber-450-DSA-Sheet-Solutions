#include <bits/stdc++.h>
using namespace std;

/*  method 1 (using bfs alogrithm) */
vector<vector<int>> nearest(vector<vector<int>> grid)
{
    // grid size
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // push all 1's position and in grid[i][j] distance do zero
            if (grid[i][j] == 1)
            {
                q.push({i, j});
                grid[i][j] = 0;
                visited[i][j] = true;
            }

            // othwerise insert max value
            else
                grid[i][j] = INT_MAX;
        }
    }

    int level = 0; // level
    while (!q.empty())
    {
        int size = q.size();
        level++;
        while (size--)
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int dx[4] = {-1, 0, 1, 0};
            int dy[4] = {0, -1, 0, 1};

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + dx[i];
                int ncol = col + dy[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == INT_MAX && visited[nrow][ncol] == false)
                {
                    grid[nrow][ncol] = level;
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = true;
                }
            }
        }
    }
    return grid;
    /* TC-O(n*m+v+e*4) SC-O(n*m + n*m) */
}