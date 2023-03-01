#include <bits/stdc++.h>
using namespace std;

/* method 1 (using queue - bfs) */
int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();    // row
    int m = grid[0].size(); // col

    // {{i,j}, time}
    queue<pair<pair<int, int>, int>> q;

    // keep track visited
    int vis[n][m];

    int cntFresh = 0; // count fresh oranges
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // rotten orange
            if (grid[i][j] == 2)
            {
                // push into queue and mark as visted
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            else
                vis[i][j] = 0;

            // check it's is fresh
            if (grid[i][j] == 1)
                cntFresh++;
        }
    }

    int tm = 0;                  // time take
    int drow[] = {-1, 0, +1, 0}; // row neighbours
    int dcol[] = {0, +1, 0, -1}; // col neighbours

    int cnt = 0; // cnt all fresh orange

    // apply bfs
    while (!q.empty())
    {
        // take front value
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();

        // check all neighbours
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            // if conditions satified
            if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and vis[nrow][ncol] == 0 and grid[nrow][ncol] == 1)
            {
                q.push({{nrow, ncol}, tm + 1}); 
                vis[nrow][ncol] = 2;
                cnt++;
            }
        }
    }

    // if fresh orange and mark cnt is not equal
    if (cntFresh != cnt)
        return -1;
    return tm;
    /* TC-O(n*m*2) SC-O(n*m*2)*/
}