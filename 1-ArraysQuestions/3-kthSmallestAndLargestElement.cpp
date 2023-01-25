#include <bits/stdc++.h>
using namespace std;

/* Method 1 - Using Sorting */
int kthSmallest(int arr[], int l, int r, int k)
{
    if (r == 0 || k == 0 || k > r + 1)
        return -1;
    sort(arr, arr + r + 1);
    return arr[k - 1];

    /* TC - O(N*LogN) SC - O(1) */
}

int kthLargest(int arr[], int l, int r, int k)
{
    if (r == 0 || k == 0 || k > r + 1)
        return -1;
    sort(arr, arr + r + 1);
    return arr[r - k];

    /* TC - O(N-LOGN) SC - O(1) */
}

/* Method 2 - Using Extra Space */
int kthSmallest(int arr[], int l, int r, int k)
{
    if (r == 0 || k == 0 || k > r + 1)
        return -1;
    const int maxSize = 10e5;
    int temp[maxSize] = {0};
    for (int i = l; i <= r; i++)
        temp[arr[i]]++;
    int index = 0;
    while (index < maxSize)
    {
        if (temp[index] > 0)
            k--;
        if (k == 0)
            return index;
        index++;
    }
    return -1;

    /* TC - O(maxSize) SC - O(maxSize) */
}

/* USING HEAP DATA STRUCTURE */
int kthSmallest(int arr[], int l, int r, int k)
{
    priority_queue<int> a1;
    for (int i = 0; i < k; i++)
        a1.push(arr[i]);

    for (int i = k; i <= r; i++)
    {
        if (a1.top() > arr[i])
        {
            a1.pop();
            a1.push(arr[i]);
        }
    }
    return a1.top();
    /* TC - O(N)+O(K-1 * LGON)  SC - O(N)*/
}

/* using selections sort algorithm */
int partition(int arr[], int left, int right)
{
    int i = left - 1;
    int pivot = arr[right];
    for (int j = left; j <= right - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return (i + 1);
}

int kthSmallest(int arr[], int l, int r, int k)
{
    while (l <= r)
    {
        int index = partition(arr, l, r);

        if (index == k - 1)
            return arr[index];

        else if (index > k - 1)
            r = index - 1;
        else
            l = index + 1;
    }
    return -1;

    /* TC-O(N^2) - wrost case and O(N) - best case */
}