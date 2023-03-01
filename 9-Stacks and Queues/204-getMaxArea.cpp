#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach) */
long long getMaxArea(long long arr[], int n)
{
    long long maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        // how many previous building height graeter than currHeight
        int cnt_1 = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > arr[i])
                cnt_1++;
            else
                break; // remember only find contigeuous building
        }

        // how many next building height graeter than currHeight
        int cnt_2 = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
                cnt_2++;
            else
                break; // remember only find contigeuous building
        }

        // formula for calculating area
        maxArea = maxArea < ((abs(cnt_1 + cnt_2) + 1) * arr[i]) ? ((abs(cnt_1 + cnt_2) + 1) * arr[i]) : maxArea;
    }

    // heighest histogram
    return maxArea;
    /* TC-O(n^2) SC-O(1) */
}

/* method 2 (using stack) */
long long max(long long a, long long b) { return a > b ? a : b; }
long long getMaxArea(long long arr[], int n)
{
    // left smaller guy index and rightsmaller guy index
    vector<int> leftSmall(n), rightSmall(n);
    stack<pair<int, long long>> st;

    // left smaller index keep tracking
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() and st.top().second >= arr[i])
            st.pop();

        if (st.empty())
            leftSmall[i] = 0;
        else
            leftSmall[i] = st.top().first + 1;
        st.push({i, arr[i]});
    }

    // clear the stack
    while (!st.empty())
        st.pop();

    // right smaller guy index keep tracking
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() and st.top().second >= arr[i])
            st.pop();

        if (st.empty())
            rightSmall[i] = n - 1;
        else
            rightSmall[i] = st.top().first - 1;
        st.push({i, arr[i]});
    }

    long long maxA = 0;
    for (int i = 0; i < n; i++)
        maxA = max(maxA, arr[i] * (rightSmall[i] - leftSmall[i] + 1));
    return maxA;
    /* tc-O(3n) sc-o(3n) */
}