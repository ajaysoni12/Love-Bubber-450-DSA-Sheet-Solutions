#include <bits/stdc++.h>
using namespace std;

/* method 1(using two loop + sorting + space) */
int median(vector<vector<int>> &matrix, int row, int col)
{
    if (row == 0)
        return -1;

    vector<int> ans;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            ans.push_back(matrix[i][j]);

    sort(ans.begin(), ans.end());
    return ans[ans.size() / 2];

    /*  Time Complexity: O(n^2 + n*mLog(n*m )) = O(n^2)
        Auxiliary Space: O(row*col) */
}

/* count how many no. smaller then mid in given matrix */
int countSmallerThamEqualToMid(vector<int> matrix, int mid)
{
    int low = 0, high = matrix.size() - 1;
    while (low <= high)
    {
        int midd = (low + high) / 2;
        if (matrix[midd] <= mid)
            low = midd + 1;
        else
            high = midd - 1;
    }
    return low; // its total less than mid element
}

/* method 2 (using binary search) */
int median(vector<vector<int>> &matrix, int row, int col)
{
    // search space
    int low = 1;
    int high = 1e9; // you can take 2000 according to question, this is search space

    while (low <= high)
    {
        // find mid
        int mid = (low + high) / 2;
        int cnt = 0; // how many element less than mid
        for (int i = 0; i < row; i++)
            cnt += countSmallerThamEqualToMid(matrix[i], mid);

        if (cnt <= (row * col) / 2)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low; // always answer

    /*  Time Complexity : O(32 * r * log(c)).The upper bound function will      log(c) time and is performed for each row. And since the numbers will be max    of 32 bit, so binary search of numbers from min to max will be performed in    at most 32 ( log2(2^32) = 32 ) operations.
        Auxiliary Space: O(1) */
}