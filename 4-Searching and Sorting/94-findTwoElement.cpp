#include <bits/stdc++.h>
using namespace std;

/* method 1 (using sorting) */
int *findTwoElement(int *arr, int n)
{
    // store repeated and missing
    int *t = new int[2];
    t[0] = 1;

    // sort array
    sort(arr, arr + n);

    for (int i = 1; i < n; i++)
    {
        // for repeating element
        if (arr[i] == arr[i - 1])
        {
            t[0] = arr[i];
            continue; // for this case: 1 3 3 -> sor it updated that why
        }
        // for missing
        if (arr[i] != arr[i - 1] + 1)
            t[1] = arr[i - 1] + 1;
    }

    // because we use 0 based indexing let all present exclude n
    if (arr[n - 1] != n)
        t[1] = n;

    return t;
    /* TC-O(n * log(n)) SC-O(1) */
}

/* method 2 (using freq array) */
int *findTwoElement(int *arr, int n)
{
    int freq[n + 1] = {0};
    for (int i = 0; i <= n; i++)
        freq[arr[i] + 1]++;

    int *t = new int[2];
    for (int i = 1; i <= n; i++)
    {
        if (freq[i] != i)
            t[1] = i;
        if (freq[i] > 1)
            t[0] = i;
    }
    return t;
    /* TC-O(2N) SC-O(N) */
}

/* method 3 (change plus sign to -sign)*/
int *findTwoElement(int *arr, int n)
{
    // store ans
    int *t = new int[2];

    // find repeating element
    for (int i = 0; i < n; i++)
    {
        // ith index abs value
        int temp = abs(arr[i]);

        // if it neg means already previous same value change
        if (arr[temp - 1] < 0)
            t[0] = abs(arr[i]);
        else
            arr[temp - 1] = -arr[temp - 1]; // change pos to neg
    }

    // find missing element
    for (int i = 0; i < n; i++)
    {
        // if any index value is postive means these index value not present in array
        if (arr[i] > 0)
        {
            t[1] = i + 1; // 0th based index
            break;
        }
    }
    return t;
    /* TC-O(N) SC-O(1) */
}