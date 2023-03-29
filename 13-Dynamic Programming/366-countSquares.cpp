#include <bits/stdc++.h>
using namespace std;

/* method 1 (tabulation way) */
int countSquares(int n, int m, vector<vector<int>> &matrix)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int j = 0; j < m; j++)
        dp[0][j] = matrix[0][j];
    for (int i = 0; i < n; i++)
        dp[i][0] = matrix[i][0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == 0)
                dp[i][j] = 0;
            else
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            sum += dp[i][j];
    return sum;
    /* TC-O(n*m) SC-O(n*m + n*m)*/
}