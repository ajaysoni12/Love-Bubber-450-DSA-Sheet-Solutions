#include <bits/stdc++.h>
using namespace std;

int findLongestPath(vector<vector<int>> &mat, int row, int col, vector<vector<bool>> &vist, int &ans, int pathRow, int pathCol, int desRow, int desCol, int curr_path_len)
{
    if (pathCol == desCol and pathRow == desRow)
    {
        ans = max(ans, curr_path_len);
        return;
    }

    if (pathRow < 0 or pathRow >= row or pathCol < 0 or pathCol >= col or vist[pathRow][pathCol] or mat[pathRow][pathCol] == 0)
        return;

    vist[pathRow][pathCol] = true;
    findLongestPath(mat, row, col, vist, ans, pathRow, pathCol + 1, desRow, desCol, curr_path_len + 1);
    findLongestPath(mat, row, col, vist, ans, pathRow, pathCol - 1, desRow, desCol, curr_path_len + 1);
    findLongestPath(mat, row, col, vist, ans, pathRow - 1, pathCol, desRow, desCol, curr_path_len + 1);
    findLongestPath(mat, row, col, vist, ans, pathRow + 1, pathCol, desRow, desCol, curr_path_len + 1);
    vist[pathRow][pathCol] = false;
    return;
}