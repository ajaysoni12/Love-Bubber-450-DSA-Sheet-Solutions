#include <bits/stdc++.h>
using namespace std;

/* method 1 (using brute force approach - generate all sub array) */
bool subArrayExists(int arr[], int n)
{
    int count = 0; // no. of subArray
    int k = 0;     // depend on question what's k?

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = 0; k <= j; k++)
                sum += arr[j];
            if (sum == k)
                count++;
        }
    }
    if (count == 0)
        return false;
    return true;

    /*  Time Complexity: O(n^3)
        Auxiliary Space: O(1) */
}

/* method 2 (mantain prefix sum) - generate all sub array */
bool subArrayExists(int arr[], int n)
{
    int count = 0; // no. of subArray
    int k = 0;     // depend on question what's k?

    int leftSum[n];
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j <= i; j++)
            sum += arr[j];
        leftSum[i] = sum;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i == 0 && leftSum[j] == k)
                count++;
            else if (leftSum[j] - leftSum[i - 1] == k)
                count++;
        }
    }
    if (count == 0)
        return false;
    return true;

    /*  Time Complexity: O(n^2)
        Auxiliary Space: O(n) */
}

/* method 3 (maintain running sum - generate all sub array) */
bool subArrayExists(int arr[], int n)
{
    int count = 0; // no. of subArray
    int k = 0;     // depend on question what's k?

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == k)
                count++;
        }
    }
    if (count == 0)
        return false;
    return true;

    /*  Time Complexity: O(n^2)
        Auxiliary Space: O(1) */
}

/* method 4 (using hashing)*/
bool subArrayExists(int arr[], int n)
{
    int k = 0;
    int count = 0;
    unordered_set<int> set;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i]; // prefix sum

        if (sum == k || set.find(sum - k) != set.end()) // if its present that means this subarray sum is 0
            count++;
        set.insert(sum);
    }

    if (count)
        return true;
    return false;

    /*  Time Complexity: O(n)
        Auxiliary Space: O(n) */
}
