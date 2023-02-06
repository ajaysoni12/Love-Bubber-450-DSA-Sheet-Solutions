#include <bits/stdc++.h>
using namespace std;

/* method 1 (naive appraoch)*/
int kthElement(int arr1[], int arr2[], int n, int m, int k)
{

    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr1[i]); // when push it arrange in sorted increasing order
        if (pq.size() > k)
            pq.pop();
    }
    for (int i = 0; i < m; i++)
    {
        pq.push(arr2[i]);
        if (pq.size() > k)
            pq.pop();
    }
    return pq.top();
    /* TC-O(n*Log(n)) SC-O(n+m) */
}

/* method 2 (using two pointers)*/
int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    int cnt = 0;
    int i = 0, j = 0; // pointing arr1 and arr2 symultaneously
    while (i < n and j < m)
    {
        cnt++;
        if (arr1[i] <= arr2[j])
        {
            if (cnt == k)
                return arr1[i];
            i++;
        }
        else
        {
            if (cnt == k)
                return arr2[j];
            j++;
        }
    }

    while (i < n)
    {
        cnt++;
        if (cnt == k)
            return arr1[i];
        i++;
    }
    while (j < m)
    {
        cnt++;
        if (cnt == k)
            return arr1[j];
        j++;
    }
    return -1;
    /* TC-O(cnt) SC-O(1) */
}

