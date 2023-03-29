#include <bits/stdc++.h>
using namespace std;

/* method 1 (recursion) */
int f(int ind, int buy, vector<int> &arr, int n)
{
    if (ind >= n)
        return 0;

    int profit = 0;
    if (buy)
        profit = max(-arr[ind] + f(ind + 1, 0, arr, n), 0 + f(ind + 1, 0, arr, n));
    else
        // cannot buy after sell, so increase by 2
        profit = max(arr[ind] + f(ind + 2, 1, arr, n), 0 + f(ind + 1, 0, arr, n));
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
    if (ind >= n)
        return 0;

    if (dp[ind][buy] != -1)
        return dp[ind][buy];

    int profit = 0;
    if (buy)
        profit = max(-arr[ind] + f(ind + 1, 0, arr, n, dp), 0 + f(ind + 1, 0, arr, n, dp));
    else
        profit = max(arr[ind] + f(ind + 2, 1, arr, n, dp), 0 + f(ind + 1, 0, arr, n, dp));
    return dp[ind][buy] = profit;
}
int stockBuySell(vector<int> arr, int n)
{
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return f(0, 1, arr, n, dp);
    /* TC - O(expo) SC-O(n)*/
}

/* method 3 (tabulation) */
int stockBuySell(vector<int> price, int n)
{
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    // base case already compute

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy == 1)
                dp[ind][buy] = max(-price[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
            else // ind == n - 1
                dp[ind][buy] = max(price[ind] + dp[ind + 2][1], dp[ind + 1][0]);
        }
    }

    return dp[0][1];
    /* TC - O(n*2) SC-O(n*2)*/
}

/* method tc optimization */
int stockBuySell(vector<int> price, int n)
{
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    // base case already compute

    for (int ind = n - 1; ind >= 0; ind--)
    {
        dp[ind][1] = max(-price[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
        // ind == n - 1
        dp[ind][0] = max(price[ind] + dp[ind + 2][1], dp[ind + 1][0]);
    }

    return dp[0][1];
    /* TC - O(n) SC-O(n*2)*/
}
