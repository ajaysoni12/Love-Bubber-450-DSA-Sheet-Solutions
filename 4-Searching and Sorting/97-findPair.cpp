#include <bits/stdc++.h>
using namespace std;

/* method 1 (using two loops-brute force) */
bool findPair(int arr[], int size, int n)
{
    for (int i = 0; i < n; i++)
    {
        int y = arr[i] + n;
        for (int j = 0; j < n; j++)
            if (arr[j] == y) // find pair
                return true;
    }
    return false;
    /* TC-O(n^2) SC-O(1) */
}

/* method 2 (using hashing) */
bool findPair(int arr[], int size, int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < size; i++)
        mp[arr[i]] = 1;

    for (int i = 0; i < size; i++)
    {
        int y = arr[i] + n;
        if (mp[y] == 1)
            return true;
    }
    return false;
    /* TC-O(n) SC-O(1) */
}

/* method 3 (using sorting + binary search) */
bool findPair(int arr[], int size, int n)
{
    sort(arr, arr + size); // sort array

    for (int i = 0; i < size; i++)
    {
        int x = n + arr[i];
        int j = i + 1, k = size - 1;
        while (j <= k)
        {
            int mid = (j + k) / 2;
            if (arr[mid] == x)
                return true;
            else if (arr[mid] < x)
                j = mid + 1;
            else
                k = mid - 1;
        }
    }

    return false;
    /* TC-O(n*log(n)) SC-O(1) */
}