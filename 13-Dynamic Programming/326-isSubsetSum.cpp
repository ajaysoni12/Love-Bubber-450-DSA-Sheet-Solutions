#include <bits/stdc++.h>
using namespace std;

/* method 1 (recursion) */
bool f(vector<int> &arr, int sum, int ind)
{
    if (sum == 0)
        return true;
    if (ind == 0)
        return (sum == arr[0]);

    bool notTake = f(arr, sum, ind - 1);
    bool take = false;
    if (sum >= arr[ind])
        take = f(arr, sum - arr[ind], ind - 1);
    return notTake | take;
}
bool isSubsetSum(vector<int> arr, int sum)
{
    return f(arr, sum, arr.size() - 1);
    /* TC-O(2^n) SC-O(sum) */
}

/* method 2 (memoization) */
bool f(vector<int> &arr, int sum, int ind, vector<vector<int>> &dp)
{
    if (sum == 0)
        return true;
    if (ind == 0)
        return (sum == arr[0]);
    if (dp[ind][sum] != -1)
        return dp[ind][sum];

    bool notTake = f(arr, sum, ind - 1, dp);
    bool take = false;
    if (sum >= arr[ind])
        take = f(arr, sum - arr[ind], ind - 1, dp);
    return dp[ind][sum] = notTake | take;
}
bool isSubsetSum(vector<int> arr, int sum)
{
    vector<vector<int>> dp(arr.size(), vector<int>(sum + 1, -1));
    return f(arr, sum, arr.size() - 1, dp);
    /* TC-O(n*sum) SC-O(n*sum + o(sum) )*/
}

/* method 3 (tabulation) */
bool isSubsetSum(vector<int> arr, int sum)
{
    vector<vector<bool>> dp(arr.size(), vector<bool>(sum + 1, 0));

    for (int i = 0; i < arr.size(); i++)
        dp[i][0] = true;

    dp[0][arr[0]] = true;

    for (int ind = 1; ind < arr.size(); ind++)
    {
        for (int target = 0; target <= sum; target++)
        {
            bool notTake = dp[ind - 1][target];
            bool take = false;
            if (target >= arr[ind])
                take = dp[ind - 1][target - arr[ind]];
            dp[ind][target] = notTake | take;
        }
    }
    return dp[arr.size() - 1][sum];
    /* TC-O(n*sum) SC-O(n*sum)*/
}

/* method 4 (space optimization) */
bool isSubsetSum(vector<int> arr, int sum)
{
    vector<bool> prev(sum + 1, 0), curr(sum + 1, 0);
    prev[0] = curr[0] = true;

    prev[arr[0]] = true;

    for (int ind = 1; ind < arr.size(); ind++)
    {
        for (int target = 0; target <= sum; target++)
        {
            bool notTake = prev[target];
            bool take = false;
            if (target >= arr[ind])
                take = prev[target - arr[ind]];
            curr[target] = notTake | take;
        }
        prev = curr;
    }
    return prev[sum];
    /* TC-O(n*sum) SC-O(sum)*/
}