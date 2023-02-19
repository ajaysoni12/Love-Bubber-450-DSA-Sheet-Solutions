#include <bits/stdc++.h>
using namespace std;

/* method 1 (greedy approach) */
int maxMeetings(int start[], int end[], int n)
{
	// edge case
	if (n == 0)
		return 0;

	vector<pair<int, int>> meetings; // store meeting start & end time
	for (int i = 0; i < n; i++)
		meetings.push_back({start[i], end[i]});

	// sort meeting according to end Time
	sort(meetings.begin(), meetings.end(), [&](pair<int, int> a, pair<int, int> b)
		 { return a.second < b.second; });

	// curr meetings endTime
	int endTime = meetings[0].second;
	int mxMeetings = 1; // intial meeting count

	for (int i = 1; i < n; i++)
	{
		// if endTime is less than next meeting start time
		if (endTime < meetings[i].first)
		{
			mxMeetings++;
			endTime = meetings[i].second; // update endTime
		}
	}
	return mxMeetings; // total attended meeting time
	/* TC-O(n*log(n) + o(n)) SC-O(n) */
}
