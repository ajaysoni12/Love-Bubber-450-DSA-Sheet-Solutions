#include <bits/stdc++.h>
using namespace std;

/* method 1 (recursion) */
int f(int i, int j, vector<int> &a)
{
    if (i > j)
        return 0;
    int maxi = INT_MIN;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = a[i - 1] * a[ind] * a[j + 1] + f(i, ind - 1, a) + f(ind + 1, j, a);
        maxi = max(maxi, cost);
    }
    return maxi;
}
int maxCoins(int n, vector<int> &arr)
{
    arr.push_back(1);
    arr.insert(arr.begin(), 1);
    return f(1, n, arr);
    /* TC-O(expo) SC-O(n) */
}

/* method 2 (memoization) */
int f(int i, int j, vector<int> &a, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    int maxi = INT_MIN;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = a[i - 1] * a[ind] * a[j + 1] + f(i, ind - 1, a, dp) + f(ind + 1, j, a, dp);
        maxi = max(maxi, cost);
    }
    return dp[i][j] = maxi;
}
int maxCoins(int n, vector<int> &arr)
{
    arr.push_back(1);
    arr.insert(arr.begin(), 1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return f(1, n, arr, dp);
    /* TC-O(n*n*n) SC-O(n*n + n) */
}