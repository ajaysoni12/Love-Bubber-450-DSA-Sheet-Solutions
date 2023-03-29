#include <bits/stdc++.h>
using namespace std;

/* method 1 (recursion) */
int solve(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid)
{
    // out of bound case
    if (j1 < 0 or j2 < 0 or j1 >= c or j2 >= c)
        return -1e8;

    // we reach variable point from fixed point
    if (i == r - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    // explore all path of alice and bob symultaneously
    int maxi = -1e8;

    // alice path
    for (int dj1 = -1; dj1 <= +1; dj1++)
    {
        // bob path
        for (int dj2 = -1; dj2 <= +1; dj2++)
        {
            int value = 0;
            if (j1 == j2)
                value = grid[i][j1];
            else
                value = grid[i][j1] + grid[i][j2];
            value += solve(i + 1, j1 + dj1, j2 + dj2, r, c, grid);
            maxi = max(maxi, value);
        }
    }
    return maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    return solve(0, 0, c - 1, r, c, grid);
    /* TC - O(3^n*3^n) SC-O(n) */
}

/* method 2 (memoization) */
int solve(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid,
          vector<vector<vector<int>>> &dp)
{
    // out of bound case
    if (j1 < 0 or j2 < 0 or j1 >= c or j2 >= c)
        return -1e8;

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    // we reach variable point from fixed point
    if (i == r - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    // explore all path of alice and bob symultaneously
    int maxi = -1e8;
 
    // alice path
    for (int dj1 = -1; dj1 <= +1; dj1++)
    {
        // bob path
        for (int dj2 = -1; dj2 <= +1; dj2++)
        {
            int value = 0;
            if (j1 == j2)
                value = grid[i][j1];
            else
                value = grid[i][j1] + grid[i][j2];
            value += solve(i + 1, j1 + dj1, j2 + dj2, r, c, grid);
            maxi = max(maxi, value);
        }
    }
    return dp[i][j1][j2] = maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    // int dp[r][c][c];
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return solve(0, 0, c - 1, r, c, grid, dp);
    /* TC - O(n*m*m) SC-O(n*m*m + o(n) ) */
}

/* method 3 (tabulation) */
