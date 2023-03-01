#include <bits/stdc++.h>
using namespace std;

/* method 1 (using stack) */
queue<int> modifyQueue(queue<int> q, int k)
{
    // create stack
    stack<int> s;

    // insert in stack, first k value of queue
    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }

    // then insert stack value into queue in last
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    // then again insert left q.size()-k value into queue last
    for (int i = 0; i < q.size() - k; i++)
    {
        q.push(q.front());
        q.pop();
    }

    return q;
    /* TC-O(2k+n-k = O(n+k)) SC-O(k) */
}

/* method 2 (using backtracking) */
void solve(queue<int> &q, int k)
{
    if (q.empty() or k == 0)
        return;
    int ele = q.front();
    q.pop();
    solve(q, k - 1);
    q.push(ele);
}
queue<int> modifyQueue(queue<int> q, int k)
{
    solve(q, k);
    return q;
    /* TC-O(k) SC-O(k) */
}