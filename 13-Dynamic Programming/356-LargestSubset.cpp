#include <bits/stdc++.h>
using namespace std;

/* method 1 (tabulation) */
vector<int> LargestSubset(int n, vector<int> &arr)
{
    vector<int> dp(n, 1), hash(n);
    int mxLen = 1;
    int lastInd = 0;

    sort(arr.begin(), arr.end()); 

    // update
    for (int ind = 0; ind < n; ind++)
    {
        hash[ind] = ind;
        for (int prev = 0; prev < ind; prev++)
        {
            if (arr[ind] % arr[prev] == 0 && 1 + dp[prev] > dp[ind])
            {
                dp[ind] = 1 + dp[prev];
                hash[ind] = prev;
            }
        }
        if (dp[ind] > mxLen)
        {
            mxLen = dp[ind];
            lastInd = ind;
        }
    }

    // back track
    vector<int> ans(mxLen);
    ans[0] = arr[lastInd];
    int ind = 1;
    while (hash[lastInd] != lastInd)
    {
        lastInd = hash[lastInd];
        ans[ind++] = arr[lastInd];
    }
    reverse(ans.begin(), ans.end());
    return ans;
    /* TC-O(n^2 + n) SC-O(n +n)*/
}