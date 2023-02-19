#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

vector<int> JobScheduling(Job arr[], int n)
{
    // sort Jobs according to profit in decreasing order
    sort(arr, arr + n, [&](Job a, Job b)
         { return a.profit < b.profit; });

    // keep count profit and no. of job
    int mxProfit = 0, mxJob = 0;

    // intialy job are slots are empty
    bool slots[n] = {false};

    // traverse all jobs
    for (int i = 0; i < n; i++)
    {
        int deadLine = arr[i].dead;
        int j = deadLine - 1;
        // find best slots of job doing
        while (j >= 0)
        {
            if (slots[j] == false)
            {
                mxProfit += arr[j].profit;
                mxJob++;
                slots[j] = true; // mark true means here slots is full
                break;
            }
            j--; // decreasing slots till slots not find
        }
    }
    return {mxJob, mxProfit};
    /* TC-O(nLog(n) + n*m) SC-O(m) , m = max job */
}