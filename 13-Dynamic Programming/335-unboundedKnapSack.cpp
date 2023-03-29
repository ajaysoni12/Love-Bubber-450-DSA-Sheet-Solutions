#include <bits/stdc++.h>
using namespace std;

/* method 1 (using recursion) */
int f(int ind, int W, int val[], int wt[])
{
    if (ind == 0)
        return ((int)(W / wt[0]) * val[0]);

    int notTake = f(ind - 1, W, val, wt);
    int take = 0;
    if (wt[ind] <= W)
        take = val[ind] + f(ind, W - wt[ind], val, wt);
    return max(notTake, take);
}
int knapSack(int n, int W, int val[], int wt[])
{
    return f(n - 1, W, val, wt);
    /* TC-(exponential) SC-O(>>n) */
}

/* method 2 (memoization) */
int f(int ind, int W, int val[], int wt[], vector<vector<int>> &dp)
{
    if (ind == 0)
        return ((int)(W / wt[0]) * val[0]);

    if (dp[ind][W] != -1)
        return dp[ind][W];

    int notTake = f(ind - 1, W, val, wt, dp);
    int take = 0;
    if (wt[ind] <= W)
        take = val[ind] + f(ind, W - wt[ind], val, wt, dp);
    return dp[ind][W] = max(notTake, take);
}
int knapSack(int n, int W, int val[], int wt[])
{
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return f(n - 1, W, val, wt, dp);
    /* TC-(n*sum) SC-O(n*sum + >>n) */
}

/* method 3 (tabulation) */
int knapSack(int n, int W, int val[], int wt[])
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    for (int w = 0; w <= W; w++)
        dp[0][w] = ((int)(w / wt[0]) * val[0]);

    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= W; w++)
        {
            int notTake = dp[ind - 1][w];
            int take = 0;
            if (wt[ind] <= w)
                take = val[ind] + dp[ind][w - wt[ind]];
            dp[ind][w] = max(notTake, take);
        }
    }
    return dp[n - 1][W];
    /* TC-(n*sum) SC-O(n*sum + >>n) */
}

/* method 4 (space optimization) */
int knapSack(int n, int W, int val[], int wt[])
{
    vector<int> prev(W + 1, 0), curr(W + 1, 0);
    for (int w = 0; w <= W; w++)
        prev[w] = ((int)(w / wt[0]) * val[0]);

    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= W; w++)
        {
            int notTake = prev[w];
            int take = 0;
            if (wt[ind] <= w)
                take = val[ind] + curr[w - wt[ind]];
            curr[w] = max(notTake, take);
        }
    }
    return prev[W];
    /* TC-(n*sum) SC-O(n*sum + >>n) */
}
