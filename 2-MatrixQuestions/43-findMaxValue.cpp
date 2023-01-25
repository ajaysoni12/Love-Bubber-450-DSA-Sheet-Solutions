#include <bits/stdc++.h>
using namespace std;
#define N 5

/* method 1 (using brute force approach)*/
int findMaxValue(int mat[][N])
{
    // store minimum value
    int maxValue = INT_MIN;

    // Consider all possible pairs mat[a][b] and mat[d][e]
    for (int a = 0; a < N - 1; a++)
        for (int b = 0; b < N - 1; b++)
            for (int c = a + 1; c < N; c++)
                for (int d = b + 1; d < N; d++)
                    maxValue = max(maxValue, mat[c][d] - mat[a][b]);

    return maxValue;

    /*  Time Complexity: O(n*n*n*n) = O(n^4)
        Auxiliary Space: O(1) */
}

/* method 2 (using extra space) */
int findMaxValue(int mat[][N])
{
    // store minium value
    int maxValue = INT_MIN;

    // maxArr[i][j] stores max of elements in matrix from (i, j) to (N-1, N-1)
    int maxArr[N][N];

    // last element of maxArr will be same's as of the input matrix
    maxArr[N - 1][N - 1] = mat[N - 1][N - 1];

    // process last row
    int maxV = mat[N - 1][N - 1];
    for (int j = N - 2; j >= 0; j--)
    {
        if (mat[N - 1][j] > maxV)
            maxV = mat[N - 1][j];
        maxArr[N - 1][j] = maxV;
    }

    // process last column
    maxV = mat[N - 1][N - 1];
    for (int i = N - 2; i >= 0; i--)
    {
        if (mat[i][N - 1] > maxV)
            maxV = mat[i][N - 1];
        maxArr[i][N - 1] = maxV;
    }

    // preprocess rest of the matrix from bottom
    for (int i = N - 2; i >= 0; i--)
    {
        for (int j = N - 2; j >= 0; j--)
        {
            if (maxArr[i + 1][j + 1] - mat[i][j] > maxValue)
                maxValue = maxArr[i + 1][j + 1] - mat[i][j];
            maxArr[i][j] = max(mat[i][j], max(maxArr[i + 1][j], maxArr[i][j + 1]));
        }
    }
    return maxValue;

    /*  Time Complexity: O(n*n) = O(n^2)
        Auxiliary Space: O(n^2) */
}

/* method 3 (using two array)*/
int findMaxValue(int mat[][N])
{
    int temp1[N], temp2[N];
    temp1[N - 1] = mat[N - 1][N - 1];

    for (int i = N - 2; i >= 0; i--)
        temp1[i] = max(mat[N - 1][i], temp1[i + 1]);

    int answer = INT_MIN;

    for (int i = N - 2; i >= 0; i--)
    {
        temp2[N - 1] = max(temp1[N - 1], mat[i][N - 1]);
        for (int j = N - 2; j >= 0; j--)
        {
            if (temp1[j + 1] - mat[i][j] > answer)
                answer = temp1[j + 1] - mat[i][j];
            temp2[j] = max(mat[i][j], max(temp1[j], temp2[j + 1]));
        }

        for (int i = 0; i < N; i++)
            temp1[i] = temp2[i];
    }
    return answer;

    /*  Time Complexity: O(n+n+n*n) = O(n^2)
        Auxiliary Space: O(n+n) = O(n) */
}