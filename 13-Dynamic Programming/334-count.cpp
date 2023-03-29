#include <bits/stdc++.h>
using namespace std;

/* method 1 (recursion) */
long long f(int ind, int T, int coins[])
{
    if (ind == 0)
        return (T % coins[0] == 0);

    long long notTake = f(ind - 1, T, coins);
    long long take = 0;
    if (coins[ind] <= T)
        take = f(ind, T - coins[ind], coins);

    return take + notTake;
}
long long int count(int coins[], int N, int sum)
{
    return f(N - 1, sum, coins);
    /* TC-O(exponential) SC-O(n) */
}

/* method 2 (memoization) */
long long f(int ind, int T, int coins[], vector<vector<long long>> &dp)
{
    if (ind == 0)
        return (T % coins[0] == 0);

    if (dp[ind][T] != -1)
        return dp[ind][T];

    long long notTake = f(ind - 1, T, coins, dp);
    long long take = 0;
    if (coins[ind] <= T)
        take = f(ind, T - coins[ind], coins, dp);

    return dp[ind][T] = take + notTake;
}
long long int count(int coins[], int N, int sum)
{
    vector<vector<long long>> dp(N, vector<long long>(sum + 1, -1));
    return f(N - 1, sum, coins, dp);
    /* TC-O(n*sum) SC-O(n*sum + n) */
}

/* method 3 (tabulation) */
long long int count(int coins[], int N, int sum)
{
    vector<vector<long long>> dp(N, vector<long long>(sum + 1, 0));

    for (int T = 0; T <= sum; T++)
        dp[0][T] = (T % coins[0] == 0);

    for (int ind = 1; ind < N; ind++)
    {
        for (int T = 0; T <= sum; T++)
        {
            long long notTake = dp[ind - 1][T];
            long long take = 0;
            if (coins[ind] <= T)
                take = dp[ind][T - coins[ind]];

            dp[ind][T] = take + notTake;
        }
    }

    return dp[N - 1][sum];
    /* TC-O(n*sum) SC-O(n*sum) */
}

/* method 4 (space optimization) */
long long int count(int coins[], int N, int sum)
{
    vector<long long> prev(sum + 1, 0), curr(sum + 1, 0);
    for (int T = 0; T <= sum; T++)
        prev[T] = (T % coins[0] == 0);

    for (int ind = 1; ind < N; ind++)
    {
        for (int T = 0; T <= sum; T++)
        {
            long long notTake = prev[T];
            long long take = 0;
            if (coins[ind] <= T)
                take = prev[T - coins[ind]];

            curr[T] = take + notTake;
        }
    }

    return prev[sum];
    /* TC-O(n*sum) SC-O(sum) */
}