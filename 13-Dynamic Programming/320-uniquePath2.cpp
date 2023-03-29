#include <bits/stdc++.h>
using namespace std;

/* method 1 (using recursion) */
int solve(int i, int j, vector<vector<int>> &mat)
{
    if (i >= 0 and j >= 0 and mat[i][j] == 1)
        return 0;
    if (i == 0 and j == 0)
        return 1;
    if (i < 0 or j < 0)
        return 0;

    int up = solve(i - 1, j, mat);
    int left = solve(i, j - 1, mat);
    return up + left;
}
int uniquePathsWithObstacles(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();
    return solve(0, 0, mat);
    /* TC-O(2^a*b) SC-O(m * n) */
}

/* method 2 (using memoization) */
int solve(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    if (i >= 0 and j >= 0 and mat[i][j] == 1)
        return 0;
    if (i == 0 and j == 0)
        return 1;
    if (i < 0 or j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = solve(i - 1, j, mat);
    int left = solve(i, j - 1, mat);
    return dp[i][j] = up + left;
}
int uniquePathsWithObstacles(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(0, 0, mat, dp);
    /* TC-O(a*b) SC-O(path length or (a-1)+(b-1)) */
}

/* method 3 (using tabulation method) */
int uniquePathsWithObstacles(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (i >= 0 and j >= 0 and mat[i][j] == 1)
                dp[i][j] = 0;
            else if (i == 0 and j == 0)
                dp[i][j] = 1;
            else
            {
                int down = 0, right = 0;
                if (i > 0)
                    down = dp[i - 1][j]; // up
                if (j > 0)
                    right = dp[i][j - 1]; // left
                dp[i][j] = down + right;
            }
        }
    }
    return dp[n - 1][m - 1];
    /* TC-O(a*b) SC-O(a*b(dp space)) */
}

/* method 4 (space optimization) */
int NumberOfPath(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();
    vector<int> dp(m, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        vector<int> temp(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i >= 0 and j >= 0 and mat[i][j] == 1)
                temp[j] = 0;
            else if (i == 0 and j == 0)
                temp[j] = 1;
            else
            {
                int down = 0, right = 0;
                if (i > 0)
                    down = dp[j]; // up and prev (i-1)
                if (j > 0)
                    right = temp[j - 1]; // left
                temp[j] = down + right;
            }
        }
        dp = temp;
    }
    return dp[m - 1];
    /* TC-O(a*b) SC-O(a + b) */
}