#include <bits/stdc++.h>
using namespace std;

/* method 1 (using priority queue)*/
int minValue(string str, int k)
{
    // insert all char with freq
    unordered_map<int, int> mp;
    for (int i = 0; i < str.size(); i++)
        mp[str[i]]++;

    // keep order of freq
    priority_queue<int> pq;
    for (auto it : mp)
        pq.push(it.second);

    // k character remove
    while (k)
    {
        int x = pq.top();
        pq.pop();
        x--;
        pq.push(x);
        k--;
    }

    // than calculate sum
    int sum = 0;
    while (!pq.empty())
    {
        int d = pq.top();
        sum += (d * d);
        pq.pop();
    }
    return sum;
    /* TC-O(n+k +n*log(k)) SC-O(n) */
}