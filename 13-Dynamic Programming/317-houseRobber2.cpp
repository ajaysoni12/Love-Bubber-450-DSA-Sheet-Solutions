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
    if (n == 1)
        return nums[0];

    vector<int> temp1, temp2;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(nums[i]);
        if (i != n - 1)
            temp2.push_back(nums[i]);
    }

    return max(solve(temp1.size() - 1, temp1), solve(temp2.size() - 1, temp2));
    /* TC-O(2^n + 2^n) SC-O(2^n + 2^n) */
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
    if (n == 1)
        return nums[0];

    vector<int> temp1, temp2;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(nums[i]);
        if (i != n - 1)
            temp2.push_back(nums[i]);
    }

    vector<int> dp1(temp1.size(), -1), dp2(temp2.size(), -1);
    return max(solve(temp1.size() - 1, temp1, dp1), solve(temp2.size() - 1, temp2, dp2));
    /* TC-O(n + n) SC-O(n + n + n + n) */
}

/* method 3 (using tabulation method) */
int maxNonAdjSum(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];

    vector<int> temp1, temp2;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(nums[i]);
        if (i != n - 1)
            temp2.push_back(nums[i]);
    }

    vector<int> dp1(temp1.size(), -1), dp2(temp2.size(), -1);

    dp1[0] = temp1[0];
    for (int i = 1; i < temp1.size(); i++)
    {
        int pick = temp1[i];
        if (i > 1)
            pick += dp1[i - 2];
        int notPick = 0 + dp1[i - 1];
        dp1[i] = max(pick, notPick);
    }

    dp2[0] = temp2[0];
    for (int i = 1; i < temp2.size(); i++)
    {
        int pick = temp2[i];
        if (i > 1)
            pick += dp2[i - 2];
        int notPick = 0 + dp2[i - 1];
        dp2[i] = max(pick, notPick);
    }

    return max(dp1[temp1.size() - 1], dp2[temp2.size() - 1]);
    /* TC-O(n + n) SC-O(n + n) */
}

/* method 4 (space optimization) */
int solve(vector<int> &nums)
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
}
int maxNonAdjSum(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];

    vector<int> temp1, temp2;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(nums[i]);
        if (i != n - 1)
            temp2.push_back(nums[i]);
    }

    return max(solve(temp1), solve(temp2));
    /* TC-O(n + n) SC-O(1) */
}