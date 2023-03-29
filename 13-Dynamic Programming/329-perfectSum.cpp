#include <bits/stdc++.h>
using namespace std;

/* method 1 (using recursion) */
int f(int arr[], int ind, int sum)
{
    if (ind == 0)
    {
        if (sum == 0 and arr[0])
            return 2;
        if (sum == 0 or sum == arr[0])
            return 1;
        return 0;
    }

    int notTake = f(arr, ind - 1, sum);
    int take = 0;
    if (arr[ind] <= sum)
        take = f(arr, ind - 1, sum - arr[ind]);

    return take + notTake;
}
int perfectSum(int arr[], int n, int sum)
{
    return f(arr, n - 1, sum);
    /* TC-O(2^n) SC-O(n) */
}

/* method 2 (memoization) */
int f(int arr[], int ind, int sum, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (sum == 0 and arr[0])
            return 2;
        if (sum == 0 or sum == arr[0])
            return 1;
        return 0;
    }

    if (dp[ind][sum] != -1)
        return dp[ind][sum];

    int notTake = f(arr, ind - 1, sum, dp);
    int take = 0;
    if (arr[ind] <= sum)
        take = f(arr, ind - 1, sum - arr[ind], dp);

    return dp[ind][sum] = take + notTake;
}
int perfectSum(int arr[], int n, int sum)
{
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return f(arr, n - 1, sum, dp);
    /* TC-O(n*sum) SC-O(n*sum + o(n)) */
}

/* method 3 (tabulation) */
int perfectSum(int arr[], int n, int sum)
{
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

    // base case
    for (int ind = 0; ind < n; ind++)
        dp[ind][0] = 1;

    if (arr[0] <= sum)
        dp[0][arr[0]] = 1;

    if (arr[0] == 0)
        dp[0][0] = 2;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= sum; target++)
        {
            int notTake = dp[ind - 1][target];
            int take = 0;
            if (arr[ind] <= target)
                take = dp[ind - 1][target - arr[ind]];

            dp[ind][target] = take + notTake;
        }
    }
    return dp[n - 1][sum];
    /* TC-O(n*sum) SC-O(n*sum + o(n)) */
}

/* method 4 (space optimization) */
int perfectSum(int arr[], int n, int sum)
{
    int mod = (int)1000000007;
    vector<int> prev(sum + 1, 0), curr(sum + 1, 0);
    prev[0] = curr[0] = 1; // target becomes zero
    if (arr[0] <= sum)
        prev[arr[0]] = 1;

    if (arr[0] == 0)
        prev[0] = 2;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            int notPick = prev[j];
            int pick = 0;
            if (arr[i] <= j)
                pick = prev[j - arr[i]];
            curr[j] = (pick + notPick) % mod;
        }
        prev = curr;
    }

    return prev[sum] % mod;
}