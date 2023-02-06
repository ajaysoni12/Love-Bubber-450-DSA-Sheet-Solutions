#include <bits/stdc++.h>
using namespace std;

/* method 1 (using greedy approach)*/
int minSwaps(vector<int> &nums)
{
    int n = nums.size();
    // store value and index
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
        v.push_back({nums[i], i});
    // sort
    sort(v.begin(), v.end());

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        // check which index value diff
        if (i != v[i].second)
        {
            cnt++;
            swap(v[i], v[v[i].second]);
            i--;
        }
    }
    /* TC-O(N) SC-O(N) */
}