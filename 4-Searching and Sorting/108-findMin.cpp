#include <bits/stdc++.h>
using namespace std;

/* method 1 (using linear search) */
int findMin(int arr[], int n)
{
    int min = arr[0];
    for (int i = 1; i < n; i++)
        if (min > arr[i])
            min = arr[i];
    return min;
    /* TC-O(n) SC-O(1) */
}

int findMin(int arr[], int n)
{
    int left = 0, right = n - 1;

    // edge case
    if (arr[left] < arr[left + 1] and arr[left] < arr[right])
        return arr[left];

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] < arr[mid - 1])
            return arr[mid];
        else if (arr[mid] > arr[right])
            left = mid + 1;
        else
            right = mid - 1;
    }
    /* TC-O(nLog(n)) SC-O(1) */
}