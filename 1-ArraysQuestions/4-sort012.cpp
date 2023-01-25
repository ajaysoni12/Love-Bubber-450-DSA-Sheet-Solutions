#include <bits/stdc++.h>
using namespace std;

/* using sort function */
void sort012(int a[], int n)
{
    sort(a, a + n);
    /* TC-O(N*LOGN) SC-O(1) MERGE SORT OR HEAP SORT */
}

/* USING COUNTING FREQUENCY */
void sort012(int a[], int n)
{
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;

    for (int i = 0; i < n; ++i)
    {
        // count frequency of 0, 1, and 2
        if (a[i] == 0)
            cnt0++;

        else if (a[i] == 1)
            cnt1++;

        else
            cnt2++;
    }

    // fill element from 0 to cnt 0
    for (int i = 0; i < cnt0; i++)
        a[i] = 0;

    // fill element from cnt0 to cnt (cnt0 + cnt1)
    for (int i = cnt0; i < cnt0 + cnt1; i++)
        a[i] = 1;

    // fill element from (cnt0 + cnt1) to (cnt0 + cnt1 + cnt2) or n
    for (int i = cnt0 + cnt1; i < n; i++)
        a[i] = 2;

    /*
        TC - O(n) + O(n) --> O(2n)
        SC - O(1)
     */
}

/* dutch national flag alogrithm */
void sort012(int a[], int n)
{
    if (n == 0)
        return;

    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        // if element if 0
        if (a[mid] == 0)
            swap(a[low++], a[mid++]);

        // if elemet is 1
        else if (a[mid] == 1)
            mid++;

        // if element is 2
        else
            swap(a[mid], a[high--]);
    }
}
