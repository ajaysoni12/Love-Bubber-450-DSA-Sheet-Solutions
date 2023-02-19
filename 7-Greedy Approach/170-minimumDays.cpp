#include <bits/stdc++.h>
using namespace std;

/* method 1 (using greedy approach) */
int minimumDays(int S, int N, int M)
{
    int x = S / 7; // sundays count
    int y = S - x; // subtract sundays

    int sm = S * M;    // totalEnergy needed
    int days = sm / N; // startingly buy energy kya pta aage sunday aa jaye

    if (sm % N != 0) // if rem != 0 then need one extra days
        days++;
    if (days <= y)
        return days; // means you can buy
    else
        return -1; // othwerise not buy or not servive
    /* TC-O(1) SC-O(1) */
}
