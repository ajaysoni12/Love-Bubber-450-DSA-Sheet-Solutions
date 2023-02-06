#include <bits/stdc++.h>
using namespace std;

bool allocationPossible(int arr[], int barrier, int n, int k)
{
    int allocatedStu = 1, pages = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > barrier)
            return false;
        if (pages + arr[i] > barrier)
        {
            allocatedStu += 1;
            pages = arr[i];
        }
        else
            pages += arr[i];
    }
    if (allocatedStu > k)
        return false;
    return true;
}
int findPages(int arr[], int n, int k)
{
    if (n < k)
        return -1;

    int low = arr[0], high = 0;
    for (int i = 1; i < n; i++)
        low = low > arr[i] ? low : arr[i];
    for (int i = 0; i < n; i++)
        high = high + arr[i];

    int res = -1;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (allocationPossible(arr, mid, n, k))
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    /* TC-O(n*Log(n)) SC-O(1) */
}