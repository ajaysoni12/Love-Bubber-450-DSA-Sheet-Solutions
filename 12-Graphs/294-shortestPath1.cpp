#include <bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<pair<int, int>> adj[],
              stack<int> &st, vector<int> &vis)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        int v = it.first;
        if (!vis[v])
            topoSort(v, adj, st, vis);
    }
    st.push(node);
}
vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    // N = nodes, M = edges

    // create dag
    vector<pair<int, int>> adj[N];
    for (int i = 0; i < M; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }

    // visited array
    vector<int> vis(N, false);
    stack<int> st;
    for (int i = 0; i < N; i++)
        if (!vis[i])
            topoSort(i, adj, st, vis);

    // find distance
    vector<int> dist(N, 1e9);

    // source is 0
    dist[0] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        for (auto it : adj[node])
        {
            int v = it.first;
            int wt = it.second;
            dist[v] = min(dist[node] + wt, dist[v]); // if it's is minimum then update
        }
    }

    // if some one not reach
    for (int i = 0; i < N; i++)
        if (dist[i] == 1e9)
            dist[i] = -1;

    return dist;
    /* TC-O(m + N+M + N+M + N) SC-O(N + N + N)*/
}