#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach) */
int square(int n)
{
    // handle negative input
    n = n < 0 ? -n : n;

    // Initialize result
    int res = n;

    // Add n to res n-1 times
    for (int i = 1; i < n; i++)
        res += n;

    return res;
    /* TC-O(n) SC-O(1) */
}

/* method 2 (using bit manipulation technique) */
int square(int n)
{
    // handle negative input
    n = n < 0 ? -n : n;
    int x = n;
    int power = 0;
    int answer = 0;

    while (x)
    {
        if (x & 1)
            answer += n << power; // result=result+(num*(2^power))
        x >>= 1;
        power++;
    }
    return answer;
    /* TC-O(log2(n)) SC-O(1) */
}
