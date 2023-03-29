#include <bits/stdc++.h>
using namespace std;

/* method 1 (recursion) */
int f(int i, int j, int isTrue, string &str)
{
    if (i > j)
        return 0;

    if (i == j)
    {
        if (isTrue)
            return str[i] == 'T';
        else
            return str[i] == 'F';
    }

    int ways = 0;
    for (int ind = i + 1; ind <= j - 1; ind += 2)
    {
        int lT = f(i, ind - 1, 1, str);
        int lF = f(i, ind - 1, 0, str);
        int rT = f(ind + 1, j, 1, str);
        int rF = f(ind + 1, j, 0, str);

        if (str[ind] == '&')
        {
            if (isTrue)
                ways += (lT * rT) % 1003;
            else
                ways += (lF * rF + lF * rT + lT * rF) % 1003;
        }
        else if (str[ind] == '|')
        {
            if (isTrue)
                ways += (lT * rT + lT * rF + lF * rT) % 1003;
            else
                ways += (lF * rF) % 1003;
        }
        else if (str[ind] == '^')
        {
            if (isTrue)
                ways += (lT * rF + lF * rT) % 1003;
            else
                ways += (lT * rT + lF * rF) % 1003;
        }
    }
    return ways % 1003;
}

int countWays(int N, string S)
{
    return f(0, S.size() - 1, 1, S);
    /* TC-O(expo) SC-O(n) */
}

/* method 2 (memoization) */
int f(int i, int j, int isTrue, string &str, vector<vector<vector<int>>> &dp)
{
    if (i > j)
        return 0;

    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    if (i == j)
    {
        if (isTrue)
            return str[i] == 'T';
        else
            return str[i] == 'F';
    }

    int ways = 0;
    for (int ind = i + 1; ind <= j - 1; ind += 2)
    {
        int lT = f(i, ind - 1, 1, str, dp);
        int lF = f(i, ind - 1, 0, str, dp);
        int rT = f(ind + 1, j, 1, str, dp);
        int rF = f(ind + 1, j, 0, str, dp);

        if (str[ind] == '&')
        {
            if (isTrue)
                ways += (lT * rT) % 1003;
            else
                ways += (lF * rF + lF * rT + lT * rF) % 1003;
        }
        else if (str[ind] == '|')
        {
            if (isTrue)
                ways += (lT * rT + lT * rF + lF * rT) % 1003;
            else
                ways += (lF * rF) % 1003;
        }
        else if (str[ind] == '^')
        {
            if (isTrue)
                ways += (lT * rF + lF * rT) % 1003;
            else
                ways += (lT * rT + lF * rF) % 1003;
        }
    }
    return dp[i][j][isTrue] = ways % 1003;
}

int countWays(int N, string S)
{
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(N + 1, vector<int>(2, -1)));
    return f(0, S.size() - 1, 1, S, dp);
    /* TC-O(n*n*2) SC-O(n*n*2 + n) */
}