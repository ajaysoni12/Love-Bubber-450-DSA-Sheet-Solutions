#include <bits/stdc++.h>
using namespace std;

/* inversion count(conditon) - arr[i] > arr[j] && i < j */

/* method 1 (brute force approach) */
long long int inversionCount(long long arr[], long long n)
{
    long long int inv_cnt = 0;

    for (int i = 0; i < n - 1; i++) // last element not campared
    {
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j]) // don't not to check i<j condition, always less than
                inv_cnt++;
    }
    return inv_cnt;
    /*  Time Complexity: O(n^2)
      Auxiliary Space: O(1) */
}

int merge(long long arr[], int start, int mid, int end)
{
    int inv_cnt = 0;
    int temp[end - start + 1];
    int i = start;   /* i is index for left subarray */
    int j = mid + 1; /* j is index for right subarray */
    int k = 0;       /* k is index for resultant merged array */

    while (i <= mid && j <= end)
    {
        if (arr[j] > arr[i])
        {
            temp[k++] = arr[j++];
            inv_cnt += mid - i + 1; /* if i element is grater then sure all i+1 element is grater */
        }
        else
            temp[k++] = arr[i++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= end)
        temp[k++] = arr[j++];

    for (int i = start, k = 0; i <= end; i++)
        arr[i] = temp[k++];

    return inv_cnt;
}

int _mergeSort(long long arr[], int start, int end)
{
    int inv_cnt = 0, mid;
    if (start < end)
    {
        // Divide the array into two parts and
        mid = (start + end) / 2;

        /* Inversion count will be sum of inversions in left-part, right-part and number of inversions in merging. you can pass inv_cnt by ref becuase interview gloabal vairable not allowed */
        inv_cnt += _mergeSort(arr, start, mid);
        inv_cnt += _mergeSort(arr, mid + 1, end);
        inv_cnt += merge(arr, start, mid, end);
    }
    return inv_cnt;
}

/* method 2 (using merge sort)*/
long long int inversionCount(long long arr[], long long n)
{
    return _mergeSort(arr, 0, n - 1);

    /*  Time Complexity: O(n * Log(n))
        Auxiliary Space: O(n) */
}