#include <bits/stdc++.h>
using namespace std;

/* method 1 (recursion) */
/* method 2 (memoization) */
/* method 3 (tabulation) */

/* method 4 (space optimization) */
int lcs(int x, int y, string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for (int j = 0; j <= m; j++)
        prev[j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    return prev[m];
    /* TC-O(n*m) SC-O(n + m) */
}
int longestPalinSubseq(string str)
{
    string s1 = str;
    reverse(str.begin(), str.end());
    return lcs(str.size() - 1, str.size() - 1, s1, str);
}
int countMin(string str)
{
    return str.size() - longestPalinSubseq(str);
}