#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach)*/
int getPairsCount(int arr[], int n, int k)
{
    int cnt = 0;

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] + arr[j] == k)
                cnt++;

    return cnt;

    /*  Time Complexity: O(n^2)
        Auxiliary Space: O(1) */
}

/* method 2 (using hashing) */
int getPairsCount(int arr[], int n, int k)
{
    int cnt = 0;

    unordered_map<int, int> mp; // map take o(logn) time to insertion

    for (int i = 0; i < n; i++)
    {
        if (mp.find(k - arr[i]) != mp.end())
            cnt += mp[k - arr[i]];
        mp[arr[i]]++;
    }

    return cnt;
    /*  Time Complexity: O(n)
        Auxiliary Space: O(n) */
}

/* method 3 (using binary search) */
int getPairsCount(int arr[], int n, int k)
{
    // then we apply binary search
    sort(arr, arr + n);

    int x = 0, c = 0, y, z;
    for (int i = 0; i < n - 1; i++)
    {
        x = k - arr[i];

        // Lower bound from i+1
        int y = lower_bound(arr + i + 1, arr + n, x) - arr;

        // Upper bound from i+1
        int z = upper_bound(arr + i + 1, arr + n, x) - arr;
        c = c + z - y;
    }
    return c;

    /*  Time Complexity: O(n * Log(n))
        Auxiliary Space: O(1) */
}