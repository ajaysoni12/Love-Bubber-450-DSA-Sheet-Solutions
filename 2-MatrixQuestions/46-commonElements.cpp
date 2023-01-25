#include <bits/stdc++.h>
using namespace std;

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

    if (ans.size() == 0)
        return {-1};
    return ans;
}