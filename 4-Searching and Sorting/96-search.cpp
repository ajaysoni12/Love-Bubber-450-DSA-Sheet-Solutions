#include <bits/stdc++.h>
using namespace std;

/* method 1 (naive appraoch) */
int search(int arr[], int n, int x, int k)
{
    // just traverse each index
    for (int i = 0; i < n; i++)
    {
        // if elmenet is equal to k means return index
        if (arr[i] == x)
            return i;
    }
    // otherwise it's not present
    return -1;
    /* TC-O(N) SC-O(1) */
}

/* method 2 (optimized solutions) */
int search(int arr[], int n, int x, int k)
{
    int i = 0;
    while (i < n)
    {
        if (arr[i] == x)
            return i;
        // why 1? because when difference is one then it give 0 but we need to go bye one
        i = i + max(1, abs(arr[i] - x) / 2);
    }
    /* TC-O(N) SC-O(1) */
}
