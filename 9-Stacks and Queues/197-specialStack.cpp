#include <bits/stdc++.h>
using namespace std;

void push(stack<int> &s, int a)
{
    s.push(a);
    /* TC-O(1) SC-O(1) */
}

bool isFull(stack<int> &s, int n)
{
    return s.size() == n;
    /* TC-O(1) SC-O(1) */
}

bool isEmpty(stack<int> &s)
{
    return s.size() == 0;
    /* TC-O(1) SC-O(1) */
}

int pop(stack<int> &s)
{
    int k = s.top();
    s.pop();
    return k;
    /* SC-O(1) TC-O(1) */
}

int getMin(stack<int> &s)
{
    int minVal = INT_MAX;
    while (!s.empty())
    {
        minVal = min(minVal, s.top());
        s.pop();
    }
    return minVal;
    /* TC-O(n) SC-O(1) */
}