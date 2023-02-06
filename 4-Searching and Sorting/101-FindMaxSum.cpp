#include <bits/stdc++.h>
using namespace std;

/* method 1 (naive approach)

    Each element has two choices: either it can be the part of the subsequence with the highest sum or it cannot be part of the subsequence. So to solve the problem, build all the subsequences of the array and find the subsequence with the maximum sum such that no two adjacent elements are present in the subsequence.
    TC-O(2^n) SC-O(n)
*/

/* method 2 (using dynamic programming)*/

int solve(int arr[], int i, int dp[])
{
    // when arr index goes below 0
    if (i <= -1)
        return 0;

    // we get -1 then return dp[i]
    if (dp[i] != -1)
        return dp[i];

    // include + back 2 index
    int include = arr[i] + solve(arr, i - 2, dp);
    // exclude + back 1 index
    int exclude = solve(arr, i - 1, dp);
    return dp[i] = max(include, exclude);
}
int FindMaxSum(int arr[], int n)
{
    int dp[n];
    memset(dp, -1, sizeof(dp));
    return solve(arr, n - 1, dp);
    /* TC-O(n) SC-O(N)*/
}

/* method 3 (space optimization)*/
int FindMaxSum(vector<int> arr, int n)
{
    int incl = arr[0];
    int excl = 0;
    int excl_new;
    int i;

    for (i = 1; i < n; i++)
    {
        // Current max excluding i
        excl_new = max(incl, excl);

        // Current max including i
        incl = excl + arr[i];
        excl = excl_new;
    }

    // Return max of incl and excl
    return max(incl, excl);
    /* TC-O(n) SC-O(1) */
}
