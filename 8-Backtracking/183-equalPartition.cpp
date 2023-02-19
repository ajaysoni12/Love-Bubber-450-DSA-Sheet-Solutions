#include <bits/stdc++.h>
using namespace std;

/* method 1 (using backtracking) */
int equalPartition(int N, int arr[])
{
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += arr[i];
    if (sum % 2 == 1) // if sum is odd then we cann't separete into two parts
        return 0;
    int tar = sum / 2;
    return f(arr, N, 0, tar) == true ? 1 : 0;
}

bool f(int arr[], int n, int ind, int tar)
{
    if (tar == 0)
        return true;
    if (tar < 0 || ind == n)
        return false;
    return f(arr, n, ind + 1, tar - arr[ind]) || f(arr, n, ind + 1, tar);
}