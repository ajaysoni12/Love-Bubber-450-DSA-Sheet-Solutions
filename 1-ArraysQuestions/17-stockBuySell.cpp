#include <bits/stdc++.h>
using namespace std;

/* method 1 (using brute force appraoch) condition - single transction*/
int stockBuySellOneTime(vector<int> arr, int n)
{
    int maxProfit = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            maxProfit = max(maxProfit, arr[j] - arr[i]);
    }
    return maxProfit;

    /*  Time Complexity: O(n^2)
      Auxiliary Space: O(1) */
}

/* method 2 (keep tracking minprice and check for all other stocks) condition - single transction */
int stockBuySellOneTime(vector<int> arr, int n)
{
    int maxProfit = 0;
    int minPrice = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        minPrice = min(minPrice, arr[i]);
        maxProfit = max(maxProfit, arr[i] - minPrice);
    }
    return maxProfit;

    /*  Time Complexity: O(n)
      Auxiliary Space: O(1) */
}

/* method 3 (using greedy appraoch) condition - multiple transction */
vector<vector<int>> stockBuySell(vector<int> arr, int n)
{
    int buy = 0;
    int sell;

    vector<vector<int>> ans;
    for (int i = 1; i < n; i++)
    {
        // best buying
        while (i < n)
        {
            if (arr[buy] > arr[i])
                buy = i;
            else
                sell = i;
            i++;
        }

        if (i >= n)
            break;

        // best selling
        while (i < n)
        {
            if (arr[sell] < arr[i])
                sell = i;
            else
            {
                ans.push_back({buy, sell});
                buy = i;
            }
            i++;
        }
    }
    return ans;

    /*  Time Complexity: O(n)
      Auxiliary Space: O(n) */
}
