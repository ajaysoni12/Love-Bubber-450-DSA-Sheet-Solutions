#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

/* method 1 (using extra space) */
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    vector<int> temp;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp.push_back(mat[i][j]);

    sort(temp.begin(), temp.end());

    if (k == 0)
        return -1;
    return temp[k - 1];

    /*  Time Complexity: O(n*n + nLog(n)) = O(n^2)
        Auxiliary Space: O(n^2) */
}

/* using max-heap */
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            pq.push(mat[i][j]);
            if (pq.size() > k)
                pq.pop();
        }
    return pq.top();
    /*  Time Complexity: O(n*n) = O(n^2)
        Auxiliary Space: O(k) */
}

/* method 3 (using binary search) - upper_bound */
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
    return low;
}
int kthSmallest(vector<vector<int>> matrix, int row, int k)
{
    int low = matrix[0][0];
    int high = matrix[row - 1][row - 1]; // you can take 2000 according to question, this is search space

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int cnt = 0; // how many element less than mid
        for (int i = 0; i < row; i++)
            cnt += countSmallerThamEqualToMid(matrix[i], mid);
        if (cnt < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low; // always answer

    /*  Time Complexity : O(y * n * logn)
        Where y = log(abs(Mat[0][0] - Mat[n - 1][n - 1]))
        We call the getElementsGreaterThanOrEqual function
        log(abs(Mat[0][0] – Mat[n - 1][n - 1])) times
        Time complexity of getElementsGreaterThanOrEqual is
        O(n logn) since there we do binary search n times.
        Auxiliary Space : O(1)
    */
}