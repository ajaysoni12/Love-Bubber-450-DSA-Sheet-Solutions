#include <bits/stdc++.h>
using namespace std;

/* total permutaion is n! */

/* method 1 (in-built next_permutation function)*/
vector<int> nextPermutation(int n, vector<int> arr)
{
    /* return true(if possible), return false(if not possible)*/
    next_permutation(arr.begin(), arr.end());
    return arr;
}

/* method 2 (brute force approach) - generate all permutaion(using heap alogrithm) */
void heapPermutation(int a[], int size, int n)
{
    // if size becomes 1 then prints the obtained
    // permutation
    if (size == 1)
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        printf("\n");
        return;
    }

    for (int i = 0; i < size; i++)
    {
        heapPermutation(a, size - 1, n);

        // if size is odd, swap 0th i.e (first) and
        // (size-1)th i.e (last) element
        if (size % 2 == 1)
            swap(a[0], a[size - 1]);

        // If size is even, swap ith and
        // (size-1)th i.e (last) element
        else
            swap(a[i], a[size - 1]);
    }

    /*  Time Complexity: O(n!)
      Auxiliary Space: O(n!) */
}

/* method 3 (using linear traversing) */
vector<int> nextPermutation(int N, vector<int> arr)
{
    /*
    Approach:
        i = n-2;
        1) a[i] < a[i+1]  stop, keep index1
            again from right to left
        2) a[index1] > a[i], keep index2
        3) swap(arr[index1], arr[index2])
        4) reverse(index1 +1, last);

        /* edge case - if no break point - then reverse(begin(), end()) */

    if (N == 1)
        return {arr[0]};

    int i = N - 2;
    while (i >= 0 && arr[i] >= arr[i + 1])
        i--;

    if (i >= 0)
    {
        int j = N - 1; // 1 3(break) 5 4(just greater) 2
        while (arr[j] <= arr[i])
            j--;
        swap(arr[i], arr[j]);
    }

    reverse(arr.begin() + i + 1, arr.end());
    return arr;

    /*  Time Complexity: O(n)
      Auxiliary Space: O(1) */
}