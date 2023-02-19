#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach) */
long long int maximizeSum(long long int a[], int n, int k)
{
    int i = 0, sum = 0;
    sort(a, a + n);
    for (i = 0; i < n; i++)
    {
        if (a[i] < 0 && k > 0)
        {
            a[i] = a[i] * (-1);
            k--;
        }
    }
    sort(a, a + n);
    while (k > 0)
    {
        a[0] = a[0] * (-1);
        k--;
    }
    for (int j = 0; j < n; j++)
        sum += a[j];
    return sum;
}
