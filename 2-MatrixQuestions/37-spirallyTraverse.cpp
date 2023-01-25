#include <bits/stdc++.h>
using namespace std;

/* method 1 (using dividing matrix into cycle)*/
vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
{
    int cnt = 1;
    int i = 0, j = 0;
    int n = r, m = c;

    vector<int> ans;

    /* col 0 means no travesing possible */
    if (m == 0)
        return ans;

    // how many time loop running
    while (cnt <= r * c)
    {
        // right
        while (j < m && matrix[i][j] != -1)
        {
            ans.push_back(matrix[i][j]);
            matrix[i][j] = -1;
            cnt++;
            j++;
        }
        j--;
        i++;

        // down
        while (i < n && matrix[i][j] != -1)
        {
            ans.push_back(matrix[i][j]);
            matrix[i][j] = -1;
            cnt++;
            i++;
        }
        i--;
        j--;

        // left
        while (j >= 0 && matrix[i][j] != -1)
        {
            ans.push_back(matrix[i][j]);
            matrix[i][j] = -1;
            cnt++;
            j--;
        }
        j++;
        i--;

        // up
        while (i >= 0 && matrix[i][j] != -1)
        {
            ans.push_back(matrix[i][j]);
            matrix[i][j] = -1;
            cnt++;
            i--;
        }
        i++;
        j++;
    }
    return ans;
    /*  Time Complexity: O(r*c)
        Auxiliary Space: O(1) */
}

/* method 2 (using direction method) */
vector<int> spirallyTraverse(vector<vector<int>> matrix, int row, int col)
{
    vector<int> ans;

    if (col == 0 || row == 0)
        return ans;

    int left = 0, right = col - 1, top = 0, bottom = row - 1;
    int dir = 0;

    while (left <= right && top <= bottom)
    {
        if (dir == 0)
        {
            // left - right
            for (int i = left; i <= right; i++)
                ans.push_back(matrix[top][i]);
            dir = 1;
            top--; // decrease top because we travese row
        }
        else if (dir == 1)
        {
            // top-bottom
            for (int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            dir = 2;
            right--; // decrease right because we travese col
        }
        else if (dir == 2)
        {
            // right-left
            for (int i = right; i >= left; i--)
                ans.push_back(matrix[i][bottom]);
            dir = 3;
            bottom--; // decrase bottom becaus we travese row(right-left)
        }
        else if (dir == 3)
        {
            // bottom-top
            for (int i = bottom; i >= top; i--)
                ans.push_back(matrix[i][left]);
            dir = 4;
            left++; // because we traverse col(bottom-top)
        }
    }
    return ans;
    /*  Time Complexity: O(r*c)
        Auxiliary Space: O(1) */
}
