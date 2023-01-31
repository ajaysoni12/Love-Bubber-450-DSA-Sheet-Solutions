#include <bits/stdc++.h>
using namespace std;

int solveWordWrap(vector<int> nums, int k)
{
    // nums vector size
    int n = nums.size();

    // store extra space and after store cost
    int remainSpace[n][n];

    // fill remaining space
    for (int i = 0; i < n; i++)
    {
        remainSpace[i][i] = k - nums[i];
        for (int j = i + 1; j < n; j++)
            remainSpace[i][j] = remainSpace[i][j - 1] - nums[j] - 1; // -1 because it contain one space
    }

    // calculated cost
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // according to question not need to calculated cost for last word
            if (j == n - 1 && remainSpace[i][j] > 0)
                remainSpace[i][j] = 0;

            // not possible to store in one line
            if (remainSpace[i][j] < 0)
                remainSpace[i][j] = INT_MAX;

            // possible to store in one line
            else
                remainSpace[i][j] = remainSpace[i][j] * remainSpace[i][j];
        }
    }

    // store minCost and ans symultaneously
    int min[n], ans[n];

    for (int i = n - 1; i >= 0; i--)
    {
        min[i] = remainSpace[i][n - 1];
        ans[i] = n;
        for (int j = n - 1; j > i; j--)
        {
            if (remainSpace[i][j - 1] == INT_MAX)
                continue;
            if (min[i] > remainSpace[i][j - 1] + min[j])
            {
                min[i] = remainSpace[i][j - 1] + min[j];
                ans[i] = j;
            }
        }
    }

    return min[0];
    /* TC-O(N^2) SC-O(N^2) */
}