#include <bits/stdc++.h>
using namespace std;

/* method 1 (using recursion way) */
int solve(int i, int j)
{
    // we reach
    if (i == 0 and j == 0)
        return 1;

    // out of the grid
    if (i < 0 or j < 0)
        return 0;

    int up = solve(i - 1, j);   // down
    int left = solve(i, j - 1); // right
    return up + left;           // total ways
}
int NumberOfPath(int a, int b)
{
    return solve(a - 1, b - 1);
    /* TC-O(2^a*b) SC-O(m * n) */
}

/* method 2 (using memoization - overlapping sub problem) */
int solve(int i, int j, vector<vector<int>> &dp)
{
    // we reach
    if (i == 0 and j == 0)
        return 1;

    // out of the grid
    if (i < 0 or j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = solve(i - 1, j);    // down
    int left = solve(i, j - 1);  // right
    return dp[i][j] = up + left; // total ways
}
int NumberOfPath(int a, int b)
{
    vector<vector<int>> dp(a, vector<int>(b, -1));
    return solve(a, b, dp);
    /* TC-O(a*b) SC-O((a-1)+(b-1)(recursion space) + a*b(dp space)) */
}

/* method 3 (using tabulation method) */
int NumberOfPath(int a, int b)
{
    vector<vector<int>> dp(a, vector<int>(b, -1));
    dp[0][0] = 1;

    for (int i = 0; i < a; i++)
    {
        for (int j = 1; j < b; j++)
        {
            if (i == 0 and j == 0)
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
    return dp[a - 1][b - 1];
    /* TC-O(a*b) SC-O(a*b(dp space)) */
}

/* method 4 (space optimization) */
int NumberOfPath(int a, int b)
{
    vector<int> dp(b, 0);
    dp[0] = 1;

    for (int i = 0; i < a; i++)
    {
        vector<int> temp(b, 0);
        for (int j = 0; j < b; j++)
        {
            if (i == 0 and j == 0)
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
    return dp[b - 1];
    /* TC-O(a*b) SC-O(a + b) */
}