#include <bits/stdc++.h>
using namespace std;

/* method 1 (using recursion) */
bool f(int arr[], int sum, int ind)
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
int equalPartition(int n, int arr[])
{
    int totSum = 0;
    for (int i = 0; i < n; i++)
        totSum += arr[i];

    if (totSum % 2)
        return false;
    int target = totSum / 2;
    return f(arr, target, n - 1);
    /* TC-O(2^n + n) SC-O(n) */
}

/* method 2 (using memoization) */
bool f(int arr[], int sum, int ind, vector<vector<int>> &dp)
{
    if (sum == 0)
        return true;
    if (ind == 0)
        return (sum == arr[0]);

    if (dp[ind][sum] != -1)
        return dp[ind][sum];

    bool notTake = f(arr, sum, ind - 1);
    bool take = false;
    if (sum >= arr[ind])
        take = f(arr, sum - arr[ind], ind - 1);
    return dp[ind][sum] = notTake | take;
}
int equalPartition(int n, int arr[])
{
    int totSum = 0;
    for (int i = 0; i < n; i++)
        totSum += arr[i];

    if (totSum % 2)
        return false;
    int target = totSum / 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return f(arr, target, n - 1, dp);
    /* TC-O(n*target + n) SC-O(n) */
}

/* method 3 (tabulation) */
bool isSubsetSum(vector<int> arr, int sum)
{
    vector<vector<bool>> dp(arr.size(), vector<bool>(sum + 1, 0));

    for (int i = 0; i < arr.size(); i++)
        dp[i][0] = true;

    dp[0][arr[sum]] = true;

    for (int ind = 1; ind < arr.size(); ind++)
    {
        for (int target = 0; target <= sum; target++)
        {
            bool notTake = dp[ind - 1][sum];
            bool take = false;
            if (sum >= arr[ind])
                take = dp[ind - 1][sum - arr[ind]];
            dp[ind][sum] = notTake | take;
        }
    }
    return dp[arr.size() - 1][sum];
    /* TC-O(n*sum) SC-O(n*sum)*/
}

int equalPartition(int n, vector<int> arr)
{
    int totSum = 0;
    for (int i = 0; i < n; i++)
        totSum += arr[i];

    if (totSum % 2)
        return false;
    int target = totSum / 2;
    return isSubsetSum(arr, target);
    /* TC-O(n*target + n) SC-O(n) */
}