#include <bits/stdc++.h>
using namespace std;

/* method 1 (using recursion) */
long long int nthFibonacci(long long int n)
{
    // base case
    if (n <= 1)
        return n;

    return nthFibonacci(n - 1) + nthFibonacci(n - 2);
    /* TC-O(2^n) SC-O(2^n) */
}

/* method 2 (using memoization) */
long long int solve(long long int n, vector<long long> &dp)
{
    if (n <= 1)
        dp[n] = n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = (solve(n - 1, dp) + solve(n - 2, dp)) % 1000000007;
}
long long int nthFibonacci(long long int n)
{
    vector<long long> dp(n + 1, -1);
    return solve(n, dp) % 1000000007;
    /* TC-O(n (single time computed)) SC-O(n (stack) + n (array))*/
}

/* method 3 (using tabulation method) */
long long int nthFibonacci(long long int n)
{
    vector<long long> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for (long long int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
    /* TC-O(n-single time computed) SC-O(n-array) */
}

/* method 4 (using without space) */
long long int nthFibonacci(long long int n)
{
    long long prev2 = 0; // second previous
    long long prev1 = 1; // first previous
    for (long long i = 2; i <= n; i++)
    {
        // ith fibo number
        long long curr_i = prev1 + prev2;
        prev2 = prev1;  // update with next one
        prev1 = curr_i; // update with curr fibo
    }
    return prev1;
    /* TC-O(n) SC-O(1) */
}