#include <bits/stdc++.h>
using namespace std;

// prims algortihm 
int spanningTree(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0}); // {weight, node}

    vector<bool> vis(V, 0);
    int sum = 0;

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second;

        if (vis[node])
            continue;

        sum += wt;
        vis[node] = 1;
        for (auto i : adj[node])
            pq.push({i[1], i[0]});
    }
    return sum;
}