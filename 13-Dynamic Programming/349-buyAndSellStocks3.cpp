#include <bits/stdc++.h>
using namespace std;

/* method 1 (recursion) */
int f(int ind, int buy, int cap, vector<int> &price, int n)
{
    if (ind == n or cap == 0)
        return 0;

    if (buy == 1)
        return max(-price[ind] + f(ind + 1, 0, cap, price, n), 0 + f(ind + 1, 1, cap, price, n));
    return max(price[ind] + f(ind + 1, 1, cap - 1, price, n), f(ind + 1, 0, cap, price, n));
}
int maxProfit(vector<int> &price)
{
    int n = price.size();
    return f(0, 1, 2, price, n);
    /* TC-O(expo) SC-O(n) */
}

/* method 2 (memoization) */
int f(int ind, int buy, int cap, vector<int> &price, int n, vector<vector<vector<int>>> &dp)
{
    if (ind == n or cap == 0)
        return 0;

    if (dp[ind][buy][cap] != -1)
        return dp[ind][buy][cap];

    if (buy == 1)
        return dp[ind][buy][cap] = max(-price[ind] + f(ind + 1, 0, cap, price, n, dp), 0 + f(ind + 1, 1, cap, price, n, dp));
    return dp[ind][buy][cap] = max(price[ind] + f(ind + 1, 1, cap - 1, price, n, dp), f(ind + 1, 0, cap, price, n, dp));
}
int maxProfit(vector<int> &price)
{
    int n = price.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return f(0, 1, 2, price, n, dp);
    /* TC-O(n*2*3) SC-O(n*2*3 + n) */
}

/* method 3 (tabulation) */
int maxProfit(vector<int> &price)
{
    int n = price.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    // base case, no need buy default 0

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++) // no need to start from 0
            {
                if (buy == 1)
                    dp[ind][buy][cap] = max(-price[ind] + dp[ind + 1][0][cap], 0 + dp[ind + 1][1][cap]);
                else
                    dp[ind][buy][cap] = max(price[ind] + dp[ind + 1][1][cap - 1], dp[ind + 1][0][cap]);
            }
        }
    }

    return dp[0][1][2];
    /* TC-O(n*2*3) SC-O(n*2*3) */
}

/* method 4 (space optimization) */
int maxProfit(vector<int> &price)
{
    int n = price.size();
    vector<vector<int>> after(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));

    // base case, no need buy default 0

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++) // no need to start from 0
            {
                if (buy == 1)
                    curr[buy][cap] = max(-price[ind] + after[0][cap], 0 + after[1][cap]);
                else
                    curr[buy][cap] = max(price[ind] + after[1][cap - 1], after[0][cap]);
            }
        }
        after = curr;
    }

    return after[1][2];
    /* TC-O(n*2*3) SC-O(2*3) */
}

// method 5
// n*4(B S B S)