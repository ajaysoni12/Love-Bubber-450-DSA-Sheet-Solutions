#include <bits/stdc++.h>
using namespace std;

/* method 1 (using standard process) */
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> res;
    queue<int> q;

    // starting from 0
    q.push(0);

    // keep tracking which nodes visited
    vector<bool> vis(V, false);
    vis[0] = true;
    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        res.push_back(n);
        // for each loop - for(auto it : adj[n])
        for (int i = 0; i < adj[n].size(); i++)
        {
            // if it's false then hi insert
            if (vis[adj[n][i]] == false)
            {
                vis[adj[n][i]] = true; // mark as a visited
                q.push(adj[n][i]);     // insert in queue
            }
        }
    }
    return res;
    /* TC-O(v+e) SC-O(v) */
}