#include <bits/stdc++.h>
using namespace std;

/* method 1 (using dfs) */
void dfs(int node, vector<bool> &vis, stack<int> &st, vector<int> adj[])
{
    vis[node] = true; // mark visited
    for (auto it : adj[node])
    {
        if (!vis[it]) // if not visited
            dfs(it, vis, st, adj);
    }
    st.push(node); // all neighbours visited then push into stack
}
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<bool> vis(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs(i, vis, st, adj);
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
    /* TC-O(v + e + v) SC-O(v + v) */
}