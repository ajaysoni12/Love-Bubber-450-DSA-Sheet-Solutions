#include <bits/stdc++.h>
using namespace std;

/* method 1 (recursion) */
int f(int ind, int prev_ind, int arr[], int n)
{
    if (ind == n)
        return 0;

    int len = 0 + f(ind + 1, prev_ind, arr, n);
    if (prev_ind == -1 or arr[ind] > arr[prev_ind])
        len = max(len, 1 + f(ind + 1, ind, arr, n));

    return len;
}
int longestSubsequence(int n, int arr[])
{
    return f(0, -1, arr, n);
    /* TC-O(2^n) SC-O(n) */
}

/* method 2 (memoization) */
int f(int ind, int prev_ind, int arr[], int n, vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;

    if (dp[ind][prev_ind + 1] != -1)
        return dp[ind][prev_ind + 1];

    int len = 0 + f(ind + 1, prev_ind, arr, n, dp);
    if (prev_ind == -1 or arr[ind] > arr[prev_ind])
        len = max(len, 1 + f(ind + 1, ind, arr, n, dp));

    return dp[ind][prev_ind + 1] = len;
}
int longestSubsequence(int n, int arr[])
{
    // here -1 starting, so we take 1 based indexing
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(0, -1, arr, n, dp);
    /* TC-O(n*n) SC-O(n*n + n) */
}

/* method 3 (tabulation) */
int longestSubsequence(int n, int arr[])
{
    // here -1 starting, so we take 1 based indexing
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // base case is already 0

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
        {
            int len = 0 + dp[ind + 1][prev_ind + 1];
            if (prev_ind == -1 or arr[ind] > arr[prev_ind])
                len = max(len, 1 + dp[ind + 1][ind + 1]);
        }
    }

    return dp[0][-1 + 1];
    /* TC-O(n*n) SC-O(n*n) */
}

/* method 4 (space optimization) */
int longestSubsequence(int n, int arr[])
{
    // here -1 starting, so we take 1 based indexing
    vector<int> after(n + 1, 0), curr(n + 1, 0);

    // base case is already 0

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
        {
            int len = 0 + after[prev_ind + 1];
            if (prev_ind == -1 or arr[ind] > arr[prev_ind])
                len = max(len, 1 + after[ind + 1]);
            curr[prev_ind + 1] = len;
        }
        after = curr;
    }

    return after[-1 + 1];
    /* TC-O(n*n) SC-O(n+n) */
}

/* method 5 (optimized approach) */
int longestSubsequence(int n, int arr[])
{
    vector<int> dp(n, 1);

    int mxLen = 0;
    for (int ind = 0; ind < n; ind++)
    {
        for (int prev = 0; prev < ind; prev++)
        {
            if (arr[prev] < arr[ind])
                dp[ind] = max(dp[ind], 1 + dp[prev]);
        }
        mxLen = max(mxLen, dp[ind]);
    }
    return mxLen;
    /* TC-O(n*n) SC-O(n) */
}

/* method 6 (binary search) */
int longestSubsequence(int n, int arr[])
{
    vector<int> temp;
    temp.push_back(arr[0]);
    int len = 1;

    for (int ind = 1; ind < n; ind++)
    {
        if (arr[ind] > temp.back())
        {
            temp.push_back(arr[ind]);
            len++;
        }
        else
        {
            int index = lower_bound(temp.begin(), temp.end(), arr[ind]);
            temp[index] = arr[ind];
        }
    }
    return len;
}