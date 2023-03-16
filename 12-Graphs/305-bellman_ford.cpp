#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    vector<int> dist(V, 1e8);
    int n = edges.size();
    dist[S] = 0;

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int u = edges[j][0], v = edges[j][1], w = edges[j][2];

            if (dist[u] != 1e8 and (dist[u] + w) < dist[v])
                dist[v] = w + dist[u];
        }
    }

    for (int j = 0; j < n; j++)
    {
        int u = edges[j][0], v = edges[j][1], w = edges[j][2];
        if (dist[u] != 1e8 and (dist[u] + w) < dist[v])
            return {-1};
    }
    return dist;
}