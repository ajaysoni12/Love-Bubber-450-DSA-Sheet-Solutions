#include <bits/stdc++.h>
using namespace std;

/* method 1 (using linear search) */
int Search(vector<int> vec, int k)
{
    // visit every index
    for (int i = 0; i < vec.size(); i++)
        if (vec[i] == k) // element found
            return i;
    return -1; // element not found
    /* TC-O(N) SC-O(1) */
}

/* method 2 (using binary search) */
int Search(vector<int> vec, int k)
{
    // find low and high index
    int low = 0, high = vec.size() - 1;

    // base case
    while (low <= high)
    {
        // find mid
        int mid = (low + high) / 2;

        if (vec[mid] == k)
            return mid;

        // if left array sorted
        else if (vec[low] <= vec[mid])
        {
            // find k present in left part
            if (vec[low] <= k && k <= vec[mid])
                high = mid - 1;
            else
                // otherwise right part
                low = mid + 1;
        }
        // if right array sorted
        else
        {
            // if k is present right part
            if (vec[mid] <= k and k <= vec[high])
                low = mid + 1;
            else
                // otherwise left part
                high = mid - 1;
        }
    }
    return -1; // element not found
    /* TC-O(n * Log(n)) SC-O(1) */
}