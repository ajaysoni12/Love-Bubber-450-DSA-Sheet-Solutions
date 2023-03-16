#include <bits/stdc++.h>
using namespace std;

// Function to find minimum time required to rot all oranges.
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

    int tm = 0; // minTime

    // all four direction
    int drow[] = {-1, 0, +1, 0};
    int dcol[] = {0, +1, 0, -1};
    int cnt = 0; // count fresh orange who goes to rotton
    while (!q.empty())
    {
        int r = q.front().first.first;  // get row
        int c = q.front().first.second; // get col
        int t = q.front().second;       // get time
        tm = max(tm, t);                // time update
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and vis[nrow][ncol] == 0 and grid[nrow][ncol] == 1)
            {
                q.push({{nrow, ncol}, tm + 1}); // time increae by unit time
                vis[nrow][ncol] = 2;            // mark visited
                cnt++;                          // increment cnt
            }
        }
    }

    // if fresOragne count and cnt is equal to means all fresh orange are rotton
    if (cntFresh != cnt)
        return -1;
    return tm; // minTime take
    /* TC-O(n*m+4*n*m) SC-O(n*m + n*m) */
}
