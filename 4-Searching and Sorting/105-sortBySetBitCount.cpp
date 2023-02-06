#include <bits/stdc++.h>
using namespace std;

/* method 1 (using custom sort) */
int countBit(int n)
{
    int cnt = 0; // countBits
    while (n != 0)
    {
        // if rem 1
        if (n % 2)
            cnt++;
        n /= 2; // divide by 2 because binary representation
    }
    return cnt;
}
int cmp(int a, int b)
{
    int cnt1 = countBit(a);
    int cnt2 = countBit(b);

    if (cnt1 <= cnt2)
        return false; // sort no. of bits greater
    return true;
}
void sortBySetBitCount(int arr[], int n)
{
    stable_sort(arr, arr + n, cmp);
    /* TC-O(n*Log(n)) SC-O(1) */
}

/* method 2 (unordered_map) */
int countBit(int num)
{
    int cnt = 0;
    while (num != 0)
    {
        if (num % 2 == 1)
            cnt++;
        num /= 2;
    }
    return cnt;
}
void sortBySetBitCount(int arr[], int n)
{
    int mx = INT_MIN;                   // store maxSetBit count
    int mi = INT_MAX;                   // store minSetBit count
    unordered_map<int, vector<int>> mp; // key - (same bit no. )
    for (int i = 0; i < n; i++)
    {
        int cntBit = countBit(arr[i]);
        mp[cntBit].push_back(arr[i]);
        mx = max(mx, cntBit);
        mi = min(mi, cntBit);
    }

    int idx = 0;
    for (int i = mx; i >= mi; i--)
    {
        // element is present
        if (mp.count(i))
        {
            // store
            for (auto it : mp[i])
            {
                arr[idx] = it;
                idx++;
            }
        }
    }
    /* TC-O(n*Log(n)) SC-O(n) */
}