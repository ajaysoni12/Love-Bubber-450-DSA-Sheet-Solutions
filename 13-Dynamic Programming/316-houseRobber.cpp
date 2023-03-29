#include <bits/stdc++.h>
using namespace std;

/* method 1 (using recursion) */
int solve(int ind, vector<int> &nums)
{
    if (ind == 0)
        return nums[ind];
    if (ind < 0)
        return 0;

    int pick = nums[ind] + solve(ind - 2, nums);
    int notPick = 0 + solve(ind - 1, nums);
    return max(pick, notPick);
}
int maxNonAdjSum(vector<int> &nums)
{
    int n = nums.size();
    return solve(n - 1, nums);
    /* TC-O(2^n) SC-O(2^n) */
}

/* method 2 (using memoization) */
int solve(int ind, vector<int> &nums, vector<int> &dp)
{
    if (ind == 0)
        return nums[ind];
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int pick = nums[ind] + solve(ind - 2, nums);
    int notPick = 0 + solve(ind - 1, nums);
    return dp[ind] = max(pick, notPick);
}
int maxNonAdjSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return solve(n - 1, nums, dp);
    /* TC-O(n) SC-O(n + n) */
}

/* method 3 (using tabulation method) */
int maxNonAdjSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    dp[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i > 1)
            pick += dp[i - 2];
        int notPick = 0 + dp[i - 1];
        dp[i] = max(pick, notPick);
    }
    return dp[n - 1];
    /* TC-O(n) SC-O(n) */
}

/* method 4 (space optimization) */
int maxNonAdjSum(vector<int> &nums)
{
    int n = nums.size();
    int prev2 = 0;      // neg = 0
    int prev = nums[0]; // dp[0]

    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i > 1)
            pick += prev2;
        int notPick = 0 + prev;
        int curr = max(pick, notPick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
    /* TC-O(n) SC-O(1) */
}