#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach) */
vector<int> help_classmate(vector<int> arr, int n)
{
    vector<int> res;
    int next, i, j;
    for (i = 0; i < n; i++)
    {
        next = -1;
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                next = arr[j];
                break;
            }
        }
        res.push_back(next);
    }
    res;
    /* TC-O(n^2) SC-O(1)*/
}

/* method 2 (using stack) */
vector<int> help_classmate(vector<int> arr, int n)
{
    stack<pair<int, int>> s;
    vector<int> ans(n);

    // iterate for rest of the elements
    for (int i = 0; i < n; i++)
    {
        int next = arr[i];

        // if stack is empty then this element can't be NSE
        // for any other element, so just push it to stack
        // so that we can find NSE for it, and continue
        if (s.empty())
        {
            s.push({next, i});
            continue;
        }

        // while stack is not empty and the top element is
        // greater than next
        //  a) NSE for top is next, use top's index to
        //    maintain original order
        //  b) pop the top element from stack

        while (!s.empty() && s.top().first > next)
        {
            ans[s.top().second] = next;
            s.pop();
        }

        // push next to stack so that we can find NSE for it

        s.push({next, i});
    }

    // After iterating over the loop, the remaining elements
    // in stack do not have any NSE, so set -1 for them

    while (!s.empty())
    {
        ans[s.top().second] = -1;
        s.pop();
    }
    return ans;
    /* TC - O(n) SC - O(n) */
}