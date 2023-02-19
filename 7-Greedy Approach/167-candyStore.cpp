#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach) */
vector<int> candyStore(int candies[], int n, int k)
{
    sort(candies, candies + n); // sort candies

    int minCost = 0, maxCost = 0;

    // find minCost
    for (int i = 0, j = n - 1; i <= j; i++)
    {
        minCost += candies[i];
        j = j - k;
    }

    // find maxCost
    for (int i = n - 1, j = 0; j < i; i--)
    {
        maxCost += candies[i];
        j = j + k;
    }

    return {minCost, maxCost};
}