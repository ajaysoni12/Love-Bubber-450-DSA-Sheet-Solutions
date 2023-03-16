#include <bits/stdc++.h>
using namespace std;

/* method 1 (using bfs - unit distance) */
vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
{
    // create adjancy list
    vector<int> adj[N];
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    // intial confrugation
    int dist[N];
    for (int i = 0; i < N; i++)
        dist[i] = 1e9;

    // src node
    dist[src] = 0;
    queue<int> q;
    q.push(src); // push source node

    // find distance
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (dist[node] + 1 < dist[it])
            {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }

    // if some one not reach then put -1
    vector<int> shortestPath(N, -1);
    for (int i = 0; i < N; i++)
        if (dist[i] != 1e9)
            shortestPath[i] = dist[i];

    return shortestPath;
    /* TC-O(M + N + V+E + N) SC-O(N + N + N + N) */
}