#include <bits/stdc++.h>
using namespace std;

/* method 1 (using queue) */
int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                 pair<int, int> destination)
{
    if (source == destination)
        return 0;
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dest(n, vector<int>(m, 1e9));
    dest[source.first][source.second] = 0;
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {source.first, source.second}});

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int des = it.first;
        int row = it.second.first;
        int col = it.second.second;

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if (nrow >= 0 and ncol >= 0 and nrow < n and ncol < m and grid[nrow][ncol] == 1 and des + 1 < dest[nrow][ncol])
            {
                dest[nrow][ncol] = des + 1;
                if (nrow == destination.first and ncol == destination.second)
                    return des + 1;
                q.push({1 + des, {nrow, ncol}});
            }
        }
    }
    return -1;
}