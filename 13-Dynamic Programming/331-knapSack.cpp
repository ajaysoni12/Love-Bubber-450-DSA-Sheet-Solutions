#include <bits/stdc++.h>
using namespace std;

/* method 1 (recursion) */
int f(int ind, int W, int wt[], int val[])
{
    // base case
    if (ind == 0)
    {
        if (wt[0] <= W)
            return val[0];
        return 0;
    }

    int notTake = 0 + f(ind - 1, W, wt, val);
    int take = INT_MIN;
    if (wt[ind] <= W)
        take = val[ind] + f(ind - 1, W - wt[ind], wt, val);

    return max(take, notTake);
}
int knapSack(int W, int wt[], int val[], int n)
{
    return f(n - 1, W, wt, val);
    /* TC-O(2^n) SC-O(n) */
}

/* method 2 (using memoization) */
int f(int ind, int W, int wt[], int val[], vector<vector<int>> &dp)
{
    // base case
    if (ind == 0)
    {
        if (wt[0] <= W)
            return val[0];
        return 0;
    }

    if (dp[ind][W] != -1)
        return dp[ind][W];

    int notTake = 0 + f(ind - 1, W, wt, val, dp);
    int take = INT_MIN;
    if (wt[ind] <= W)
        take = val[ind] + f(ind - 1, W - wt[ind], wt, val, dp);

    return dp[ind][W] = max(take, notTake);
}
int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return f(n - 1, W, wt, val, dp);
    /* TC-O(n * W) SC-O(n*W + n) */
}

/* method 3 (tabulation) */
int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    // base case
    for (int w = wt[0]; w <= W; w++)
        dp[0][w] = val[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= W; w++)
        {
            int notTake = 0 + dp[ind - 1][w];
            int take = INT_MIN;
            if (wt[ind] <= w)
                take = val[ind] + dp[ind - 1][w - wt[ind]];

            dp[ind][w] = max(take, notTake);
        }
    }
    return dp[n - 1][W];
    /* TC-O(n * W) SC-O(n*W) */
}

/* method 4 (space optmization - two rows) */
int knapSack(int W, int wt[], int val[], int n)
{
    vector<int> prev(W + 1, 0), curr(W + 1, 0);
    // base case
    for (int w = wt[0]; w <= W; w++)
        prev[w] = val[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= W; w++)
        {
            int notTake = 0 + prev[w];
            int take = INT_MIN;
            if (wt[ind] <= w)
                take = val[ind] + prev[w - wt[ind]];

            curr[w] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[W];
    /* TC-O(n * W) SC-O(W) */
}

/* method 5 (single row) */
int knapSack(int W, int wt[], int val[], int n)
{
    vector<int> prev(W + 1, 0);
    // base case
    for (int w = wt[0]; w <= W; w++)
        prev[w] = val[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int w = W; w >= 0; w--)// right to left 
        {
            int notTake = 0 + prev[w];
            int take = INT_MIN;
            if (wt[ind] <= w)
                take = val[ind] + prev[w - wt[ind]];

            prev[w] = max(take, notTake);
        }
    }
    return prev[W];
    /* TC-O(n * W) SC-O(W) */
}