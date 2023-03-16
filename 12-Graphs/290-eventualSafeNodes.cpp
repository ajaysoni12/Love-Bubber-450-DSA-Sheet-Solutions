#include <bits/stdc++.h>
using namespace std;

// check terminal node
bool isTerminal(int node, vector<int> adj[])
{
    if (adj[node].size() == 0)
        return true;
    return false;
}
bool dfs(int node, vector<int> adj[], vector<bool> &vis)
{
    vis[node] = true;

    if (isTerminal(node, adj) == true)
        return true;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs(it, adj, vis) == false)
            {
                vis[it] = false; // marks as unvisted
                return false;
            }
            vis[it] = false; // mark as unvisited
        }
        // if path note lead terminal nodes, then definitely contain cycle
        else
            return false;
    }
    return true;
}
vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
    vector<int> safeNode;
    vector<bool> vis(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, adj, vis) == true)
            {
                safeNode.push_back(i);
                vis[i] = false;
            }
        }
    }
    return safeNode;
}

/* method 2 (using optimized dfs) */
bool dfseventualSafeNodes(int s, vector<bool> &visited, vector<bool> &dfsvisited, vector<bool> &presentvisited, vector<int> adj[])
{
    visited[s] = true;
    dfsvisited[s] = true;
    vector<int> data = adj[s];
    for (auto v : data)
    {
        if (!visited[v])
        {
            if (dfseventualSafeNodes(v, visited, dfsvisited, presentvisited, adj))
                return presentvisited[s] = true;
        }
        else if (visited[v] == true && dfsvisited[v] == true)
            return presentvisited[s] = true;
    }
    dfsvisited[s] = false;
    return false;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    vector<bool> dfsvisited(V, false);
    vector<bool> presentvisited(V, false);
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            dfseventualSafeNodes(i, visited, dfsvisited, presentvisited, adj);

    vector<int> ans;
    for (int i = 0; i < V; i++)
        if (presentvisited[i] == false)
            ans.push_back(i);
    return ans;
}