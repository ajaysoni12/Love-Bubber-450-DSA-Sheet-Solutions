#include <bits/stdc++.h>
using namespace std;

/* method 1 (using priority queue) */
int findPlatform(int arr[], int dep[], int n)
{
    // Store the arrival and departure time
    vector<pair<int, int>> arr2(n);
    for (int i = 0; i < n; i++)
        arr2[i] = {arr[i], dep[i]};

    // Sort arr2 based on arrival time
    sort(arr2.begin(), arr2.end());

    priority_queue<int, vector<int>, greater<int>> p;
    int count = 1;
    p.push(arr2[0].second);

    for (int i = 1; i < n; i++)
    {
        // Check if arrival time of current train
        // is less than or equals to departure time
        // of previous train
        if (p.top() >= arr2[i].first)
            count++;
        else
            p.pop();
        p.push(arr2[i].second);
    }

    // Return the number of trains required
    return count;
}

/* method 2 (using sorting) */
int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);

    int totalPlatform = 1;
    int i = 1, j = 0;
    while (i < n)
    {
        if (arr[i] <= dep[j])
            totalPlatform++;
        else
            j++;
        i++;
    }
    return totalPlatform;
}