#include <bits/stdc++.h>
using namespace std;

int lcs(int x, int y, string s1, string s2)
{
    // base case
    if (x == 0 || y == 0)
        return 0;

    if (s1[x - 1] == s2[y - 1])
        return 1 + lcs(x - 1, y - 1, s1, s2);
    else
        return max(lcs(x, y - 1, s1, s2), lcs(x - 1, y, s1, s2));
    /* TC-O(2^N) SC-O(1) */
}