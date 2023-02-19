#include <bits/stdc++.h>
using namespace std;

/* method 1 (greedy approach) */
int buyMaximumProducts(int n, int k, int price[])
{
    // store price, and stock on the ith day
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
        v.push_back({price[i], i + 1});

    // sort according to price
    sort(v.begin(), v.end());

    // store totalStocks
    int totalStocks = 0;
    for (int i = 0; i < n; i++)
    {
        int price = v[i].first;
        int stock = v[i].second;

        //  completely buy
        if (price * stock <= k)
        {
            totalStocks += stock;
            k = k - (price * stock);
        }
        // hafly buy
        else
        {
            totalStocks += (k / price);
            k = k - (price * (k / price)); // ramaing money
        }
    }
    return totalStocks;
    /* TC-O(nLog(n) + n = O(nLog(n))) SC-O(n) */
}