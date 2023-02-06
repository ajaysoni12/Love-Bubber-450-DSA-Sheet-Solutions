#include <bits/stdc++.h>
using namespace std;

/* method 1 (naive apprach) */
int countSquares(int n)
{
    int cnt = 0;
    for (int i = 1; i < n; i++)
        if (i * i < n)
            cnt++;
    return cnt;
    /* TC-O(N) SC-O(1) */
}

/* method 2 (just go only sqrt(n))*/
int countSquares(int n)
{
    int cnt = 0;
    for (int i = 1; i * i < n; i++)
        cnt++;
    return cnt;
    /* TC-O(sqrt(n)) SC-O(N) */
}

/* method 3 (direct using sqrt function) */
int countSquares(int n)
{
    int sqrt_num = sqrt(n);
    if (sqrt_num * sqrt_num != n)
        return sqrt_num;
    return sqrt_num - 1;
}