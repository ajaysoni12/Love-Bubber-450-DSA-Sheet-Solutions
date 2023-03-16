#include <bits/stdc++.h>
using namespace std;

/* method 1 (using standard process) */
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> res; // store answer
    stack<int> st;
    vector<bool> vis(V, false); // mark vis nodes

    // intial step
    st.push(0);
    vis[0] = true;
    while (!st.empty())
    {
        int n = st.top();
        st.pop();
        res.push_back(n);
        // auto it = adj[n].rbegin();
        // for (; it != adj[n].rend(); it++)
        for (auto it : adj[n])
        {
            if (!vis[it])
            {
                vis[it] = true;
                st.push(it);
            }
        }
    }
    return res;
    /* TC-O(v+e) SC-O(v) */
}

/* method 2 (using recursion) */
void solve(int &src, vector<int> adj[], vector<int> &res, int v, vector<bool> &vis)
{
    vis[src] = true; // mark visited
    res.push_back(src);
    for (auto it : adj[src]) // move on it's edge nodes
        if (vis[it] == false)
            solve(it, adj, res, v, vis);
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> res;
    vector<bool> vis(V, false);
    int src = 0; // source address
    solve(src, adj, res, V, vis);
    /* TC-O(v+e) SC-O(v) */
}