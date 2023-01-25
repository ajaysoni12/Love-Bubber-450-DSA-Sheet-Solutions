#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach - using intersection) - A simple solution is to first find intersection of two arrays and store the intersection in a temporary array, then find the intersection of third array and temporary array.
Time complexity of this solution is O(n1 + n2 + n3) where n1, n2 and n3 are sizes of ar1[], ar2[] and ar3[] respectively The above solution requires extra space and two loops */

/* method 2 (using hashing) */
vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    vector<int> ans;

    unordered_map<int, int> mp1, mp2, mp3;

    for (int i = 0; i < n1; i++)
        mp1[A[i]]++;
    for (int i = 0; i < n2; i++)
        mp2[B[i]]++;
    for (int i = 0; i < n3; i++)
        mp3[C[i]]++;

    int i = 0;
    while (i < n1)
    {
        if (mp1[A[i]] and mp2[A[i]] and mp3[A[i]])
            ans.push_back(A[i]);
        mp1[A[i]] = 0; // for removing duplicacy
        i++;
    }
    if (ans.size() == 0)
        return {-1};
    return ans;

    /*  Time Complexity: O(n1+n2+n3)
        Auxiliary Space: O(n1+n2+n3) */
}

/* method 3 (without extra space) */
vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    vector<int> ans;
    int x = 0, y = 0, z = 0;

    while (x < n1 && y < n2 && z < n3)
    {
        if (A[x] == B[y] and B[y] == C[z])
        {
            ans.push_back(A[x]);
            x++;
            y++;
            z++;
        }
        else if (A[x] < B[y])
            x++;
        else if (B[y] < C[z])
            y++;
        else
            z++;

        // for duplicate
        if (x > 0 && y > 0 && z > 0)
        {
            int xx = A[x - 1];
            int yy = B[y - 1];
            int zz = C[z - 1];
            while (A[x] == xx)
                x++;
            while (B[y] == yy)
                y++;
            while (C[z] == zz)
                z++;
        }
    }

    if (ans.size() == 0)
        return {-1};
    return ans;

    /*  Time Complexity: O(min(n1, n2 , n3))
        Auxiliary Space: O(1) */
}