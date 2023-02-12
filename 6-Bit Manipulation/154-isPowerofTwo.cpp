#include <bits/stdc++.h>
using namespace std;

/* method 1 (using division operation) */
bool isPowerofTwo(long long n)
{
    // edge case
    if (n == 0)
        return false;

    // till 1
    while (n != 1)
    {
        // if rem is not equal 0 then confirm its not power of two
        if (n % 2 != 0)
            return false;
        n /= 2;
    }
    return true; // power of two
    /* TC-O(log(n)) SC-O(1) */
}

/* method 2 (count set bit) */
bool isPowerOfTwo(int n)
{
    /* First x in the below expression is for the case when x is 0 */
    int cnt = 0;
    while (n > 0)
    {
        if ((n & 1) == 1)
            cnt++;
        n = n >> 1; // keep dividing n by 2 using right shift operator
    }

    // if cnt = 1 only then it is power of 2
    if (cnt == 1)
        return true;
    return false;
    /* TC-O(log(n)) SC-O(1) */
}

/* method 2 (using log property) */
bool isPowerofTwo(long long n)
{
    // edge case
    if (n == 0)
        return false;

    // let, n = 8 then ceil(3) == floor(3), if n=9, then ceil(3) and floor(4)
    return ceil(log2(n)) == floor(log2(n));
    /* TC-O(1) SC-O(1) */
}

/* method 4 - (using bit manipulation technique)*/
bool isPowerofTwo(long long n)
{
    // edge case
    if (n == 0)
        return false;

    // if its give non zero means not power of two
    if (n & (n - 1))
        return false;
    return true; // power of two
    /* TC-O(1) SC-O(1) */
}
