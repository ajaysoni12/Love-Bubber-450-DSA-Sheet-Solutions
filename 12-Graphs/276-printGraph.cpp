#include <bits/stdc++.h>
using namespace std;

/* method 1 (using brute force approach) */
vector<vector<int>> printGraph(int V, vector<int> adj[])
{
    vector<vector<int>> res;
    for (int i = 0; i < V; i++)
    {
        vector<int> temp;
        temp.push_back(i);
        for (int j = 0; j < adj[i].size(); j++)
            temp.push_back(adj[i][j]);
        res.push_back(temp);
    }
    return res;
    /* TC-O(n^2) SC-O(n^2)  */
}