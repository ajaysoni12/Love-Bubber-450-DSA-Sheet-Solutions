#include <bits/stdc++.h>
using namespace std;

/* method 1 (greedy approach) */
long long minCost(long long arr[], long long n)
{
    // take min heap
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; i++)
        pq.push(arr[i]);

    long long cost = 0;

    // till we not have less than two element
    while (pq.size() >= 2)
    {
        // pop two element
        long long currLength = pq.top();
        pq.pop();
        currLength += pq.top();
        pq.pop();

        cost += currLength;
        pq.push(currLength); // and add their sum
    }
    return cost; // return total cost
}