#include <bits/stdc++.h>
using namespace std;

/* method 1 (using stack) */
int checkMirrorTree(int n, int e, int A[], int B[])
{
    unordered_map<int, stack<int>> mp;

    // push all edge with nodes conection
    for (int i = 0; i < 2 * e; i += 2)
        mp[A[i]].push(A[i + 1]);

    for (int i = 0; i < 2 * e; i += 2)
    {
        if (mp[B[i]].top() != B[i + 1])
            return 0;
        mp[B[i]].pop();
    }
    return 1;
    /* TC-O(e) SC-O(e) */
}