#include <bits/stdc++.h>
using namespace std;

/* method 1 (using recursion) */
int f(int i, int j, string &pattern, string &text)
{
    if (i < 0 && j < 0)
        return true;
    if (i < 0 && j >= 0)
        return false;
    if (j < 0 && i >= 0)
    {
        for (int i1 = 0; i1 <= i; i1++)
            if (pattern[i1] != '*')
                return false;
        return true;
    }

    if (pattern[i] == text[j] || pattern[i] == '?')
        return f(i - 1, j - 1, pattern, text);
    if (pattern[i] == '*')
        return f(i - 1, j, pattern, text) | f(i, j - 1, pattern, text);
    return false; // not match
}
int wildCard(string pattern, string str)
{
    int n = pattern.size();
    int m = str.size();
    return f(n - 1, m - 1, pattern, str);
    /* TC-O(expo) SC-O(n+m) */
}

/* method 2 (memoization) */
int f(int i, int j, string &pattern, string &text, vector<vector<int>> &dp)
{
    if (i < 0 && j < 0)
        return true;
    if (i < 0 && j >= 0)
        return false;
    if (j < 0 && i >= 0)
    {
        for (int i1 = 0; i1 <= i; i1++)
            if (pattern[i1] != '*')
                return false;
        return true;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    if (pattern[i] == text[j] || pattern[i] == '?')
        return dp[i][j] = f(i - 1, j - 1, pattern, text, dp);
    if (pattern[i] == '*')
        return dp[i][j] = f(i - 1, j, pattern, text, dp) | f(i, j - 1, pattern, text, dp);
    return dp[i][j] = false; // not match
}
int wildCard(string pattern, string str)
{
    int n = pattern.size();
    int m = str.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n - 1, m - 1, pattern, str, dp);
    /* TC-O(n*m) SC-O(n*m + n+m) */
}

/* method 3 (tabulation) */
int wildCard(string pattern, string text)
{
    int n = pattern.size();
    int m = text.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // 1 based indexing
    dp[0][0] = true;
    for (int j = 1; j <= m; j++)
        dp[0][j] = false;

    for (int i = 1; i <= n; i++)
    {
        int flag = true;
        for (int i1 = 0; i1 <= i; i1++)
            if (pattern[i1] != '*')
            {
                flag = false;
                break;
            }
        dp[i][0] = flag;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (pattern[i - 1] == '*')
                dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
            else
                dp[i][j] = false; // not match
        }
    }

    return dp[n][m];
    /* TC-O(expo) SC-O(n+m) */
}
