#include <bits/stdc++.h>
using namespace std;

bool isPossible(int n, vector<pair<int, int>> &pre)
{
    vector<int> adj[n];
    for (auto i : pre)
    {
        adj[i.second].push_back(i.first);
    }
    // bfs topo sort
    // if cycle detected there not possible to finis all tasks
    vector<int> indegree(n);
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    int count = 0;
    while (q.size())
    {
        int node = q.front();
        q.pop();
        count++;
        for (auto i : adj[node])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                q.push(i);
        }
    }
    return count == n; // n = no. of nodes;
}