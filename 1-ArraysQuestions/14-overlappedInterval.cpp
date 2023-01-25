#include <bits/stdc++.h>
using namespace std;

/*
    method 1 (brute force approach)
A simple approach is to start from the first interval and compare it with all other intervals for overlapping, if it overlaps with any other interval, then remove the other interval from the list and merge the other into the first interval. Repeat the same steps for the remaining intervals after the first. This approach cannot be implemented in better than O(n^2) time.
*/

/* method 2 (using stack) */
vector<vector<int>> overlappedInterval(vector<vector<int>> &intervals)
{
    // Sort Intervals
    sort(intervals.begin(), intervals.end());

    stack<pair<int, int>> s;

    int start = intervals[0][0];
    int end = intervals[0][1];

    s.push({start, end}); // for camparison

    for (int i = 1; i < intervals.size(); i++)
    {
        pair<int, int> temp = s.top();
        if (temp.second >= intervals[i][0]) // overlapped intervals
        {
            s.pop();
            s.push({min(temp.first, intervals[i][0]), max(temp.second, intervals[i][1])});
        }
        else
            s.push({intervals[i][0], intervals[i][1]});
    }

    vector<vector<int>> intervals(s.size());

    // copy data stack to vector
    for (int i = s.size() - 1; i >= 0; i--)
    {
        intervals[i].assign({s.top().first, s.top().second});
        s.pop();
    }

    return intervals;

    /*  Time Complexity: O(nLog(n))
        Auxiliary Space: O(n) */
}

/* method 3 (using same vector - without extra space) */
vector<vector<int>> overlappedInterval(vector<vector<int>> &intervals)
{
    int index = 0;

    sort(intervals.begin(), intervals.end());

    for (int i = 1; i < intervals.size(); i++)
    {
        int start = intervals[index][0];
        int end = intervals[index][1];

        if (end >= intervals[i][0])
        {
            intervals[index][0] = min(start, intervals[i][0]);
            intervals[index][1] = max(end, intervals[i][1]);
        }
        else
        {
            index++;
            intervals[index] = intervals[i];
            // intervals[index][0] = intervals[i][0];
            // intervals[index][1] = intervals[i][1];
        }
    }

    vector<vector<int>> ans;

    for (int i = 0; i <= index; i++)
        ans.push_back(intervals[i]);

    return ans;
}
