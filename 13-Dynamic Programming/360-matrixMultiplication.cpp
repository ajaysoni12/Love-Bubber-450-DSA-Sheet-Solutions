#include <bits/stdc++.h>
using namespace std;

/* method 1 (recursion) */
int f(int i, int j, int arr[])
{
    if (i == j)
        return 0;
    int mini = 1e8;
    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + f(i, k, arr) + f(k + 1, j, arr);
        mini = min(mini, steps);
    }
    return mini;
}
int matrixMultiplication(int N, int arr[])
{
    return f(1, N - 1, arr);
    /* TC-O(expo) SC-O(n) */
}

/* method 2 (memoization) */
int f(int i, int j, int arr[], vector<vector<int>> &dp)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    int mini = 1e8;
    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k + 1, j, arr, dp);
        mini = min(mini, steps);
    }
    return dp[i][j] = mini;
}
int matrixMultiplication(int N, int arr[])
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return f(1, N - 1, arr, dp);
    /* TC-O(n^3) SC-O(n*n + n) */
}

/* method 3 (tabulation) */
int matrixMultiplication(int N, int arr[])
{
    int dp[N][N];
    for (int i = 1; i < N; i++)
        dp[i][i] = 0;

    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            int mini = 1e9;
            for (int k = i; k < j; k++)
            {
                int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                if (steps < mini)
                    mini = steps;
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][N - 1];
    /* TC-O(n^3) SC-O(n*n) */
}