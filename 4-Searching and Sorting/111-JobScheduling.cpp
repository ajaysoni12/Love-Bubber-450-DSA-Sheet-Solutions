#include <bits/stdc++.h>
using namespace std;

struct Job 
{
    int id;
    int dead; 
    int profit;
};
static bool cmp(Job a, Job b)
{
    if (a.profit > b.profit)
        return true;
    return false;
}
/* method 1 (using greedy approach) when only deadline given not starting line*/
vector<int> JobScheduling(Job arr[], int n)
{
    vector<pair<int, int>> ans;

    // sort array according to profit
    sort(arr, arr + n, cmp);

    // it is check slots are avaible or not
    bool slots[n] = {0};

    int profit = 0, noJob = 0;
    for (int i = 0; i < n; i++)
    {
        int p = arr[i].profit;
        int d = arr[i].dead - 1;
        int j = arr[i].id;

        while (d >= 0)
        {
            if (slots[d] == false)
            {
                // mark slots book, increase jobNo and profit
                slots[d] = true;
                noJob++;
                profit += p;
                break;
            }
            d--; // if previous slots avaible because profit is max so check previous sltos
        }
    }

    ans.push_back({noJob, profit});
    /* TC-O(n*Log(n) + n*m) SC-O(n) */
}

