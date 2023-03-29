#include <bits/stdc++.h>
using namespace std;

/* method1 (using recursion) */
int solve(int n, vector<int> &height)
{
    if (n == 0)
        return 0;
    int left = solve(n - 1, height) + abs(height[n] - height[n - 1]);
    int right = INT_MAX;
    if (n > 1)
        right = solve(n - 2, height) + abs(height[n] - height[n - 2]);
    return min(left, right);
}
int frogJump(int n, vector<int> &height)
{
    return solve(n, height);
    /* TC-O(2^n) SC-O(2^n) */
}

/* method 2 (using memoization) */
int solve(int n, vector<int> &height, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int left = solve(n - 1, height) + abs(height[n] - height[n - 1]);
    int right = INT_MAX;
    if (n > 1)
        right = solve(n - 2, height) + abs(height[n] - height[n - 2]);
    return dp[n] = min(left, right);
}
int frogJump(int n, vector<int> &height)
{
    vector<int> dp(n + 1, -1);
    solve(n, height, dp);
    /* TC-O(n) SC-O(n + n) */
}

/* method 3 (using tabulation method) */
int frogJump(int n, vector<int> &height)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int left = dp[n - 1] + abs(height[n] - height[n - 1]);
        int right = INT_MAX;
        if (n > 1)
            right = dp[n - 2] + abs(height[n] - height[n - 2]);
        dp[n] = min(left, right);
    }
    return dp[n - 1];
    /* TC-O(n) SC-O(n) */
}

/* method 4 (space optimization) */
int frogJump(int n, vector<int> &height)
{
    int prev2 = 0;
    int prev = 0;
    for (int i = 1; i < n; i++)
    {
        int left = prev + abs(height[n] - height[n - 1]);
        int right = INT_MAX;
        if (n > 1)
            right = prev2 + abs(height[n] - height[n - 2]);
        int curr = min(left, right);
        prev2 = prev;
        prev = curr;
    }
    return prev;
    /* TC-O(n) SC-O(1) */
}