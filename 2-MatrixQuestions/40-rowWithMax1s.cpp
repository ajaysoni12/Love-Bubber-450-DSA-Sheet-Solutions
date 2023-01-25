#include <bits/stdc++.h>
using namespace std;

/* method 1 (using two loops) */
int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    int index = -1, max_1 = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < m; j++)
            if (arr[i][j] == 1)
                cnt++;

        if (cnt > max_1)
        {
            index = i;
            max_1 = cnt;
        }
    }
    return index;
    /*  Time Complexity: O(n*m)
        Auxiliary Space: O(1) */
}

/* method 1 (col wise traversing and return first 1's index)*/
int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i][j] == 1)
                return i;
        }
    }
    return -1;
    /*  Time Complexity: O(n*m)
        Auxiliary Space: O(1) */
}

int first(vector<int> arr, int low, int high)
{
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (mid == 0 || (arr[mid - 1] == 0 && arr[mid] == 1))
            return mid;
        else if (arr[mid] == 0)
            first(arr, mid + 1, high);
        else
            first(arr, low, mid - 1);
    }
    return -1;
}

int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    int max_row_index = 0, max = -1;
    int index;

    for (int i = 0; i < n; i++)
    {
        index = first(arr[i], 0, m - 1);
        if (index != -1 && m - index > max)
        {
            max = m - index;
            max_row_index = i;
        }
    }
    return max_row_index;

    /*  Time Complexity: O(m*log(n))
        Auxiliary Space: O(log(n)) */
}

int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    int i, j = m - 1;
    int max_row_index = 0;

    for (int i = 0; i < n; i++)
    {
        // Move left until a 0 is found
        bool flag = false; // to check whether a row has more 1's than previous
        while (j >= 0 && arr[i][j] == 1)
        {
            j--;         // Update the index of leftmost 1  seen so far
            flag = true; // present row has more 1's than previous
        }
        // if the present row has more 1's than previous
        if (flag)
            max_row_index = i; //  Update max_row_index
    }
    if (max_row_index == 0 && arr[0][m - 1] == 0)
        return -1;
    return max_row_index;

    /*  Time Complexity: O(n+m)
        Auxiliary Space: O(1) */
}
