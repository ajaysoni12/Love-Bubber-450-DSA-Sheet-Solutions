#include <bits/stdc++.h>
using namespace std;

/* method 1 (greedy approach) */
int minSubset(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());
    int res = 0;
    long long int sum = 0, temp = 0;

    for (int i = 0; i < n; i++)
        sum += arr[i];

    for (int i = n - 1; i >= 0; i--)
    {
        if (temp <= (sum / 2))
        {
            temp += arr[i];
            res++;
        }
    }
    return res;
    /* TC-O(n*log(n)) SC-O(1) */
}