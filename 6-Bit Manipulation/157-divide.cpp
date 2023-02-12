#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach) */
long long divide(long long dividend, long long divisor)
{
    int sign;
    if ((dividend < 0 and divisor >= 0) or (dividend >= 0 and divisor < 0))
        sign = -1;
    else
        sign = +1;

    dividend = abs(dividend);
    divisor = abs(divisor);

    int quotient = 0;
    while (dividend >= divisor)
    {
        quotient++;
        dividend -= divisor;
    }
    return quotient * sign;
    /* TC-O(n) SC-O(1) */
}

/* method 2 (using bit manipulations)*/
long long divide(long long dividend, long long divisor)
{
    bool isNegative = false;
    if ((dividend > 0 and divisor < 0) or (dividend < 0 and divisor > 0))
        isNegative = true;

    // change to positive
    long long absDividend = abs(dividend);
    long long absDivisor = abs(divisor);

    long long ans = 0;

    while (absDividend >= absDivisor)
    {
        long long tmp = absDivisor;
        long long quotient = 1;

        // find quotient, divsor*quotient > dividend, min quotient value
        // in power of two
        while (tmp <= absDividend)
        {
            tmp <<= 1;
            quotient <<= 1;
        }

        ans += quotient >> 1;
        absDividend -= tmp >> 1;
    }

    if (isNegative == true)
        return ~ans + 1;
    else if (ans > INT_MAX)
        return INT_MAX;
    return ans;
    /* TC-O(32) SC-O(1) */
}