#include <bits/stdc++.h>
using namespace std;

void rec(vector<vector<char>> &mat, string target, vector<vector<bool>> &visited, int row, int col, int i, int j, int t_size, int &ans)
{
    // all possible direction - right, left, down, top
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // mark true means visited curr index char
    visited[i][j] = true;

    // check all dir if t_size index char present or not
    for (int d = 0; d < dir.size(); d++)
    {
        // curr index is i, j, so we add dir index one bye one
        int ind1 = i + dir[d].first;
        int ind2 = j + dir[d].second;

        // some edge cases and if target[t_size] == mat[ind1][ind2] means we go this side and also check visited array
        if (ind1 >= 0 && ind1 < row && ind2 >= 0 && ind2 < col && target[t_size] == mat[ind1][ind2] && visited[ind1][ind2] == false)
        {
            // it means target found
            if (t_size + 1 == target.size())
                ans++;
            else
                // we pass ind1, ind2 because we need to check for other character, t_size + 1 - means check for next character
                rec(mat, target, visited, row, col, ind1, ind2, t_size + 1, ans);
        }
    }
    // again put false for other output
    visited[i][j] = false;

    /* TC-O(2^sizeOfTraget) SC-O(dir.size()) */
}

int findOccurrence(vector<vector<char>> &mat, string target)
{
    int row = mat.size();     // no. of rows in mat
    int col = mat[0].size();  // no. of columns in mat
    int size = target.size(); // no. of char in given target string
    int ans = 0;              // store total occurrnece

    // not check for same path
    vector<vector<bool>> visited(row, vector<bool>(col, false));

    // visit every index
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // if target string first character found
            if (mat[i][j] == target[0])
            {
                // if target length is only one
                if (size == 1)
                    ans++;
                else
                    // more than one length
                    // here 1 means target second index
                    rec(mat, target, visited, row, col, i, j, 1, ans);
            }
        }
    }
    // return final ans
    return ans;

    /* TC-O(row*col * 2^sizeOfTarget) SC-O(N) */
}