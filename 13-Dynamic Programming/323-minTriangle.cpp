#include <bits/stdc++.h>
using namespace std;

/* method 1 (using recursion) */
int solve(int i, int j, vector<vector<int>> &triangle, int n)
{
    // we reach last row
    if (i == n - 1)
        return triangle[i][j];
    int down = triangle[i][j] + solve(i + 1, j, triangle, n);
    int downDiagonal = triangle[i][j] + solve(i + 1, j + 1, triangle, n);
    return min(down, downDiagonal);
}
int minPathSum(vector<vector<int>> &triangle, int n)
{
    return solve(0, 0, triangle, n);
    /* TC-O(2^n*m - no. of row and no. of column) SC-O(n) */
}

/* method 2 (using memoization) */
int solve(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
{
    // we reach last row
    if (i == n - 1)
        return triangle[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int down = triangle[i][j] + solve(i + 1, j, triangle, n);
    int downDiagonal = triangle[i][j] + solve(i + 1, j + 1, triangle, n);
    return dp[i][j] = min(down, downDiagonal);
}
int minPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(0, 0, triangle, n, dp);
    /* TC-O(n*m - no. of row and no. of column) SC-O(n + n*m) */
}

/* method 3 (using tabulation method) */
int minPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // compute last row
    for (int j = 0; j < n; j++)
        dp[n - 1][j] = triangle[n - 1][j];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int downDiagonal = triangle[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(down, downDiagonal);
        }
    }
    return dp[0][0];
    /* TC-O(n*m - no. of row and no. of column) SC-O(n*m) */
}

/* method 4 (space optmization) */
int minPathSum(vector<vector<int>> &triangle, int n)
{
    vector<int> front(n, 0);

    // compute last row
    for (int j = 0; j < n; j++)
        front[j] = triangle[n - 1][j];

    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> curr(n, 0);
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + front[j];
            int downDiagonal = triangle[i][j] + front[j + 1];
            curr[j] = min(down, downDiagonal);
        }
        front = curr;
    }
    return front[0];
    /* TC-O(n*m - no. of row and no. of column) SC-O(n + n) */
}