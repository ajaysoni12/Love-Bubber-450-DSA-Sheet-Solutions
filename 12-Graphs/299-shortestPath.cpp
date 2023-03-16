#include <bits/stdc++.h>
using namespace std;

/* method 1 (using priority queue) */
vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    // create adjacency list
    vector<pair<int, int>> adj[n + 1];
    for (auto it : edges)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    // priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    vector<int> dist(n + 1, 1e9);
    dist[1] = 0;
    vector<int> parent(n + 1);

    // making the parent to be itself at first
    for (int i = 1; i < n + 1; i++)
        parent[i] = i;

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            int edgW = it.second;
            int adjNode = it.first;

            if (dis + edgW < dist[adjNode])
            {
                dist[adjNode] = dis + edgW;
                pq.push({dist[adjNode], adjNode});
                parent[adjNode] = node;
            }
        }
    }

    // we can't reach last node
    if (dist[n] == 1e9)
        return {-1};

    vector<int> path;
    int node = n;
    while (parent[node] != node)
    {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    return path;
}