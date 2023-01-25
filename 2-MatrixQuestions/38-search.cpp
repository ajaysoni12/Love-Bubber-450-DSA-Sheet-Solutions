#include <bits/stdc++.h>
using namespace std;

/* method 1 (using two loops) */
bool search(int mat[4][4], int n, int x)
{
    if (n == 0)
        return false;

    // traverse through the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            // if the element is found
            if (mat[i][j] == x)
            {
                cout << "\nElement found at (" << i << ", "
                     << j << ")\n";
                return true;
            }
    }

    cout << "\nElement not found";
    return false;

    /*  Time Complexity: O(n*m)
        Auxiliary Space: O(1) */
}

/* method 2 (visit every row last index compare and traverse)*/
bool search(vector<vector<int>> matrix, int n, int m, int x)
{
    int i = 0;
    while (i < n)
    {
        if (matrix[i][m - 1] >= x)
        {
            for (int j = 0; j < m; j++)
                if (matrix[i][j] == x)
                    return true;
        }
        i++;
    }
    return false;
    /*  Time Complexity: O(n+m)
        Auxiliary Space: O(1) */
}

/* method 3 (using single traversing) */
bool search(vector<vector<int>> matrix, int n, int m, int x)
{
    if (n == 0)
        return false;
    int largest = matrix[n - 1][m - 1];
    int smallest = matrix[0][0];
    if (smallest < x || largest > x)
        return false;

    int i = 0, j = n - 1;
    while (i < n && j >= 0)
    {
        if (matrix[i][j] == x)
            return true;
        if (matrix[i][j] > x)
            j--;
        else
            i++;
    }
    return false;
    /*  Time Complexity: O(n)
        Auxiliary Space: O(1) */
}
