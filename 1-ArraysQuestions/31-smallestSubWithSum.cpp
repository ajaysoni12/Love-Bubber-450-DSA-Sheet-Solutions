#include <bits/stdc++.h>
using namespace std;

/* method 1 (generate all subArray) */
int smallestSubWithSum(int arr[], int n, int x)
{
    int minLength = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = 0; k <= i; k++)
                sum += arr[j];
            if (sum > x)
                minLength = min(minLength, j - i + 1);
        }
    }
    return minLength;
    /*  Time Complexity: O(n^3)
        Auxiliary Space: O(1) */
}

/* method 2 (generate all subArray + running sum) */
int smallestSubWithSum(int arr[], int n, int x)
{
    int minLength = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum > x)
                minLength = min(minLength, j - i + 1);
        }
    }
    return minLength;
    /*  Time Complexity: O(n^2)
        Auxiliary Space: O(1) */
}

/* method 3 (fist add on, then removed on) */
int smallestSubWithSum(int arr[], int n, int x)
{
    int i = 0, j = 0;
    int sum = 0;
    int ans = INT_MAX;

    while (j < n)
    {
        while (sum <= x && j < n)
            sum += arr[j++];

        while (sum > x && i < j)
        {
            ans = min(ans, j - i); // j incresed by one then no need to +1
            sum = sum - arr[i];
            i++;
        }
    }

    return ans;

    /*  Time Complexity: O(n)
        Auxiliary Space: O(1) */

    // OR
    int k = 0;
    int ans = 0;
    int len = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        ans += arr[i];
        while (ans > x)
        {
            len = min(len, i - k + 1);
            ans -= arr[k++];
        }
    }

    return len;

    /*  Time Complexity: O(n)
        Auxiliary Space: O(1) */
}