#include <bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int> &arr, int start, int end)
{
    queue<pair<int, int>> q;
    q.push({0, start});

    vector<int> distance(100000, 1e9);
    distance[start] = 0;

    while (!q.empty())
    {
        int steps = q.front().first;
        int node = q.front().second;
        q.pop();

        if (node == end)
            return steps;

        for (int i = 0; i < arr.size(); i++)
        {
            if (steps + 1 < distance[node * arr[i] % 100000])
            {
                distance[node * arr[i] % 100000] = steps + 1;
                q.push({steps + 1, (node * arr[i]) % 100000});
            }
        }
    }
    return -1;
}