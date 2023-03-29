#include <bits/stdc++.h>
using namespace std;

/* method 1 (recursion) */
int f(int ind, int buy, int cap, int price[], int n)
{
    if (ind == n or cap == 0)
        return 0;

    if (buy == 1)
        return max(-price[ind] + f(ind + 1, 0, cap, price, n), 0 + f(ind + 1, 1, cap, price, n));
    return max(price[ind] + f(ind + 1, 1, cap - 1, price, n), f(ind + 1, 0, cap, price, n));
}
int maxProfit(int K, int N, int price[])
{
    return f(0, 1, K, price, N);
    /* TC-O(expo) SC-O(n) */
}

/* method 2 (memoization) */
int f(int ind, int buy, int cap, int price[], int n, vector<vector<vector<int>>> &dp)
{
    if (ind == n or cap == 0)
        return 0;

    if (dp[ind][buy][cap] != -1)
        return dp[ind][buy][cap];

    if (buy == 1)
        return dp[ind][buy][cap] = max(-price[ind] + f(ind + 1, 0, cap, price, n, dp), 0 + f(ind + 1, 1, cap, price, n, dp));
    return dp[ind][buy][cap] = max(price[ind] + f(ind + 1, 1, cap - 1, price, n, dp), f(ind + 1, 0, cap, price, n, dp));
}
int maxProfit(int K, int N, int price[])
{
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(2, vector<int>(K + 1, -1)));
    return f(0, 1, K, price, N, dp);
    /* TC-O(n*2*k) SC-O(n*2*k + n) */
}

/* method 3 (tabulation) */
int maxProfit(int K, int N, int price[])
{
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(2, vector<int>(K + 1, 0)));

    // base case, no need buy default 0

    for (int ind = N - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= K; cap++) // no need to start from 0
            {
                if (buy == 1)
                    dp[ind][buy][cap] = max(-price[ind] + dp[ind + 1][0][cap], 0 + dp[ind + 1][1][cap]);
                else
                    dp[ind][buy][cap] = max(price[ind] + dp[ind + 1][1][cap - 1], dp[ind + 1][0][cap]);
            }
        }
    }

    return dp[0][1][K];
    /* TC-O(n*2*k) SC-O(n*2*k) */
}

/* method 4 (space optimization) */
int maxProfit(int K, int N, int price[])
{
    vector<vector<int>> after(2, vector<int>(K + 1, 0));
    vector<vector<int>> curr(2, vector<int>(K + 1, 0));

    // base case, no need buy default 0

    for (int ind = N - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= K; cap++) // no need to start from 0
            {
                if (buy == 1)
                    curr[buy][cap] = max(-price[ind] + after[0][cap], 0 + after[1][cap]);
                else
                    curr[buy][cap] = max(price[ind] + after[1][cap - 1], after[0][cap]);
            }
        }
        after = curr;
    }

    return after[1][K];
    /* TC-O(n*2*k) SC-O(2*k) */
}

/* another method */
int f(int ind, int ts, int price[], int n, int k)
{
    if (ind == n or ts == 2 * k)
        return 0;

    if (ts % 2 == 0) // buy
        return max(-price[ind] + f(ind + 1, ts + 1, price, n, k), 0 + f(ind + 1, ts, price, n, k));
    else // sell
        return max(price[ind] + f(ind + 1, ts + 1, price, n, k), 0 + f(ind + 1, ts, price, n, k));
}
int maxProfit(int K, int N, int price[])
{
    f(0, 0, price, N, K);
    /* TC - O(expo) SC-O(N) */
}

// memoization
int f(int ind, int ts, int price[], int n, int k, vector<vector<int>> &dp)
{
    if (ind == n or ts == 2 * k)
        return 0;

    if (dp[ind][ts] != -1)
        return dp[ind][ts];

    if (ts % 2 == 0) // buy
        return dp[ind][ts] = max(-price[ind] + f(ind + 1, ts + 1, price, n, k, dp), 0 + f(ind + 1, ts, price, n, k, dp));
    else // sell
        return dp[ind][ts] = max(price[ind] + f(ind + 1, ts + 1, price, n, k, dp), 0 + f(ind + 1, ts, price, n, k, dp));
}
int maxProfit(int K, int N, int price[])
{
    vector<vector<int>> dp(N, vector<int>(2 * K, -1)); 
    f(0, 0, price, N, K, dp);
    /* TC - O(n*2*k) SC-O(N) */
}