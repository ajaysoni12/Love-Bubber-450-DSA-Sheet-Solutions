#include <bits/stdc++.h>
using namespace std;

/* using extra space */
int maxProfit(int price[], int n)
{
    /* TC-O(N) SC-O(N) */
    int *profit = new int[n];
    for (int i = 0; i < n; i++)
        profit[i] = 0;

    int max_price = price[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (price[i] > max_price)
            max_price = price[i];

        profit[i] = max(profit[i + 1], max_price - price[i]);
    }

    int min_price = price[0];
    for (int i = 1; i < n; i++)
    {
        if (price[i] < min_price)
            min_price = price[i];

        profit[i] = max(profit[i - 1], profit[i] + (price[i] - min_price));
    }
    int result = profit[n - 1];

    delete[] profit; // To avoid memory leak

    return result;
}

/* using 4 variable */
int maxtwobuysell(int arr[], int size)
{
    int first_buy = INT_MIN;
    int first_sell = 0;
    int second_buy = INT_MIN;
    int second_sell = 0;

    for (int i = 0; i < size; i++)
    {
        first_buy = max(first_buy, -arr[i]); // we set prices to negative, so the calculation of profit will be convenient
        first_sell = max(first_sell, first_buy + arr[i]);
        second_buy = max(second_buy, first_sell - arr[i]); // we can buy the second only after first is sold
        second_sell = max(second_sell, second_buy + arr[i]);
    }
    return second_sell;
}