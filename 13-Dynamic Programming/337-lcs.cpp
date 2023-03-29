#include <bits/stdc++.h>
using namespace std;

/* method 1 (using recursion) */
int f(int i, int j, string &s1, string &s2)
{
    if (i < 0 or j < 0)
        return 0;

    if (s1[i] == s2[j])
        return 1 + f(i - 1, j - 1, s1, s2);
    return max(f(i - 1, j, s1, s2), f(i, j - 1, s1, s2));
}
int lcs(int x, int y, string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    return f(n - 1, m - 1, s1, s2);
    /* TC-O(2^n * 2^m) SC-O(n+m) */
}

/* method 2 (using memoization) */
int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (i < 0 or j < 0) // other 1 shifted index
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
        return dp[i][j] = 1 + f(i - 1, j - 1, s1, s2, dp);
    return dp[i][j] = max(f(i - 1, j, s1, s2, dp), f(i, j - 1, s1, s2, dp));
}
int lcs(int x, int y, string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n - 1, m - 1, s1, s2, dp);
    /* TC-O(n*m) SC-O(n*m + n+m) */
}

/* method 3 (tabulation - 1 shifted index) */
int lcs(int x, int y, string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
    /* TC-O(n*m) SC-O(n*m) */
}

/* method 4 (space optimization) */
int lcs(int x, int y, string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(n + 1, 0), curr(n + 1, 0);

    for (int j = 0; j <= m; j++)
        prev[j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i] == s2[j])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    return prev[m];
    /* TC-O(n*m) SC-O(n + m) */
}
