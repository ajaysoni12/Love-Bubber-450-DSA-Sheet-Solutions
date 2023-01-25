#include <bits/stdc++.h>
using namespace std;

/* method 1 (using sorting) */
int countOccurence(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int ans = 0;
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
            cnt++;
        else
        {
            if (cnt > n / k)
                ans++;
            cnt = 1;
        }
    }
    return ans;

    /*  Time Complexity: O(n * Log(n))
        Auxiliary Space: O(1) */
}

/* method 2 (using hashing) */
int countOccurence(int arr[], int n, int k)
{
    unordered_map<int, int> mp;
    int cnt = 0;

    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    for (int i = 0; i < mp.size(); i++)
        if (mp[i] > n / k)
            cnt++;

    return cnt;

    /*  Time Complexity: O(n)
        Auxiliary Space: O(n) */
}