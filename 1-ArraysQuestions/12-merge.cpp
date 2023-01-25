#include <bits/stdc++.h>
using namespace std;

/* method 1 (using extra array - array not sorted or sorted) */
void merge1(long long arr1[], long long arr2[], int n1, int n2)
{
    int i = 0, j = 0, k = 0;

    long long arr3[n1 + n2];

    // traverse the arr1 and insert its element in arr3
    while (i < n1)
        arr3[k++] = arr1[i++];

    // now traverse arr2 and insert in arr3
    while (j < n2)
        arr3[k++] = arr2[j++];

    // sort the whole array arr3
    sort(arr3, arr3 + n1 + n2);

    for (int i = 0; i < n1; i++)
        arr1[i] = arr3[i];
    for (int i = n1; i < k; i++)
        arr2[i - n1] = arr3[i];

    /*  Time Complexity: O((n+m)Log(n+m))
        Auxiliary Space: O(n+m) */
}

/* method 2 (using maps - array sorted or not sorted)*/
void merge2(long long arr1[], long long arr2[], int n1, int n2)
{
    // Declaring a map. using map as a inbuilt tool to store elements in sorted order.
    map<int, int> mp;

    // Inserting values to a map.
    for (int i = 0; i < n1; i++)
        mp[arr1[i]]++; // logn time to insertion

    for (int i = 0; i < n2; i++)
        mp[arr2[i]]++;

    int i = 0, j = 0;
    // Printing keys of the map.
    for (auto it : mp)
    {
        for (int k = 0; k < it.second; k++)
        {
            if (i < n1)
                arr1[i++] = it.first;
            else
                arr2[j++] = it.first;
        }
    }

    /*  Time Complexity: O(n1Log(n1) + n2Log(n2))
       Auxiliary Space: O(n1 + n2) */
}

/* method 3 (using merge sort approach - array must sortd) */
void merge3(long long arr1[], long long arr2[], int n1, int n2)
{
    int i = 0, j = 0, k = 0;

    long long arr3[n1 + n2];

    // Traverse both array
    while (i < n1 && j < n2)
    {
        /*
            Check if current element of firstarray is smaller than current element
            of second array. If yes, store first array element and increment first array
            index. Otherwise do same with second array
        */
        if (arr1[i] <= arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }

    // Store remaining elements of first array
    while (i < n1)
        arr3[k++] = arr1[i++];

    // Store remaining elements of second array
    while (j < n2)
        arr3[k++] = arr2[j++];

    for (int i = 0; i < n1; i++)
        arr1[i] = arr3[i];
    for (int i = n1; i < k; i++)
        arr2[i - n1] = arr3[i];

    /*  Time Complexity: O(n+m)
        Auxiliary Space: O(n+m) */
}

/* method 4 (without extra space - array must sroted) */
void merge4(long long arr1[], long long arr2[], int n, int m)
{
    int i = 0, j = 0, k = n - 1;
    while (i <= k && j < m)
    {
        if (arr1[i] < arr2[j])
            i++;
        else
            swap(arr2[j++], arr1[k--]);
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);

    /*  Time Complexity: O((n+m)Log(n+m))
        Auxiliary Space: O(1) */
}

/* method 5 (using insertion sort kind algorithm) - array must sorted(without extra space)*/
void merge5(long long arr1[], long long arr2[], int n, int m)
{
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] > arr2[j])
        {
            swap(arr1[i], arr2[j]);
            for (int k = 1; k < m; k++) // arr2 sorted again
            {
                if (arr2[k] < arr2[k - 1])
                    swap(arr2[k], arr2[k - 1]);
                else
                    break;
            }
        }
        i++;
    }

    /*  Time Complexity: O(n * m)
        Auxiliary Space: O(1) */
}

int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}

/* method 6 (using gap filling method) - array must sorted, without extra space */
void merge6(int arr1[], int arr2[], int n, int m)
{
    int gap = n + m;
    int i, j;
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
    {
        // comparing elements in the first array
        for (i = 0; i + gap < n; i++)
        {
            if (arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);
        }

        // comparing elements in both arrays
        for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++)
        {
            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);
        }

        if (j < m)
        {
            // comparing elements in the second array
            for (j = 0; j + gap < m; j++)
            {
                if (arr2[j] > arr2[j + gap])
                    swap(arr2[j], arr2[j + gap]);
            }
        }
    }
}

int main()
{
    int a1[] = {10, 27, 38, 43, 82};
    int a2[] = {3, 9};
    int n = sizeof(a1) / sizeof(int);
    int m = sizeof(a2) / sizeof(int);

    // Function Call
    merge6(a1, a2, n, m);

    printf("First Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a1[i]);

    printf("\nSecond Array: ");
    for (int i = 0; i < m; i++)
        printf("%d ", a2[i]);
    printf("\n");
    return 0;
}