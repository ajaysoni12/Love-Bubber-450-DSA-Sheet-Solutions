#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(int N, vector<int> arr)
{
    // edge cases
    if (N == 1)
        return {arr[0]};

    // start from second last index
    int i = N - 2;
    while (i >= 0 && arr[i] >= arr[i + 1])
        i--;

    if (i >= 0)
    {
        // find just greater
        int j = N - 1; // 1 3(break) 5 4(just greater) 2
        while (arr[j] <= arr[i])
            j--;
        swap(arr[i], arr[j]);
    }

    // now reverse
    reverse(arr.begin() + (i + 1), arr.end());
    return arr;

    /* TC-O(N) SC-O(1) */
}