#include <bits/stdc++.h>
using namespace std;

/* kadane algorithm */
long long maxSubarraySum(int arr[], int n)
{
    int bestSum = INT_MIN;
    int currSum = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        if (currSum < arr[i]) // remeber this condition
            currSum = arr[i];
        if (bestSum < currSum)
            bestSum = currSum;
    }
    return bestSum;

    /*  Time Complexity: O(n)
       Auxiliary Space: O(1) */
}
