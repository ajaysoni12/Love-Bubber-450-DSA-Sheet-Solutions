#include <bits/stdc++.h>
using namespace std;

int f(int ind, vector<int> &num, int k, vector<int> &dp)
{
    int n = num.size();
    if (ind == num.size())
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    int len = 0;
    int maxi = INT_MIN;
    int mxAns = INT_MIN;

    for (int j = ind; j < min(n, ind + k); j++)
    {
        len++;
        maxi = max(maxi, num[j]);
        int sum = len * maxi + f(j + 1, num, k, dp);
        mxAns = max(mxAns, sum);
    }
    return dp[ind] = mxAns;
}
int maximumSubarray(vector<int> &num, int k)
{
    int n = num.size();
    vector<int> dp(n, -1);
    return f(0, num, k, dp);
}