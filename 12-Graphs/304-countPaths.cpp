#include <bits/stdc++.h>
using namespace std;

long long countPaths(long long n, vector<vector<long long>> &roads)
{
    // create adjacency list
    vector<pair<long long, long long>> adj[n];
    for (auto it : roads)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    vector<long long> dist(n, 1e9), ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});
    long long mod = 1e9 + 7;

    while (!pq.empty())
    {
        long long dis = pq.top().first;
        long long node = pq.top().second;
        pq.pop();

        if (dist[node] < dis)
            continue;

        for (auto it : adj[node])
        {
            long long adjNode = it.first;
            long long edgeW = it.second;

            // this is the first time i am coming
            // with this short distance
            if (dis + edgeW < dist[adjNode])
            {
                dist[adjNode] = dis + edgeW;
                pq.push({dis + edgeW, adjNode});
                ways[adjNode] = ways[node];
            }
            // same path with shortest distance
            else if (dis + edgeW == dist[adjNode])
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
        }
    }
    return ways[n - 1] % mod;
}