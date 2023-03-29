#include <bits/stdc++.h>
using namespace std;

/* method 1 (using recursion) */
int solve(int n, int k, vector<int> &height)
{
    if (n == 0)
        return 0;

    int minSteps = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        int fs = solve(n - j, k, height) + abs(height[n] - height[n - j]);
        minSteps = min(minSteps, fs);
    }
    return minSteps;
}
int frogJump(int n, int k, vector<int> &height)
{
    return solve(n, k, height);
    /* TC-O(n^k) SC-O(n^k) */
}

/* method 2 (using memoization) */
int solve(int n, int k, vector<int> &height, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int minSteps = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        int fs = solve(n - j, k, height, dp) + abs(height[n] - height[n - j]);
        minSteps = min(minSteps, fs);
    }
    return minSteps;
}
int frogJump(int n, int k, vector<int> &height)
{
    vector<int> dp(n + 1, -1);
    solve(n, k, height, dp);
    /* TC-O(n*k) SC-O(n + n) */
}

/* method 3 (using tabulation method) */
int frogJump(int n, int k, vector<int> &height)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int minSteps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            int fs = solve(n - j, k, height, dp) + abs(height[n] - height[n - j]);
            minSteps = min(minSteps, fs);
        }
        return minSteps;
    }
    return dp[n - 1];
    /* TC-O(n*k) SC-O(n) */
}
