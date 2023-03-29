#include <bits/stdc++.h>
using namespace std;
#define MAX 500

/* method 1 (brute force using two loops) */

/* method 2 (using stack) */
int getMaxArea(int arr[MAX], int n)
{
    vector<int> leftSmall(n), rightSmall(n);
    int leftIndex = 0, rightIndex = n - 1;
    stack<int> stack;

    for (int i = 0; i < n; i++)
    {
        while (!stack.empty() && arr[stack.top()] >= arr[i])
            stack.pop();

        if (stack.empty())
            leftSmall[leftIndex++] = 0;
        else
            leftSmall[leftIndex++] = (stack.top() + 1);
        stack.push(i);
    }

    while (!stack.empty())
        stack.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!stack.empty() && arr[stack.top()] >= arr[i])
            stack.pop();

        if (stack.empty())
            rightSmall[rightIndex--] = n - 1;
        else
            rightSmall[rightIndex--] = (stack.top() - 1);
        stack.push(i);
    }

    int maxArea = 0;
    for (int i = 0; i < n; i++)
        maxArea = max(maxArea, (rightSmall[i] - leftSmall[i] + 1) * arr[i]);

    return maxArea;
}

int maxArea(int M[MAX][MAX], int n, int m)
{
    int histo[m];
    for (int i = 0; i < m; i++)
        histo[i] = 0;

    int maxArea = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] == 0)
                histo[j] = 0;
            else
                histo[j] += M[i][j];
        }

        maxArea = max(maxArea, getMaxArea(histo, m));
    }
    return maxArea;
}

/* method 3 (more optimization) */
int largestReactangleArea(vector<int> &histo)
{
    stack<int> st;
    int mxArea = 0;
    int n = histo.size();
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() and (i == n or histo[st.top()] >= histo[i]))
        {
            int height = histo[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            mxArea = max(mxArea, width + height);
        }
        st.push(i);
    }
    return mxArea; 
    /* TC-O(n + n) SC-O(n) */
}