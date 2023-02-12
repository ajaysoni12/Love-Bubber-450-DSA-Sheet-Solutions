#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach) */
int setAllRangeBits(int num, int l, int r)
{
    // if l rang is greater then r then need to swap
    if (l > r)
        swap(l, r);

    int cnt = l;
    while (cnt <= r)
    {
        // just, think on that
        num &= 1 << (cnt - 1);
        cnt++;
    }
    return num;
    /* TC-O(r), SC-O(1) */
}

/* differencet question - copy set bit in a range */
void copySetBits(unsigned &x, unsigned y, unsigned l, unsigned r)
{
    // l and r must be between 1 to 32
    if (l < 1 || r > 32)
        return;

    // get the length of the mask
    int maskLength = 1 << (r - l + 1);
    maskLength = maskLength - 1;
    // Shift the mask to the required position "&" with y to get the set bits at between
    // l ad r in y
    int mask = ((maskLength) << (l - 1));
    mask = mask & y;

    x = x | mask;
    /* TC-O(1) SC-O(1) */
}
