#include <bits/stdc++.h>
using namespace std;

/* method 1 (recursion) */
int f(int i, int j, string s, string t)
{
    // one string exhausted
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    // string match
    if (s[i] == s[j])
        return 0 + f(i - 1, j - 1, s, t);
    return 1 + min(f(i - 1, j, s, t), min(f(i, j - 1, s, t), f(i - 1, j - 1, s, t)));
}
int editDistance(string s, string t)
{
    int n = s.size();
    int m = t.size();
    return f(n - 1, m - 1, s, t);
    /* TC-O(expo) SC-O(n + m) */
}

/* method 2 (memoization) */
int f(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    // one string exhausted
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    // string match
    if (s[i] == t[j])
        return dp[i][j] = 0 + f(i - 1, j - 1, s, t, dp);
    return dp[i][j] = 1 +
                      min(f(i - 1, j, s, t, dp),
                          min(f(i, j - 1, s, t, dp),
                              f(i - 1, j - 1, s, t, dp)));
}
int editDistance(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n - 1, m - 1, s, t, dp);
    /* TC-O(n*m) SC-O(n*m + n+m) */
}

/* method 3 (tabulation) */
int editDistance(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // 1 based index
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 0 + dp[i - 1][j - 1];
            else
                dp[i][j] = 1 +
                           min(dp[i - 1][j],
                               min(dp[i][j - 1],
                                   dp[i - 1][j - 1]));
        }
    }

    return dp[n][m];
    /* TC-O(n*m) SC-O(n*m + n+m) */
}

/* space optimizatin using two array */
int editDistance(string s, string t)
{
    // 1 based index
    int n = s.size();
    int m = t.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for (int j = 0; j <= m; j++)
        prev[j] = j;

    for (int i = 1; i <= n; i++)
    {
        curr[0] = i;    
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                curr[j] = 0 + prev[j - 1];
            else
                curr[j] = 1 +
                          min(prev[j],
                              min(curr[j - 1],
                                  prev[j - 1]));
        }
    }

    return prev[m];
    /* TC-O(n*m) SC-O(n + m) */
}
