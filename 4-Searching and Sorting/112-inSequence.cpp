#include <bits/stdc++.h>
using namespace std;

int inSequence(int A, int B, int C)
{
    // we can't move further
    if (C == 0)
        return A == B;

    // edge case
    if (A == B)
        return 1;

    // -4 -12 -4 - second cond
    if ((B - A) % C == 0 and (B - A) / C > 0)
        return 1;
    return 0;
    /* TC-O(1) SC-O(1) */
}