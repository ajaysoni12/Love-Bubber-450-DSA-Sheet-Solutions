#include <bits/stdc++.h>
using namespace std;

/* method 1 (using extra space) */
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size(); // n == m
    int temp[n][n];

    // clock-wise arrange
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[j][n - 1 - i] = matrix[i][j];

    // copy data
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = temp[i][j];
    
    /*  Time Complexity: O(n*n) = O(n^2)
        Auxiliary Space: O(n^2) */
}

/* method 2 (using transpose + reverse) */
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // reverse
    /* clock-wise */
    for (int i = 0; i < n; i++)
        reverse(matrix[i].begin(), matrix[i].end());

    /* anticlock-wise
        for (int i = 0; i < n; i++)
        {
            int start = 0, end = n - 1;
            while (start < end)
                swap(matrix[i][start++], matrix[i][end--]);
        }
    */

    // transpose
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            swap(matrix[i][j], matrix[j][i]);
    /*  Time Complexity: O(n*n) = O(n^2)
        Auxiliary Space: O(1) */ 
}