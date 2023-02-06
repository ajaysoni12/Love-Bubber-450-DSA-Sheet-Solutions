#include <bits/stdc++.h>
using namespace std;

/* method 1 (using naive appraoch) */
int findMajority(int arr[], int n)
{
    int maxCount = 0;
    int index = -1; // sentinels
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }

        // update maxCount if count of current element is greater
        if (count > maxCount)
        {
            maxCount = count;
            index = i;
        }
    }

    // if maxCount is greater than n/2 return the corresponding element
    if (maxCount > n / 2)
        return arr[index];
    return -1;
    /* TC-O(N^2) SC-O(1) */
}

/* method 2 (using sorting) */
int majorityElement(int a[], int size)
{
    // if size is one means it greater then n/2
    if (size == 1)
        return a[0];

    // sort array
    sort(a, a + size);

    int cnt = 1;
    int maxCnt = 0, index = -1;
    for (int i = 1; i < size; i++)
    {
        // if previous element is equal
        if (a[i] == a[i - 1])
        {
            cnt++;
            if (cnt > size / 2 && cnt > maxCnt) // cnt is greater then size/2
            {
                maxCnt = cnt;
                index = i;
            }
        }
        else
            cnt = 1; // curr element cnt is 1
    }
    if (index != -1)
        return a[index];
    return -1; // majority element not found
    /* TC-O(n*log(n) + o(n)) = O(n*log(n)) SC-O(1) */
}

/* method 3 (using hash_map) */
int majorityElement(int a[], int size)
{
    // store element and its freq
    unordered_map<int, int> mp;

    for (int i = 0; i < size; i++) // store element
        mp[a[i]]++;

    int maxElement = -1, maxCnt = 0;
    // traverse array
    for (auto it : mp)
    {
        // if any element occuring more than size/2 times
        if (it.second > size / 2 and it.second > maxCnt)
        {
            maxElement = it.first;
            maxCnt = it.second;
        }
    }

    if (maxElement != -1)
        return maxElement;
    // majority element not found
    return -1;
    /* TC-O(n+1 = 2n) SC-O(n) */
}

/* method 4 (moore voting algo) */
int majorityElement(int a[], int size)
{
    // if only one element is present
    if (size == 1)
        return a[0];

    int cnt = 0, candinate = 0;
    for (int i = 0; i < size; i++)
    {
        // new element comes 
        if (cnt == 0)
            candinate = a[i];

        // it is previous comes just increase cnt otherwise decrease 
        if (candinate == a[i])
            cnt++;
        else
            cnt--;
    }
    return candinate; // it means majority elemnt is always present
    /* TC-O(n) SC-O(1) */
}