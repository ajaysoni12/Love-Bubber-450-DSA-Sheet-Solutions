#include <bits/stdc++.h>
using namespace std;

/* method 1 (recursion) */
int f(int ind, int buy, vector<int> &arr, int n)
{
    if (ind == n)
        return 0;

    int profit = 0;
    if (buy)
        profit = max(-arr[ind] + f(ind + 1, 0, arr, n), 0 + f(ind + 1, 0, arr, n));
    else
        profit = max(arr[ind] + f(ind + 1, 1, arr, n), 0 + f(ind + 1, 0, arr, n));
    return profit;
}
int stockBuySell(vector<int> arr, int n)
{
    return f(0, 1, arr, n);
    /* TC - O(expo) SC-O(n)*/
}

/* method 2 (memoization) */
int f(int ind, int buy, vector<int> &arr, int n, vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;

    if (dp[ind][buy] != -1)
        return dp[ind][buy];

    int profit = 0;
    if (buy)
        profit = max(-arr[ind] + f(ind + 1, 0, arr, n, dp), 0 + f(ind + 1, 0, arr, n, dp));
    else
        profit = max(arr[ind] + f(ind + 1, 1, arr, n, dp), 0 + f(ind + 1, 0, arr, n, dp));
    return dp[ind][buy] = profit;
}
int stockBuySell(vector<int> arr, int n)
{
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return f(0, 1, arr, n, dp);
    /* TC - O(expo) SC-O(n)*/
}