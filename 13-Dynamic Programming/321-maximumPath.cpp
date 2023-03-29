#include <bits/stdc++.h>
using namespace std;

/* method 1 (using recursion) */
int solve(int n, vector<vector<int>> &mat, int i, int j)
{
    if (i >= n or i < 0 or j >= n or j < 0)
        return 0;

    int down = solve(n, mat, i + 1, j);
    int downLeft = solve(n, mat, i + 1, j - 1);
    int downRight = solve(n, mat, i + 1, j + 1);
    return mat[i][j] + max(down, max(downLeft, downRight));
}
int maximumPath(int n, vector<vector<int>> &mat)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
        maxi = max(maxi, solve(n, mat, 0, i));
    return maxi;
}

/* method 2 (using memoization) */
int solve(int n, vector<vector<int>> &mat, int i, int j, vector<vector<int>> &dp)
{
    if (i >= n or i < 0 or j >= n or j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int down = solve(n, mat, i + 1, j);
    int downLeft = solve(n, mat, i + 1, j - 1);
    int downRight = solve(n, mat, i + 1, j + 1);
    return dp[i][j] = mat[i][j] + max(down, max(downLeft, downRight));
}
int maximumPath(int n, vector<vector<int>> &mat)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        maxi = max(maxi, solve(n, mat, 0, i, dp));
    }
    return maxi;
}

/* method 3 (using tabulation method) */
int maximumPath(int n, vector<vector<int>> &mat)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int ans = INT_MIN;

    for (int j = 0; j < n; j++)
        dp[n - 1][j] = mat[n - 1][j];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {

            int down = dp[i + 1][j];
            int downLeft = (j - 1) >= 0 ? dp[i + 1][j - 1] : 0;
            int downRight = (j + 1) < n ? dp[i + 1][j + 1] : 0;

            dp[i][j] = mat[i][j] + max(down, max(downRight, downLeft));
            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}