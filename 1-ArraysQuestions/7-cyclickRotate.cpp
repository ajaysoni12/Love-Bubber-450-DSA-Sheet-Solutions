#include <bits/stdc++.h>
using namespace std;

/* method 1 (rotate by one - swapping) */
void rotate(int arr[], int n)
{
    /* right side rotate */
    for (int i = n - 1; i > 0; i--)
        swap(arr[i], arr[i - 1]);

    /* left side rotate */
    for (int i = 0; i < n - 1; i++)
        swap(arr[i], arr[i + 1]);

    /*  Time Complexity: O(n)
        Auxiliary Space: O(1) */
}

/* method 2 - (rotate by k - swapping) */
void rotate(int arr[], int n, int k)
{
    k = k % n; // don't change
    while (k--)
    {
        /* right side rotate */
        for (int i = n - 1; i > 0; i--)
            swap(arr[i], arr[i - 1]);

        /* left side rotate */
        for (int i = 0; i < n - 1; i++)
            swap(arr[i], arr[i + 1]);
    }

    /*  Time Complexity: O((k%n)*n)
        Auxiliary Space: O(1) */
}

/* method 3 (rotate by k - extra space) */
void rotate(int arr[], int n, int k)
{
    k = k % n; // don't change
    int temp[n];

    /* right side rotate */
    for (int i = 0; i < n; i++)
        temp[(k + i) % n] = arr[i];

    /* left side rotate */
    for (int i = 0; i < n; i++)
        temp[(k - i + 1) % n] = arr[i];

    for (int i = 0; i < n; i++)
        arr[i] = temp[i];

    /*  Time Complexity: O(2n)
    Auxiliary Space: O(n) */
}

/* method 4 (rotate by k - using reverse technique) */
void rotate(int arr[], int n, int k)
{
    k = k % n;
    reverse(arr, arr + n);

    /* right side rotate */
    // 0 - (k-1) index reverse + k - n index reverse
    reverse(arr, arr + k - 1);
    reverse(arr + k, arr + n);

    /* left side rotate */
    reverse(arr, arr + n - k);
    reverse(arr + n - k + 1, arr + n);

    /*  Time Complexity: O(n)
        Auxiliary Space: O(1) */
}
