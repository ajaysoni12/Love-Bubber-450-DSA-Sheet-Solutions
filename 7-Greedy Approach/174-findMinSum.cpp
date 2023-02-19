#include <bits/stdc++.h>
using namespace std;

/* method 1 (greedy approach) */
long long findMinSum(vector<int> &a, vector<int> &b, int n)
{
    long long sum = 0;

    // sort both of the array
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // find pair
    for (int i = 0; i < n; i++)
        sum += abs(a[i] - b[i]);

    return sum;
    /* TC-O(2n*log(n) + o(n)) SC-O(1) */
}