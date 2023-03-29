#include <bits/stdc++.h>
using namespace std;

/* method 1 (using recursion) */
int solve(int day, int lastTask, vector<vector<int>> &points)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int task = 0; task < 3; task++)
            if (task != lastTask)
                maxi = max(maxi, points[0][task]);
        return maxi;
    }

    int maxi = 0;
    for (int task = 0; task < 3; task++)
    {
        if (task != lastTask)
        {
            int point = points[day][task] + solve(day - 1, task, points);
            maxi = max(maxi, point);
        }
    }
    return maxi;
}
int ninzaTraining(int n, vector<vector<int>> &points)
{
    return solve(n - 1, 3, points);
    /* TC-O(3 * 2^n) SC-O(3 * 2^n) */
}

/* method 2 (using memoization) */
int solve(int day, int lastTask, vector<vector<int>> &points,
          vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int task = 0; task < 3; task++)
            if (task != lastTask)
                maxi = max(maxi, points[0][task]);
        return maxi;
    }

    if (dp[day][lastTask] != -1)
        return dp[day][lastTask];

    int maxi = 0;
    for (int task = 0; task < 3; task++)
    {
        if (task != lastTask)
        {
            int point = points[day][task] + solve(day - 1, task, points);
            maxi = max(maxi, point);
        }
    }
    return dp[day][lastTask] = maxi;
}
int ninzaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));

    return solve(n - 1, 3, points, dp);
    /* TC-O(3 * (4 * n()) SC-O(n + 4*n) */
}

/* method 3 (using tabulation method) */
int ninzaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));

    // base case
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }

    return dp[n - 1][3];

    /* TC-O(3 * (4 * n()) SC-O(4*n) */
}