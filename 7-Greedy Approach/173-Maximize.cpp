#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
/* method 1 (greedy approach) */
int Maximize(int a[], int n)
{
    sort(a, a + n); // sort array
    long long prod = 0;
    for (int i = 0; i < n; i++)
        prod += (long)a[i] * i;
    prod = prod % mod;
    return (int)prod;
    /* TC-O(n*log(n) + n) SC-O(1) */
}