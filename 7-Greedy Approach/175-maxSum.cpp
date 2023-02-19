#include <bits/stdc++.h>
using namespace std;

/* method 1 (using extra space) */
long long int maxSum(int arr[], int n)
{
    int temp[n]; // create extra space
    int ind = 0;
    int i = 0, j = n - 1;
    while (i <= j)
    {
        temp[ind++] = arr[i]; // store ith element

        // if array size is odd then we not to put only one time
        if (i != j)
            temp[ind++] = arr[j];
        i++;
        j--;
    }

    // return their sum
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += abs(temp[i] - temp[(i + 1) % n]);
    return sum;
    /* TC-O(n*log(n) + n) SC-O(n) */
}

/* method 2 (using greedy approach) */
long long int maxSum(int arr[], int n)
{
    sort(arr, arr + n); // sort the array

    long long sum = 0; // store resultant

    int i = 0, j = n - 1; // two pointer approach

    while (i < j)
    {
        sum += abs(arr[i] - arr[j]);     // first element with last eleemnt
        sum += abs(arr[i + 1] - arr[j]); // second element with last element and so on

        i++;
        j--;
    }

    sum += abs(arr[0] - arr[i]); // cyclic rotation
    return sum;
    /* TC-O(n*log(n) + n) SC-O(1) */
}