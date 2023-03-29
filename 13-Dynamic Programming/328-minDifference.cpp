#include <bits/stdc++.h>
using namespace std;

// 326 problem copy

/* method 1 (tabulation method) */
/* method 2 (space optimization) */
int minDifference(int arr[], int n)
{
    int totSum = 0;
    for (int i = 0; i < n; i++)
        totSum += arr[i];
    int sum = totSum;
    vector<bool> prev(sum + 1, 0), curr(sum + 1, 0);
    prev[0] = curr[0] = true;

    if (arr[0] <= sum)
        prev[arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= sum; target++)
        {
            bool notTake = prev[target];
            bool take = false;
            if (target >= arr[ind])
                take = prev[target - arr[ind]];
            curr[target] = notTake | take;
        }
        prev = curr;
    }

    // prev[col-> 0.. totSum]
    int mini = 1e8;
    for (int s1 = 0; s1 <= totSum / 2; s1++)
        if (prev[s1] == true)
            mini = min(mini, abs((totSum - s1) - s1)); // s2-s1

    return mini;
    /* TC-O(n*sum) SC-O(sum) */
}