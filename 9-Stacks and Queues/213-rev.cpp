#include <bits/stdc++.h>
using namespace std;

/* method 1 (using stack) */
queue<int> rev(queue<int> q)
{
    stack<int> s; // create stack

    // copy all element into stack
    while (!q.empty())
    {
        int element = q.front();
        q.pop();
        s.push(element);
    }

    // copy all element into queue
    while (!s.empty())
    {
        int element = s.top();
        s.pop();
        q.push(element);
    }
    return q;
    /* TC-O(2n) SC-O(n) */
}

/* method 2 (using recursion)*/
void solve(queue<int> &q)
{
    if (q.empty())
        return;
    int k = q.front();
    q.pop();
    solve(q);
    q.push(k);
}
queue<int> rev(queue<int> q)
{
    solve(q);
    return q;
    /* TC-O(n) SC-O(n) recursion*/
}