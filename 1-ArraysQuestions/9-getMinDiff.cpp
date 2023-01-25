#include <bits/stdc++.h>
using namespace std;

/* The idea is to increase the first i towers by k and decrease the rest tower by k after sorting the heights, then calculate the maximum height difference. This can be achieved using sorting */
int getMinDiff(int arr[], int n, int k)
{
    // (arr[0]+k - arr[0]-k) = 0
    if (n == 1)
        return 0;

    // Sorting the array, so that towers are sorted with heights and it is easier to work on them
    sort(arr, arr + n);

    // minDifference between maxHeight and minHeight
    int diff = arr[n - 1] - arr[0];

    for (int i = 1; i < n; i++)
    {
        // Minimum element when we add k to whole array
        int minH = min(arr[0] + k, arr[i] - k);

        // Maximum element when we subtract k from whole array
        int maxH = max(arr[n - 1] - k, arr[i - 1] + k);

        if (minH < 0)
            continue;

        diff = min(diff, maxH - minH);
    }

    /*  Time Complexity: O(n*log(n))
        Auxiliary Space: O(1) */
}