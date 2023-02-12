#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force appraoch) */
int countSetBits(int n)
{
    int bitCount = 0; // initialize the result
    for (int i = 1; i <= n; i++)
        bitCount += countSetBitsUtil(i);
    return bitCount;
}

// A utility function to count set bits in a number x
int countSetBitsUtil(int x)
{
    if (x <= 0)
        return 0;
    return (x % 2 == 0 ? 0 : 1) + countSetBitsUtil(x / 2);
    /* TC-O(n*log(n)) SC-O(1) */
}

/* method 2 (also brute force appraoch) */
int countSetBits(int n)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int totalBit = 0;
        int res = i;
        while (res)
        {
            if (res & 1 == 1)
                totalBit++;
            res >>= 1;
        }

        ans += totalBit;
    }
    return ans;
    /* TC-O(n*Log(k)) SC-O(1) k = no. of bits in number */
}

/* method 3 (optimized approach) */
// find till n largest power of two
int largestPowerOfTwo(int n)
{
    int x = 0; // store largest bit less than n

    // check 2^x is less than n
    while ((1 << x) <= n)
        x++;      // power increase
    return x - 1; // and need to return x-1, just think on that
}
int countSetBits(int n)
{
    // base case
    if (n == 0)
        return 0;

    // store largest power of two
    int x = largestPowerOfTwo(n);

    // count total bit  x * 2^x-1, just right 16 number binary and dry run
    int totalBitUpto2RaisePowX = (x * (1 << (x - 1)));

    // msb bit cnt row wise, left number
    int msbBitRowWise = n - (1 << x) + 1;

    // rest bit
    int restTotalNum = n - (1 << x);

    // apply same formula for resofnumber
    int totalBits = totalBitUpto2RaisePowX + msbBitRowWise + countSetBits(restTotalNum);

    return totalBits;
    /* TC-O(log(n)) SC-O(1) */
}