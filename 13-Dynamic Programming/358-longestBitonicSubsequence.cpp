#include <bits/stdc++.h>
using namespace std;

int LongestBitonicSequence(vector<int> arr)
{
    int n = arr.size();

    // left to right increasing
    vector<int> dp1(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i] and 1 + dp1[prev] > dp1[i])
                dp1[i] = 1 + dp1[prev];
        }
    }

    int mx = 0;

    // right to left increasing
    vector<int> dp2(n, 1);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int prev = n - 1; prev > i; prev--)
        {
            if (arr[prev] < arr[i] and 1 + dp2[prev] > dp2[i])
                dp2[i] = 1 + dp2[prev];
        }
        mx = max(mx, dp1[i] + dp2[i] - 1);
    }
    return mx;
    /* TC-O(n^2) SC-O(n) */
}