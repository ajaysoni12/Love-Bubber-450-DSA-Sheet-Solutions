#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

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
            leftSmall[leftIndex++] = n - 1;
        else
            leftSmall[leftIndex++] = (stack.top() - 1);
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

    /*  Time Complexity: O(n * m + n + n + n + n + n) = O(n*m)
        Auxiliary Space: O(m)
    */
}