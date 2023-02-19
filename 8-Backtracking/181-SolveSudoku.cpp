#include <bits/stdc++.h>
using namespace std;
#define N 9

// check it's is a valid place or not
bool isValid(int grid[N][N], int x, int y, int val)
{
    // curr row
    for (int j = 0; j < N; j++)
        if (grid[x][j] == val)
            return false;

    // curr col
    for (int i = 0; i < N; i++)
        if (grid[i][y] == val)
            return false;

    // 3*3 diagonal

    // find left corner
    int smi = x / 3 * 3; // depend what is N value
    int smj = y / 3 * 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[smi + i][smj + j] == val)
                return false;
    return true; // valid
}

bool solve(int grid[N][N], int i, int j)
{
    // base case
    if (i == N)
        return true;

    // next place
    int ni = 0;
    int nj = 0;

    // last col, increaes col
    if (j == N - 1)
    {
        ni = i + 1;
        nj = 0;
    }
    // increase row
    else
    {
        ni = i;
        nj = j + 1;
    }

    // if it's non-zero then not check for all 1-9 options
    if (grid[i][j] != 0)
    {
        if (solve(grid, ni, nj) == true)
            return true;
    }
    else
    {
        // check for all 9 options
        for (int po = 1; po <= N; po++)
        {
            if (isValid(grid, i, j, po) == true)
            {
                grid[i][j] = po; // mark
                if (solve(grid, ni, nj) == true)
                    return true;
                grid[i][j] = 0; // unmark
            }
        }
    }
    return false;
}

// Function to find a solved Sudoku.
bool SolveSudoku(int grid[N][N])
{
    return solve(grid, 0, 0);
    /* Expected Time Complexity: O(9^N*N).
    Expected Auxiliary Space: O(N*N). */
}

// Function to print grids of the Sudoku.
void printGrid(int grid[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << grid[i][j] << " ";
        }
    }
}