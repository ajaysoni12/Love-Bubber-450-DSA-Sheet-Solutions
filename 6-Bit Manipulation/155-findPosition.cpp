#include <bits/stdc++.h>
using namespace std;

/* method 1 (using bit manipulation technique) */
int findPosition(int num)
{
    // check power of two, if it's not then return false
    if (num & (num - 1) != 0)
        return false;
    int pos = 1;
    // if lsb bit is 1 then need to stop that's why pos value start from 1
    while (!(num & 1))
    {
        pos++;
        num >>= 1; // divide by two
    }
    return pos;
    /* TC-O(log(n)) SC-O(1) */
}

/* method 2 (brute force) */
int findPosition(int num)
{
    int cntBits = 0;
    int setBitPos = 0;
    while (num)
    {
        setBitPos++;
        if (num & 1)
            cntBits++;
        num >>= 1;
    }

    if (cntBits != 1)
        return -1;
    return setBitPos;
}

/* method 3 (using log property) */
int findPosition(int num)
{
    // it's not power of two,means set bit cnt is greater then two
    if ((num & (num - 1)) != 0)
        return false;

    return log2(num) + 1;
    /* TC-O(log2(n)) SC-O(log2(n)) */
}