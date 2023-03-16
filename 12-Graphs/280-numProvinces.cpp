#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force - using bfs or dfs) */
void bfs(int node, vector<vector<int>> adj, int v, vector<bool> &vis)
{
    queue<int> q;
    q.push(node);
    vis[node] = true;
    while (!q.empty())
    {
        int n = q.front();
        q.pop();

        // adj matrix will be given
        for (int it = 0; it < v; it++)
        {
            // if it's 1 and it is  ot viisted
            if (adj[n][it] and !vis[it])
            {
                vis[it] = true;
                q.push(it);
            }
        }
    }
}
int numProvinces(vector<vector<int>> adj, int V)
{
    vector<bool> vis(V, false);
    int cnt = 0; // total provinces
    for (int i = 0; i < V; i++)
    {
        // for ith nodes, mark vis for all it's adjacent nodes
        if (vis[i] == false)
        {
            cnt++;
            bfs(i, adj, V, vis); // or apply dfs
        }
    }
    return cnt;
    /* TC-O(V+(V+2E)) SC-O(n+n+n) */
}