#include <bits/stdc++.h>
using namespace std;

/* method 1 (naive appraoch)*/
vector<int> find(int arr[], int n, int x)
{
    // keep tracking of occurrence
    int first = -1, last = -1;
    for (int i = 0; i < n; i++)
    {
        // base condtions don't need to traverse for greter element because array sorted
        if (arr[i] > x)
            break;
        if (arr[i] == x)
        {
            // this for only one time
            if (first == -1)
                first = i;

            // keep update last occurence
            last = i;
        }
    }
    return {first, last};
    /* time complexity: o(n) auxiliary space: o(1) */
}

/* method 2 (using binary search) */
int firstOccurence(int arr[], int low, int high, int x, int n)
{
    // base conditons
    if (low <= high)
    {
        // find mid index
        int mid = (low + high) / 2;

        // mid == 0 ? means till 0-... same value and second one is just dry run
        if ((mid == 0 || arr[mid - 1] < x) && arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            return firstOccurence(arr, mid + 1, high, x, n);
        else
            return firstOccurence(arr, low, mid - 1, x, n);
    }
    return -1; // if value not present
}

int secondOccurence(int arr[], int low, int high, int x, int n)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;

        // this for second occurence
        if ((mid == n - 1 || arr[mid + 1] > x) && arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            return secondOccurence(arr, low, mid - 1, x, n);
        else
            return secondOccurence(arr, mid + 1, high, x, n);
    }
    return -1;
}

/* method 2 (using binary search) */
vector<int> find(int arr[], int n, int x)
{
    int first, last;
    first = firstOccurence(arr, 0, n - 1, x, n);
    last = secondOccurence(arr, 0, n - 1, x, n);
    return {first, last};
    /* TC-O(Log(n)) SC-O(log(n)) - stack manage recursive appraoch */
}

int first(int arr[], int n, int x)
{
    int res = -1;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] < x)
            low = mid + 1;
        else if (arr[mid] > x)
            high = mid - 1;
        else
        {
            res = mid;
            high = mid - 1;
        }
    }
    return res;
}
int last(int arr[], int n, int x)
{
    int res = -1;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] < x)
            low = mid + 1;
        else if (arr[mid] > x)
            high = mid - 1;
        else
        {
            res = mid;
            low = mid + 1;
        }
    }
    return res;
}

/* method 3 (using iterative way) */
vector<int> find(int arr[], int n, int x)
{
    int first_occ, last_occ;
    first_occ = first(arr, n, x);
    last_occ = last(arr, n, x);
    return {first_occ, last_occ};
    /* TC-O(Log(n)) SC-O(1) */
}