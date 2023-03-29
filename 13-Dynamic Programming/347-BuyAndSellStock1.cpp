#include <bits/stdc++.h>
using namespace std;

int maxiProfit(vector<int> &price)
{
    int mini = price[0];
    int maxProfit = 0;
    int n = price.size();

    for (int i = 1; i < n; i++)
    {
        int cost = price[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, price[i]);
    }
    return maxProfit;
    /* TC-O(n) SC-O(1) */
}