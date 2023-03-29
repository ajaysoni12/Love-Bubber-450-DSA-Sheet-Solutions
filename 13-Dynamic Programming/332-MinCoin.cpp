#include <bits/stdc++.h>
using namespace std;

/* method 1 (using recursion) */
int f(int ind, int T, vector<int> &nums)
{
    if (ind == 0)
    {
        if (T % nums[0] == 0)
            return T / nums[0];
        return 1e8;
    }

    int notTake = 0 + f(ind - 1, T, nums);
    int take = INT_MAX;
    if (nums[ind] <= T)
        take = 1 + f(ind, T - nums[ind], nums); // infinte numbers of coints
    return min(take, notTake);
}
int MinCoin(vector<int> nums, int amount)
{
    int n = nums.size();
    int ans = f(n - 1, amount, nums);
    if (ans >= 1e9)
        return -1;
    return ans;
    /* TC-O(2^n or exponential) SC-O(n or maybe more)*/
}

/* method 2 (using memoization) */
int f(int ind, int T, vector<int> &nums, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (T % nums[0] == 0)
            return T / nums[0];
        return 1e8;
    }

    if (dp[ind][T] != -1)
        return dp[ind][T];

    int notTake = 0 + f(ind - 1, T, nums);
    int take = INT_MAX;
    if (nums[ind] <= T)
        take = 1 + f(ind, T - nums[ind], nums); // infinte numbers of coints
    return dp[ind][T] = min(take, notTake);
}
int MinCoin(vector<int> nums, int amount)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ans = f(n - 1, amount, nums, dp);
    if (ans >= 1e9)
        return -1;
    return ans;
    /* TC-O(n*m) SC-O(n*m + n)*/
}

/* method 3 (tabulation) */
int MinCoin(vector<int> nums, int amount)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    for (int T = 0; T <= amount; T++)
    {
        if (T % nums[0] == 0)
            dp[0][T] = T / nums[0];
        else
            dp[0][T] = 1e8;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int T = 0; T <= amount; T++)
        {
            int notTake = 0 + dp[ind - 1][T];
            int take = INT_MAX;
            if (nums[ind] <= T)
                take = 1 + dp[ind][T - nums[ind]];
            dp[ind][T] = min(take, notTake);
        }
    }

    if (dp[n - 1][amount] >= 1e9)
        return -1;
    return dp[n - 1][amount];
    /* TC-O(n*m) SC-O(n*m)*/
}

/* method 4 (space optimization) */
int MinCoin(vector<int> nums, int amount)
{
    int n = nums.size();
    vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

    for (int T = 0; T <= amount; T++)
    {
        if (T % nums[0] == 0)
            prev[T] = T / nums[0];
        else
            prev[T] = 1e8;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int T = 0; T <= amount; T++)
        {
            int notTake = 0 + prev[T];
            int take = INT_MAX;
            if (nums[ind] <= T)
                take = 1 + prev[T - nums[ind]];
            curr[T] = min(take, notTake);
        }
        prev = curr;
    }

    if (prev[amount] >= 1e8)
        return -1;
    return prev[amount];
    /* TC-O(n * amount) SC-O(m) */
}