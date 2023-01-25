#include <bits/stdc++.h>
using namespace std;

/* method 1 (using brute force approach) */
bool find3Numbers(int A[], int n, int X)
{
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (A[i] + A[j] + A[k] == X)
                    return true;
            }
        }
    }
    return false;
    /*  Time Complexity: O(n^3)
        Auxiliary Space: O(1) */
}

/* method 2 (using two pointer) */
bool find3Numbers(int A[], int n, int X)
{
    sort(A, A + n);

    for (int i = 0; i < n - 1; i++)
    {
        int start = i + 1, end = n - 1;
        while (start < end)
        {
            int sum = A[i] + A[start] + A[end];
            if (sum == X)
                return true;

            sum < X ? start++ : end--;
        }
    }
    return false;
    /*  Time Complexity: O(n^2)
        Auxiliary Space: O(1) */
}

/* using set or extra space */
bool find3Numbers(int A[], int arr_size, int sum)
{
    // Fix the first element as A[i]
    for (int i = 0; i < arr_size - 2; i++)
    {

        // Find pair in subarray A[i+1..n-1]
        // with sum equal to sum - A[i]
        unordered_set<int> s;
        int curr_sum = sum - A[i];
        for (int j = i + 1; j < arr_size; j++)
        {
            if (s.find(curr_sum - A[j]) != s.end())
            {
                printf("Triplet is %d, %d, %d", A[i],
                       A[j], curr_sum - A[j]);
                return true;
            }
            s.insert(A[j]);
        }
    }

    // If we reach here, then no triplet was found
    return false;
}