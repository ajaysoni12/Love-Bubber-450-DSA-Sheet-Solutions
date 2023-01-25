#include <bits/stdc++.h>
using namespace std;

/* method 1 (using two loops) */

/* method 2 (using dutch national flag algortihm) */
void threeWayPartition(vector<int> &arr, int a, int b)
{
    int left = 0;
    int right = arr.size() - 1;
    for (int i = 0; i <= right; i++)
    {
        if (arr[i] < a)
        {
            swap(arr[left], arr[i]);
            left++;
        }
        else if (arr[i] > b)
        {
            swap(arr[right], arr[i]);
            right--;
            i--; // again comparison
        }
    }
    /*  Time Complexity: O(n)
        Auxiliary Space: O(1) */
}