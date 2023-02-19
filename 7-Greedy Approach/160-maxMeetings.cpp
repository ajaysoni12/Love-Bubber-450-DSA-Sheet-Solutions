#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach) */
int maxMeetings(int start[], int end[], int n)
{
    // edge case
    if (n == 0)
        return 0;

    vector<pair<int, int>> meetings; // store meetings start & end time
    for (int i = 0; i < n; i++)
        meetings.push_back({start[i], end[i]});

    // sort meetings according to end time
    sort(meetings.begin(), meetings.end(), [&](pair<int, int> a, pair<int, int> b)
         { return a.second < b.second; });

    // initially mxMeeting will be one and endTime will be 0th index end time
    int mxMeetings = 1;
    int endTime = meetings[0].second;

    // start from 1 to n-1
    for (int i = 1; i < n; i++)
    {
        // if endTime less than next meetings start time, then taken
        if (endTime < meetings[i].first)
        {
            mxMeetings++;                 // increasing meeting count
            endTime = meetings[i].second; // take next meeting end time
        }
    }
    return mxMeetings; // return totalMeeting attend in one firm
    /* TC-O(n + nLog(n) + n ~= O(n)) SC-O)(n) */
}