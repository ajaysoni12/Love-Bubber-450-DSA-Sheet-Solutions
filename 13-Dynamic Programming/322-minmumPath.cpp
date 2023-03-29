#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<vector<int>> &grid)
{
    // base case
    if (i == 0 and j == 0)
        return grid[0][0];

    // out of the boundary
    if (i < 0 or j < 0)
        return INT_MAX;

    int up = grid[i][j] + solve(i - 1, j, grid);
    int left = grid[i][j] + solve(i, j - 1, grid);
    return min(up, left);
}
int minPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    return solve(n - 1, m - 1, grid);
    /* TC-O(2^n*m) SC-O(n*m) */
}

/* method 2 (using memoization) */
int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    // base case
    if (i == 0 and j == 0)
        return grid[0][0];

    // out of the boundary
    if (i < 0 or j < 0)
        return INT_MAX;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = grid[i][j] + solve(i - 1, j, grid, dp);
    int left = grid[i][j] + solve(i, j - 1, grid, dp);
    return dp[i][j] = min(up, left);
}
int minPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n - 1, m - 1, grid, dp);
    /* TC-O(n*m) SC-O(n*m + pathLength(n-1 + m-1)) */
}

/* method 3 (using tabulation) */
int minPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    if (n == 1 and m == 1)
        return grid[0][0];
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 and j == 0)
                dp[i][j] = grid[0][0];
            else
            {
                int up = grid[i][j];
                if (i > 0)
                    up += dp[i - 1][j];
                else
                    up += 1e9;

                int left = grid[i][j];
                if (j > 0)
                    left += dp[i][j - 1];
                else
                    left += 1e9;
                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[n - 1][m - 1];
    /* TC-O(n*m) SC-O(n*m) */
}

/* method 4 (space optimization) */
int minPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<int> prevRow(m, 0); // prev row

    for (int i = 0; i < n; i++)
    {
        vector<int> currRow(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 and j == 0)
                currRow[j] = grid[0][0];
            else
            {
                int up = grid[i][j];
                // prev row jth column
                if (i > 0)
                    up += prevRow[j];
                else
                    up += 1e9;
                int left = grid[i][j];
                // curr row j-1th column
                if (j > 0)
                    left += currRow[j - 1];
                else
                    left += 1e9;
                currRow[j] = min(up, left);
            }
        }
        prevRow = currRow;
    }
    return prevRow[m - 1];
    /* TC-O(n*m) SC-O(n*m) */
}