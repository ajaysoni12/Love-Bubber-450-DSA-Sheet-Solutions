#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

// sort in decreasing order according to value/weight
bool cmp(Item a, Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, cmp); // sort arr

    int currWeight = 0;      // store currWeight
    double finalValue = 0.0; // store total value

    // traverse through each item
    for (int i = 0; i < n; i++)
    {
        // we can take whole part
        if (currWeight + arr[i].weight <= W)
        {
            currWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        // we can take fraction part
        else
        {
            int remain = W - currWeight;
            finalValue += (arr[i].value / (double)arr[i].weight) * (double)remain;
            break; // our knapsack is full
        }
    }
    return finalValue;
    /* TC-O(n*log(n) )*/
}