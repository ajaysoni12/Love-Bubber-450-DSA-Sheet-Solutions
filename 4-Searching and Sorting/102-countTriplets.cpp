#include <bits/stdc++.h>
using namespace std;

/* method 1 (naive approach) */
long long countTriplets(long long arr[], int n, long long sum)
{
    long long cnt = 0;
    // Fix the first element as A[i]
    for (int i = 0; i < n - 2; i++)
    {
        // Fix the second element as A[j]
        for (int j = i + 1; j < n - 1; j++)
        {
            // Now look for the third number
            for (int k = j + 1; k < n; k++)
                if (arr[i] + arr[j] + arr[k] < sum)
                    cnt++;
        }
    }
    return cnt;
    /* TC-O(n^3) SC-O(1) */
}

/* method 2 (using sorting + two pointer technique) */
long long countTriplets(long long arr[], int n, long long sum)
{
    long long cnt = 0;
    sort(arr, arr + n);
    for (int i = 0; i < n - 2; i++)
    {
        // two pointer technique
        int left = i + 1, end = n - 1;
        while (left < end)
        {
            int s = arr[i] + arr[left] + arr[end];
            if (s < sum)
            {
                cnt += (end - left); // it is abovious, if jth index less than sum so till j to i all element sum lessthan
                left++;
            }
            else
                end--;
        }
    }
    return cnt;
    /* TC-O(n^2) SC-O(1) */
}