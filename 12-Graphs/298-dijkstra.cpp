#include <bits/stdc++.h>
using namespace std;

/* method 1 (using priority queue) - not for negative weight
    Dijkstra Algorithm doesn't work with negetive edgeWeight graph
    cause it will fall in infinite loop, we'll keep finding shorter path
*/
vector<int> dijkstra(int V, vector<vector<int>> adj[], int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    vector<int> dist(V, 1e9);
    dist[src] = 0;

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edgeHeight = it[1];

            if (dis + edgeHeight < dist[adjNode])
            {
                dist[adjNode] = dis + edgeHeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
    /* TC-O(E * Log(V)) SC-O(V) */
}

/* method 2 (using set) */
vector<int> dijkstra(int V, vector<vector<int>> adj[], int src)
{
    set<pair<int, int>> set;
    set.insert({0, src});

    vector<int> dist(V, 1e9);
    dist[src] = 0;

    while (!set.empty())
    {
        auto it = *set.begin();
        int node = it.second;
        int dis = it.first;
        set.erase(it);

        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edgH = it[1];

            if (dis + edgH < dist[adjNode])
            {
                // erase if it existed
                if (dist[adjNode] != 1e9)
                    set.erase({dist[adjNode], adjNode});

                dist[adjNode] = dis + edgH;
                set.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}