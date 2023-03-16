#include <bits/stdc++.h>
using namespace std;

/* method 1 (using dfs approach) */
bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[])
{
    // mark as visited
    vis[node] = 1;
    pathVis[node] = 1;

    // traverse for adjacent node
    for (auto it : adj[node])
    {
        // if it is node visited
        if (!vis[it])
        {
            if (dfsCheck(it, adj, vis, pathVis) == true)
                return true;
        }
        // if the node has been previously visited
        // but it has to visited in the same path
        else if (pathVis[it])
            return true;
    }

    // unmark
    pathVis[node] = 0;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    int vis[V] = {0};
    int pathVis[V] = {0};

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            if (dfsCheck(i, adj, vis, pathVis) == true)
                return true;
    }
    return false;
    /* TC-O(v+e) SC-O(2v) */
}