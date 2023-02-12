#include <bits/stdc++.h> 
using namespace std;

/* method 1 (without bits manipulation) */
int setBits(int n)
{
    int k = 0;
    while (n != 0)
    {
        // if rem ons means set bit
        if (n % 2 == 1)
            k++;
        n = n / 2; // divide by 2 
    }
    return k;
    /* TC-O(Log(n)) SC-O(1) */
}

/* method 2 (using bit manipulation) */
int setBits(int n)
{
    int cnt = 0;
    while (n)
    {
        // res give 0 means it unset bit(0), otherwise it's set bit
        if ((n & 1) != 0)
            cnt++;
        n >>= 1; // right shift operator(>>) and left shift(<<)
    }
    return cnt;
    /* TC-O(Log(n)) SC-O(1) */
}

/* method 3 (using recursion) */
int setBits(int num)
{
    if (num == 0)
        return 0;
    return (num & 1) + setBits(num >> 1);
    /* TC-O(log(n)) SC-O(log(n)) */
}

/* method 4 */
int countSetBits(int n)
{
    int count = 0;
    while (n)
    {
        n &= (n - 1);
        count++;
    }
    return count;
}