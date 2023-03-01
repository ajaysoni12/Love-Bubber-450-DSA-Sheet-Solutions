#include <bits/stdc++.h>
using namespace std;

/* method 1 (using brute force approach)*/
int celebrity(vector<vector<int>> &M, int n)
{
    int in[n] = {0};  // how many people know ith person
    int out[n] = {0}; // jth people, know how many people

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (M[i][j] == 1)
            {
                in[j]++;
                out[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        // if ith people know n-1 other people, and ith people not know anyone
        if (in[i] == n - 1 and out[i] == 0)
            return i;
    }
    return -1;
    /* TC-O(n^2) SC-O(2n) */
}

/* method 2 (using optmization) */
int celebrity(vector<vector<int>> &M, int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (M[j][i] == 1) // j knows i
            j--;
        else // j doesnt know i so i cant be celebrity
            i++;
    }

    // i points to our celebrity candidate
    int candidate = i;

    // Now, all that is left is to check that whether
    // the candidate is actually a celebrity i.e: he is
    // known by everyone but he knows no one
    for (i = 0; i < n; i++)
    {
        if (i != candidate)
        {
            if (M[i][candidate] == 0 || M[candidate][i] == 1)
                return -1;
        }
    }
    // if we reach here this means that the candidate
    // is really a celebrity
    return candidate;
    /* TC - O(n) SC-O(1) */
}