#include <bits/stdc++.h>
using namespace std;

/* The idea is to generate all subsets of size m of arr[0..n-1]. For every subset, find the difference between the maximum and minimum elements in it. Finally, return the minimum difference. */

/* method 1 (generate all subarray of size m) and check max-min */

/* method 2 (using sorting) */
long long findMinDiff(vector<long long> a, long long n, long long m)
{
    sort(a.begin(), a.end());
    long int mini = 0, maxi = m - 1;
    long long ans = INT_MAX;
    /*
        while (maxi < n)
        {
            ans = min(ans, a[maxi] - a[mini]);
            maxi++;
            mini++;
        }
    */
    for (int i = 0; i + m - 1 < n; i++) // reduce extra loop
        ans = min(ans, a[m + i] - a[i]);

    return ans;

    /*  Time Complexity: O(n * Log(n))
       Auxiliary Space: O(1) */
}
