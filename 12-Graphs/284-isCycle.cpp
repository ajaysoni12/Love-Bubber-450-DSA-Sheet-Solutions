#include <bits/stdc++.h>
using namespace std;

/* method 1 (using bfs algortihm) */
bool dfs(int node, int parNode, vector<bool> &vis, vector<int> adj[])
{
    // mark as visited
    vis[node] = true;
    for (auto it : adj[node])
    {
        // if its not visited then go for dfs
        if (!vis[it])
        {
            if (dfs(it, node, vis, adj) == true)
                return true;
        }
        // if it's not parent node means definitely here cycle create
        else if (it != parNode)
            return true;
    }
    return false;
}
bool isCycle(int v, vector<int> adj[])
{
    vector<bool> vis(v, false);
    for (int i = 1; i <= v; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, vis, adj) == true)
                return true;
        }
    }
    return false;
    /* TC-O(v+e) SC-O(n + v+e) */
}

/* method 2 (using dfs algortihm) */
bool bfs(int src, vector<bool> &vis, vector<int> adj[])
{
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        // traverse for adjacancy list
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it];
                q.push({it, node});
            }
            // if it's equal to means parent node connect with it
            else if (it != parent)
                return true;
        }
    }
    return false;
}
bool isCycle(int v, vector<int> adj[])
{
    vector<bool> vis(v, false);
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            if (bfs(i, vis, adj) == true)
                return true;
        }
    }
    return false;
    /* TC-O(v+e) SC-O(n + v+e) */
}