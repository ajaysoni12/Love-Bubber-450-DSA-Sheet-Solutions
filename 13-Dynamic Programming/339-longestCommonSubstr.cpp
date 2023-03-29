#include <bits/stdc++.h>
using namespace std;

/* method 1 (recursion) */
int lcs(int x, int y, string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    int maxi = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                maxi = max(maxi, dp[i][j] = 1 + dp[i - 1][j - 1]);
            else
                dp[i][j] = 0;
        }
    }
    return maxi;
    /* TC-O(n*m) SC-O(n*m) */
}
int longestCommonSubstr(string s1, string s2, int n, int m)
{
    return lcs(n, m, s1, s2);
}

/* method 2 (space optimization) */
int lcs(int x, int y, string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m+1, 0), curr(m+1, 0);

    int maxi = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                maxi = max(maxi, curr[j] = 1 + prev[j - 1]);
            else
                curr[j] = 0;
        }
        prev = curr;
    }
    return maxi;
    /* TC-O(n*m) SC-O(n+m) */
}
int longestCommonSubstr(string s1, string s2, int n, int m)
{
    return lcs(n, m, s1, s2);
}