#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force appraoch) */
vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k)
{
    vector<long long> res; // store first min value in window of size k

    // some edge case
    if (n < k)
        return res;

    // check every window
    for (int i = 0; i < (n - k + 1); i++)
    {
        bool ok = false;
        // k size window
        for (int j = 0; j < k; j++)
        {
            // if eleemnt is neg then push and break
            if (arr[i + j] < 0)
            {
                res.push_back(arr[i + j]);
                ok = true;
                break;
            }
        }

        // if in window no neg element then push 0
        if (!ok)
            res.push_back(0);
    }
    /* TC-O(n*k) SC-O(1) */
}

/* method 2 (using queueu) */
vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k)
{
    vector<long long> res;
    // some edge case
    if (n < k)
        return res;

    // queue store index and value
    queue<pair<long long, long long>> q;

    // first insert, window k, all neg value
    for (int i = 0; i < k; i++)
        if (arr[i] < 0)
            q.push({i, arr[i]});

    // create window
    int low = 0, high = k - 1;
    while (high < n)
    {
        // if high will be neg the push
        if (arr[high] < 0)
            q.push({high, arr[high]});

        while (!q.empty())
        {
            // first neg in k windows size
            if (low <= q.front().first)
            {
                res.push_back(q.front().second);
                break;
            }
            else
                q.pop(); // otherwise pop
        }

        // if q empty means no neg element
        if (q.empty())
            res.push_back(0);

        // then pop first ele and insert last element maintain window
        low++;
        high++;
    }
    return res;
    /* TC-O(n) SC-O(k) */
}

vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k)
{
    vector<long long> res;
    if (n < k)
        return res;

    int firstNegInd = 0;
    int firstNegEle;

    for (int i = k - 1; i < n; i++)
    {
        // skip out of window and positive elements
        while ((firstNegInd < i and firstNegInd <= i - k) or arr[firstNegInd] >= 0)
            firstNegInd++;

        if (arr[firstNegInd] < 0)
            res.push_back(arr[firstNegInd]);
        else
            res.push_back(0);
    }
    return res;
    /* TC-O(n) SC-O(1) */
}