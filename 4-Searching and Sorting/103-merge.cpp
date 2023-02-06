#include <bits/stdc++.h>
using namespace std;

/* method 1 (using extra space) */

/* method 2 (efficient solutions)*/
void merge(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j = 0, k = n - 1;

    // Until i less than equal to k or j is less than m
    while (i <= k && j < m)
    {
        if (arr1[i] < arr2[j])
            i++;
        else
            swap(arr2[j++], arr1[k--]);
    }

    // Sort first array
    sort(arr1, arr1 + n);

    // Sort second array
    sort(arr2, arr2 + m);
    /* TC - O(n+m Log(n+m)) SC-O(1) */
}

/* method 3 (another optimzation) */
void merge(int arr1[], int arr2[], int n, int m)
{
    int i = 0;
    // while loop till last element of array 1(sorted) is
    // greater than first element of array 2(sorted)
    while (arr1[n - 1] > arr2[0])
    {
        if (arr1[i] > arr2[0])
        {
            // swap arr1[i] with first element
            // of arr2 and sorting the updated
            // arr2(arr1 is already sorted)
            swap(arr1[i], arr2[0]);
            sort(arr2, arr2 + m);
        }
        i++;
    }
    /* TC-O(n * (m*log(n))) SC-O(1) */
}