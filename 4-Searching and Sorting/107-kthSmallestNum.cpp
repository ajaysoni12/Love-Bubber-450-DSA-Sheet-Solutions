#include <bits/stdc++.h>
using namespace std;

vector<int> kthSmallestNum(vector<vector<int>> &range, vector<int> queries)
{
    // sort rangle for eg: (15,20)(2,5) that's why need to sort
    sort(range.begin(), range.end());

    // merge overlapping intervals
    int idx = 0;
    for (int i = 1; i < range.size(); i++)
    {
        if (range[idx][1] >= range[i][0])
            range[idx][1] = max(range[idx][1], range[i][1]);
        else
        {
            idx++;
            range[idx] = range[i];
        }
    }

    // store queries ans
    vector<int> ans;
    for (int i = 0; i < queries.size(); i++)
    {
        int res = -1;
        for (int j = 0; j <= idx; j++)
        {
            // +1 because need to include, if it is greater then means answer present
            if ((range[j][1] - range[j][0] + 1) >= queries[i])
            {
                res = range[j][0] + queries[i] - 1;
                break;
            }
            else
                queries[i] = queries[i] - (range[j][1] - range[j][0] + 1);
        }
        ans.push_back(res);
    }
    return ans;
    /* TC-O(n*Log(n)) SC-O(n) */
}