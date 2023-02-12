#include <bits/stdc++.h> 
using namespace std;

/* method 1 (using x-or operator) */
int countBitsFlip(int a, int b)
{
    // first take x-or, just think on that
    int res = a ^ b;

    int cnt = 0;

    // count set bit
    while (res)
    {
        // if right bit is one 
        if (res & 1 == 1)
            cnt++;
        res >>= 1; // res / 2

        /*
            cnt++;
            res = res & (res-1);
        */
    }
    return cnt; // retur ans 
    /* TC-O(k) SC-O(1) k = no. of bits */
}

/* method 2 (using predefind functions) */
int countBitsFlip(int a, int b)
{
    int res = a ^ b;

    // count set bit 
    return __builtin_popcount(res);
    /* TC-O(K) SC-O(1) */
}

/* method 3 (using and operator) */
int countBitsFlip(int a, int b)
{
    int noOfFlips = 0;

    while (a > 0 or b > 0)
    {
        // if ones means set bit
        int n1 = a & 1;
        int n2 = b & 1;

        // if both no. are diff then increase noOfFlips 
        if (n1 != n2)
            noOfFlips++;

        // right shift by one it's means divide by 2 
        a >>= 1;
        b >>= 1;
    }
    return noOfFlips;
    /* TC-O(k) SC-O(1) k = no. of bits */
}
