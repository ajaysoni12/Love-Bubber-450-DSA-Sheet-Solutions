#include <bits/stdc++.h>
using namespace std;

/* method 1 (using one dimensional array + sorting)*/
vector<vector<int>> sortedMatrix(int N, vector<vector<int>> mat)
{
    vector<int> temp;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            temp.push_back(mat[i][j]);

    sort(temp.begin(), temp.end());

    int counter = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            mat[i][j] = temp[counter++];

    return mat;
    /*  Time Complexity: O(n^2 Log(n^2))
        Auxiliary Space: O(n^2) */
}

/* method 2 (using minHeap) */
vector<vector<int>> sortedMatrix(int N, vector<vector<int>> mat)
{
    // minHeap
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            pq.push(mat[i][j]);

    int r = 0, c = 0;
    while (!pq.empty())
    {
        mat[r][c] = pq.top();
        if (c == N)
        {
            r++;
            c = 0;
        }
        pq.pop();
    }
    return mat;
    /*  Time Complexity: O(n^2 Log(n))
        Auxiliary Space: O(n^2)
    */
}