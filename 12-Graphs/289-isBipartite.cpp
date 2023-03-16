#include <bits/stdc++.h>
using namespace std;

/* method 1 (using dfs) */
bool isBipartite(int V, vector<int> adj[])
{
    vector<bool> color(V, -1);
    queue<int> q;

    // different components
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            q.push(i);
            color[i] = 0;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                // traverse for adjacent node
                for (auto it : adj[node])
                {
                    if (color[it] == -1)
                    {
                        q.push(it);
                        color[it] = !color[node];
                    }

                    // same color have
                    else if (color[it] == color[node])
                        return false;
                }
            }
        }
    }
    return true;
    /* TC-O(v + 2e) SC-O(2v) */
}

/* method 2 (using dfs) */
bool dfs(vector<int> adj[], int i, vector<int> &col, int c)
{
    col[i] = c;
    for (auto it : adj[i])
    {
        if (col[it] == -1)
        {
            if (!dfs(adj, it, col, !c))
                return false;
        }
        else if (col[it] == c)
            return false;
    }
    return true;
}
bool isBipartite(int V, vector<int> adj[])
{
    vector<int> col(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (col[i] == -1)
        {
            if (!dfs(adj, i, col, 0))
                return false;
        }
    }
    return true;
    /* TC-O(v + 2e) SC-O(v + v) */
}