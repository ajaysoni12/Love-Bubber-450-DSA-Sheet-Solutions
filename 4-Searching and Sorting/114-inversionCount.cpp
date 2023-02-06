#include <bits/stdc++.h>
using namespace std;

/* method 1 (using two loops) followed given conditions i < j and a[i] > a[j] */

/* method 2 (using merge sort) */
long long int merge(long long arr[], long long low, long long mid, long long high)
{
    long long ans = 0, n1 = mid - low + 1, n2 = high - mid;
    long long left[n1], right[n2];

    for (long long i = 0; i < n1; i++)
        left[i] = arr[i + low];

    for (long long i = 0; i < n2; i++)
        right[i] = arr[mid + 1 + i];

    long long i = 0, j = 0, k = low;

    while (i < n1 && j < n2)
    {
        if (left[i] > right[j])
        {
            ans += n1 - i;
            arr[k++] = right[j++];
        }
        else
            arr[k++] = left[i++];
    }

    while (i < n1)
        arr[k++] = left[i++];

    while (j < n2)
        arr[k++] = right[j++];

    return ans;
}

long long int mergeSort(long long arr[], long long l, long long r)
{

    long long ans = 0;
    if (r > l)
    {
        long long mid = (l + r) / 2;
        ans += mergeSort(arr, l, mid);
        ans += mergeSort(arr, mid + 1, r);
        ans += merge(arr, l, mid, r);
    }

    return ans;
}

long long int inversionCount(long long arr[], long long N)
{
    return mergeSort(arr, 0, N - 1);
    /* TC-O(n*Log(n)) SC-O(n)*/
}