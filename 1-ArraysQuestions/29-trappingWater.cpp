#include <bits/stdc++.h>
using namespace std;

// In question, width is 1 then you don't need to calculate area but for given width you need

/* method 1 (using brute force appraoch) */
long long trappingWater(int arr[], int n)
{
    int totalWater = 0;

    for (int i = 1; i < n - 1; i++)
    {
        int left = arr[i];
        for (int j = 0; j < i; j++)
            left = max(left, arr[j]);

        int right = arr[i];
        for (int j = i + 1; j < n; j++)
            right = max(right, arr[j]);

        totalWater = totalWater + (min(left, right) - arr[i]);
    }

    return totalWater;
    /*  Time Complexity: O(n^2)
       Auxiliary Space: O(1) */
}

/* method 2 (time optimization)*/
long long trappingWater(int arr[], int n)
{
    long long maxWater = 0;

    // storing max value in each index
    int leftMax[n], rightMax[n];
    int lMax = 0, rMax = 0;
    for (int i = 0, j = n - 1; i < n; i++, j--)
    {
        lMax = max(lMax, arr[i]);
        rMax = max(rMax, arr[j]);
        leftMax[i] = lMax;
        rightMax[j] = rMax;
    }

    for (int i = 1; i < n - 1; i++)
    {
        if (min(leftMax[i - 1], rightMax[i + 1]) - arr[i] > 0)
            maxWater += min(leftMax[i - 1], rightMax[i + 1]) - arr[i];
    }
    return maxWater;
    /*  Time Complexity: O(n + n)
        Auxiliary Space: O(N + n) */
}

/* method 3 (using middle highest building height) */
long long trappingWater(int arr[], int n)
{
    long long totalWater = 0;
    int leftMax = 0;
    int maxIndex = 0;
    int maximum = 0;

    for (int i = 0; i < n; i++)
    {
        if (leftMax < arr[i])
            maxIndex = i;
    }

    for (int i = 0; i <= maxIndex; i++)
    {
        leftMax = max(leftMax, arr[i]);
        int water = min(leftMax, arr[maxIndex]) - arr[i];
        totalWater += water;
    }

    leftMax = 0;

    for (int i = n - 1; i > maxIndex; i--)
    {
        leftMax = max(leftMax, arr[i]);
        int water = min(leftMax, arr[maxIndex]) - arr[i];
        totalWater += water;
    }

    return totalWater;
}