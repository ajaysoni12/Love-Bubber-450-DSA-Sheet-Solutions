#include <bits/stdc++.h>
using namespace std;

/* method 1 (using recursion) */
int nthStair(int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    return nthStair(n - 2) + 1;
    /* TC-O(2^n) SC-O(2^n) */
}

/* method 2 (using memoization) */
int solve(int n, vector<int> &dp)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = solve(n - 2, dp) + 1;
}
int nthStair(int n)
{
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
    /* TC-O(n) SC-O(n + n) */
}

/* method 3 (using tabulation method) */
int nthStair(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        dp[i] = dp[i - 2] + 1;
    return dp[n]; 
    /* TC-O(n) SC-O(n)*/
}

/* method 4 (space optimization) */
int nthStair(int n)
{
    return n / 2 + 1;
}