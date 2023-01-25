#include <bits/stdc++.h>
using namespace std;

int find_median(vector<int> v)
{
    sort(v.begin(), v.end());

    int length = v.size();
    if (length % 2 == 0)
        return (v[length / 2] + v[length / 2 - 1]) / 2; // even
    return v[length / 2];                               // odd
    /*  Time Complexity: O(n * Log(n))
        Auxiliary Space: O(1) */
}

/* Median of two sorted arrays of same size */
/* method 1 - brute force approach
    1. create array of double size
    2. fill element of both the array
    3. sort array
    4. find median
    TC-O(N * Log(N)) SC-O(N) */

/* method 2 (using extra space) */
int find_median(vector<int> arr1, vector<int> arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();

    vector<int> mergeArr;

    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
            mergeArr.push_back(arr1[i++]);
        else
            mergeArr.push_back(arr2[j++]);
    }

    while (i < n1)
        mergeArr.push_back(arr1[i++]);

    while (j < n2)
        mergeArr.push_back(arr2[j++]);

    int length = mergeArr.size();
    if (length % 2 == 0) // even
        return (mergeArr[length / 2] + mergeArr[length / 2 - 1]) / 2;
    return mergeArr[length / 2];

    /*  Time Complexity: O(n1+n2)
        Auxiliary Space: O(n1+n2) */
}

/* method 3 (without using extra space) */
int find_median(vector<int> arr1, vector<int> arr2)
{
    int n = arr1.size();
    int i = n - 1, j = 0;

    while (i > -1 && j < n && arr1[i] > arr2[j])
        swap(arr1[i--], arr2[j++]);

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    return ((arr1[n - 1], arr2[0])) / 2;
}

/* method 4 (with extra space) */
int find_median(vector<int> arr1, vector<int> arr2)
{
    /* TC-O(N) SC-O(1) */
    int i = 0, j = 0;
    int m1 = -1, m2 = -1;
    int count;
    int n = arr1.size();

    for (count = 0; count <= arr1.size(); count++)
    {
        if (i == n)
        {
            m1 = m2;
            m2 = arr2[0];
            break;
        }

        if (j == n)
        {
            m1 = m2;
            m2 = arr1[0];
            break;
        }

        if (arr1[i] <= arr2[j])
        {
            m1 = m2;
            m2 = arr1[i];
            i++;
        }
        else
        {
            m1 = m2;
            m2 = arr2[j];
            j++;
        }

        return (m1 + m2) / 2;
    }
}
