#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<vector<int>> &mat)
{
    // out of bound case
    if (j < 0 or j >= mat[0].size())
        return -1e8;

    // we reach
    if (i == 0)
        return mat[0][j];

    int up = mat[i][j] + solve(i - 1, j, mat);
    int ld = mat[i][j] + solve(i - 1, j - 1, mat);
    int rd = mat[i][j] + solve(i - 1, j + 1, mat);
    return max(up, max(ld, rd));
}
int getMaxPathSum(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    int maxi = -1e8;
    for (int j = 0; j < m; j++)
        maxi = max(maxi, solve(n - 1, j, mat));
    return maxi;
    /* TC-O(3^n) SC-O(n) */
}

/* method 2 (using memoization) */
int solve(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    // out of bound case
    if (j < 0 or j >= mat[0].size())
        return -1e8;

    // we reach
    if (i == 0)
        return mat[0][j];

    // prevously computed
    if (dp[i][j] != -1)
        return dp[i][j];

    int up = mat[i][j] + solve(i - 1, j, mat, dp);
    int ld = mat[i][j] + solve(i - 1, j - 1, mat, dp);
    int rd = mat[i][j] + solve(i - 1, j + 1, mat, dp);
    return dp[i][j] = max(up, max(ld, rd));
}
int getMaxPathSum(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    int maxi = -1e8;
    for (int j = 0; j < m; j++)
        maxi = max(maxi, solve(n - 1, j, mat, dp));
    return maxi;
    /* TC-O(n*m) SC-O(n*m + path length(n) ) */
}

/* method 3 (using tabulation) */
int getMaxPathSum(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    // base case
    for (int j = 0; j < m; j++)
        dp[0][j] = mat[0][j];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = mat[i][j] + dp[i - 1][j];
            int ld = mat[i][j];
            if (j - 1 >= 0)
                ld += dp[i - 1][j - 1];
            else
                ld += -1e8;

            int rd = mat[i][j];
            if (j + 1 < m)
                rd += dp[i - 1][j + 1];
            else
                rd += -1e8;
            dp[i][j] = max(up, max(ld, rd));
        }
    }

    int maxi = -1e8;
    for (int j = 0; j < m; j++)
        maxi = max(maxi, dp[n - 1][j]);
    return maxi;
    /* TC-O(n*m) SC-O(n*m) */
}

/* method 4 (using space optmization) */
int getMaxPathSum(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    vector<int> prev(m, 0);

    // base case
    for (int j = 0; j < m; j++)
        prev[j] = mat[0][j];

    for (int i = 1; i < n; i++)
    {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++)
        {
            int up = mat[i][j] + prev[j];
            int ld = mat[i][j];
            if (j - 1 >= 0)
                ld += prev[j - 1];
            else
                ld += -1e8;

            int rd = mat[i][j];
            if (j + 1 < m)
                rd += prev[j + 1];
            else
                rd += -1e8;
            curr[j] = max(up, max(ld, rd));
        }
        prev = curr;
    }

    int maxi = -1e8;
    for (int j = 0; j < m; j++)
        maxi = max(maxi, prev[j]);
    return maxi;
    /* TC-O(n*m) SC-O(n*m) */
}