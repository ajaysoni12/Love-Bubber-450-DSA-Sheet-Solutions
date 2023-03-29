#include <bits/stdc++.h>
using namespace std;

/* method 1 (using recursion) */
int mod = 1e9 + 7;
int f(int i, int j, string s, string t)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;

    if (s[i] == t[j])
        return (f(i - 1, j - 1, s, t) % mod + f(i - 1, j, s, t) % mod);
    else
        return f(i - 1, j, s, t) % mod;
}
int subsequenceCount(string s, string t)
{
    int n = s.size();
    int m = t.size();
    return f(n - 1, m - 1, s, t);
}

/* method 2 (using memoization) */
int mod = 1e9 + 7;
int f(int i, int j, string s, string t, vector<vector<int>> &dp)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == t[j])
        return dp[i][j] = (f(i - 1, j - 1, s, t, dp) % mod) + (f(i - 1, j, s, t, dp) % mod);
    else
        return dp[i][j] = f(i - 1, j, s, t, dp) % mod;
}
int subsequenceCount(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n - 1, m - 1, s, t, dp);
}

/* method 3 (tabulation) */
int mod = 1e9 + 7;
int subsequenceCount(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int j = 1; j <= m; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i-1] == t[j-1])
                dp[i][j] = (dp[i - 1][j - 1] % mod) + (dp[i - 1][j] % mod);
            else
                dp[i][j] = dp[i - 1][j] % mod;
        }
    }
    return dp[n - 1][m - 1];
}