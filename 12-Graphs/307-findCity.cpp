#include <bits/stdc++.h>
using namespace std;

int findCity(int n, int m, vector<vector<int>> &edges,
             int distanceThreshold)
{
    vector<vector<int>> dict(n, vector<int>(n, INT_MAX));

    for (auto it : edges)
    {
        dict[it[0]][it[1]] = it[2];
        dict[it[1]][it[0]] = it[2];
    }

    // diagonal
    for (int i = 0; i < n; i++)
        dict[i][i] = 0;

    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dict[i][via] == INT_MAX or dict[via][j] == INT_MAX)
                    continue;
                dict[i][j] = min(dict[i][j], dict[i][via] + dict[via][j]);
            }
        }
    }

    int city = n;
    int cityNo = -1;

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (dict[i][j] <= distanceThreshold)
                cnt++;
        }

        if (cnt <= city)
        {
            city = cnt;
            cityNo = i;
        }
    }
    return cityNo;
}