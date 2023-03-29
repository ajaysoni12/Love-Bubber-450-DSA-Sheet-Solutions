#include <bits/stdc++.h>
using namespace std;

bool checkPossible(string &s1, string &s2)
{
    if (s1.size() != s2.size() + 1)
        return false;

    int first = 0, second = 0;

    while (first < s1.size())
    {
        if (s1[first] == s2[second])
        {
            first++;
            second++;
        }
        else
        {
            first++;
        }
    }

    if (first == s1.size() and second == s2.size())
        return true;
    return false;
}

int longestStringChain(vector<string> &arr)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();

    vector<int> dp(n, 1);
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (checkPossible(arr[i], arr[prev]) and 1 + dp[prev] > dp[i])
                dp[i] = 1 + dp[prev];
        }
        if (dp[i] > maxi)
            maxi = dp[i];
    }
    return maxi;
    /* TC-O(n^2 + n*logN) SC-O(n) */
}