#include <bits/stdc++.h>
using namespace std;

bool rec(vector<vector<char>> &grid, string word, int row, int col, int i, int j)
{
    // this is all possible directions, dia1, left, dia2, up, down, dia3. right, dia4
    vector<pair<int, int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    // if first word doesn't equal return false
    if (grid[i][j] != word[0])
        return false;

    // word size
    int w_size = word.size();

    // traverse all directions
    for (int d = 0; d < dir.size(); d++)
    {
        // first dir1, dir2
        int ind1 = i + dir[d].first;
        int ind2 = j + dir[d].second;
        int k;

        // continuously goes on same directions
        for (k = 1; k < w_size; k++)
        {
            // edge case
            if (ind1 >= row || ind1 < 0 || ind2 >= col || ind2 < 0)
                break;

            // word character not match
            if (grid[ind1][ind2] != word[k])
                break;

            // goes down in same directions
            ind1 = ind1 + dir[d].first;
            ind2 = ind2 + dir[d].second;
        }

        // word found
        if (k == w_size)
            return true;
    }

    // word not found
    return false;
}

vector<vector<int>> searchWord(vector<vector<char>> grid, string word)
{
    int row = grid.size();    // no. of rows in grid
    int col = grid[0].size(); // no. of columns in grid
    int w_size = word.size(); // no. of char in given word

    // store indecies of matching word
    vector<vector<int>> ans;

    // visit every index
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // return true means word found
            if (rec(grid, word, row, col, i, j))
                ans.push_back({i, j});
        }
    }
    // return final ans
    return ans;

    /* TC - O(row * col * 8 * len(str)) SC-O(1) */
}