#include <bits/stdc++.h>
using namespace std;

/* contiguous sub array(contain atlest one number) */

/* method 1 - (brute force approach - generate all subarray) */
long long maxSubarraySum(int arr[], int n)
{
    long long ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = 0; k <= j; k++)
                sum += arr[k];
            ans = ans < sum ? sum : ans;
        }
    }
    return ans;
    /*  Time Complexity: O(n^3)
        Auxiliary Space: O(1) */
}

/* method 2 - (modified approach of method 1 - generate all subarray) */
long long maxSubarraySum(int arr[], int n)
{
    long long maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        long long sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            maxSum = sum > maxSum ? maxSum : sum;
        }
    }
    return maxSum;
    /*  Time Complexity: O(n^2)
        Auxiliary Space: O(1) */
}

/* USING KADANE ALGORTIHM*/
long long maxSubarraySum(int arr[], int n)
{
    int bestSum = INT_MIN;
    int currSum = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];

        // you have two choice, include currSubarray or start new subarray
        currSum = currSum < arr[i] ? currSum : arr[i];
        bestSum = bestSum < currSum ? currSum : bestSum;
    }
    return bestSum;

    /*  Time Complexity: O(n)
        Auxiliary Space: O(1) */
}
