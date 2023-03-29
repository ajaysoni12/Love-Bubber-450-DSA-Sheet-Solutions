#include <bits/stdc++.h>
using namespace std;

/* method 1 (recursion) */
int f(int ind, int N, int price[])
{
    if (ind == 0)
        return N * price[0];

    int notTake = 0 + f(ind - 1, N, price);
    int take = INT_MIN;
    int rodLength = ind + 1;
    if (rodLength <= N)
        take = price[ind] + f(ind, N - rodLength, price);
    return max(notTake, take);
}
int cutRod(int price[], int n)
{
    return f(n - 1, n, price);
    /* TC-O(exponential) SC-O(>>n) */
}

/* method 2 (memoization) */
int f(int ind, int N, int price[], vector<vector<int>> &dp)
{
    if (ind == 0)
        return N * price[0];

    if (dp[ind][N] != -1)
        return dp[ind][N];
    int notTake = 0 + f(ind - 1, N, price, dp);
    int take = INT_MIN;
    int rodLength = ind + 1;
    if (rodLength <= N)
        take = price[ind] + f(ind, N - rodLength, price, dp);
    return dp[ind][N] = max(notTake, take);
}
int cutRod(int price[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(n - 1, n, price, dp);
    /* TC-O(n*n) SC-O(n*n + >>n) */
}

/* methyod 3 (tabulation) */
int cutRod(int price[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    for (int N = 0; N <= n; N++)
        dp[0][N] = N * price[0];

    for (int ind = 1; ind <= n; ind++)
    {
        for (int N = 0; N <= n; N++)
        {
            int notTake = 0 + dp[ind - 1][N];
            int take = INT_MIN;
            int rodLength = ind + 1;
            if (rodLength <= N)
                take = price[ind] + dp[ind][N - rodLength];
            dp[ind][N] = max(notTake, take);
        }
    }
    return dp[n - 1][n];
    /* TC-O(n*n) SC-O(n*n) */
}

/* method 4 (space optimization - 2 array) */
int cutRod(int price[], int n)
{
    vector<int> prev(n + 1, 0), curr(n + 1, 0);

    for (int N = 0; N <= n; N++)
        prev[N] = N * price[0];

    for (int ind = 1; ind <= n; ind++)
    {
        for (int N = 0; N <= n; N++)
        {
            int notTake = 0 + prev[N];
            int take = INT_MIN;
            int rodLength = ind + 1;
            if (rodLength <= N)
                take = price[ind] + curr[N - rodLength];
            curr[N] = max(notTake, take);
        }
    }
    return prev[n];
    /* TC-O(n*n) SC-O(n + n) */
}

/* method 5(space optimization - 1d array) */
int cutRod(int price[], int n)
{
    vector<int> prev(n + 1, 0);

    for (int N = 0; N <= n; N++)
        prev[N] = N * price[0];

    for (int ind = 1; ind <= n; ind++)
    {
        for (int N = 0; N <= n; N++)
        {
            int notTake = 0 + prev[N];
            int take = INT_MIN;
            int rodLength = ind + 1;
            if (rodLength <= N)
                take = price[ind] + prev[N - rodLength];
            prev[N] = max(notTake, take);
        }
    }
    return prev[n];
    /* TC-O(n*n) SC-O(n) */
}