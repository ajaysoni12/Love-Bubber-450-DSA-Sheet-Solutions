#include <bits/stdc++.h>
using namespace std;

long long max(long long maxArea, long long currArea)
{
    return maxArea > currArea ? maxArea : currArea;
}

long long min(long long minHeight, long long currHeight)
{
    return minHeight > currHeight ? currHeight : minHeight;
}

/* method 2 (using stack, preculating leftSmall, rightSmall)*/
long long getMaxArea(long long arr[], int n)
{
    // storing leftSmall index, and rightSmall index
    vector<int> leftSmall(n), rightSmall(n);
    int leftIndex = 0, rightIndex = n - 1;

    // stack maintain curr leftsmall or rightsmall index
    stack<pair<int, int>> stack;

    // calculating leftSmall index
    for (int i = 0; i < n; i++)
    {
        while (!stack.empty() && stack.top().second >= arr[i])
            stack.pop();

        if (stack.empty())
            leftSmall[leftIndex++] = 0;
        else
            leftSmall[leftIndex++] = (stack.top().first + 1);
        stack.push({i, arr[i]});
    }

    // remove element, need new stack
    while (!stack.empty())
        stack.pop();

    // calculating rightSmall index
    for (int i = n - 1; i >= 0; i--)
    {
        while (!stack.empty() && stack.top().second >= arr[i])
            stack.pop();

        if (stack.empty())
            rightSmall[rightIndex--] = n - 1;
        else
            rightSmall[rightIndex--] = (stack.top().first - 1);
    }

    // (right smaller - leftSmalleer + 1) * arr[i]

    long long maxArea = 0;
    for (int i = 0; i < n; i++)
        maxArea = max(maxArea, (rightSmall[i] - leftSmall[i] + 1) * arr[i]);
    return maxArea;

    /*  Time Complexity: O(n + n + n + n + n) = O(5n)
        Auxiliary Space: O(3n) */
}
