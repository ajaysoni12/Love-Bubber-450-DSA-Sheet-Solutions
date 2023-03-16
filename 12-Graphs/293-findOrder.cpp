#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int n, vector<int> adj[])
{
    // bfs topo sort
    // if cycle detected there not possible to finis all tasks
    vector<int> indegree(n);
    for (int i = 0; i < n; i++)
        for (auto it : adj[i])
            indegree[it]++;

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            q.push(i);

    vector<int> topo;
    while (q.size())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto i : adj[node])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                q.push(i);
        }
    }
    return topo;
}

string findOrder(string dict[], int N, int K)
{
    // create DAG
    vector<int> adj[K];
    for (int i = 0; i < N - 1; i++)
    {
        string s1 = dict[i];
        string s2 = dict[i + 1];
        int len = min(s1.size(), s2.size());
        for (int i = 0; i < len; i++)
        {
            if (s1[i] != s2[i])
            {
                // create edge
                adj[s1[i] - 'a'].push_back(s2[i] - 'a');
                break;
            }
        }
    }

    vector<int> topo = topoSort(K, adj);

    // convert into string
    string ans = "";
    for (auto it : topo)
        ans += char(it + 'a');
    return ans;
    /* TC-O(n*n + v + e) SC-O(v+e + v + v) */
}