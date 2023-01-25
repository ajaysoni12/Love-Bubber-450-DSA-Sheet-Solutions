#include <bits/stdc++.h>
using namespace std;

/* using graph you find all path, to got last end using bfs */

/* intution - let suppose you have value 3 jumps, then you can find best des, if we take 1 - 3 jumps */
int minJumps(int arr[], int n)
{
    // because alreay reached in lastIndex
    if (n <= 0)
        return 0;

    // because 0 index value is greater then lastIndex
    if (arr[0] >= n - 1)
        return 1;

    // return -1, if it is not posible to jumps
    if (arr[0] == 0)
        return -1;

    int jumps = 0;
    int pos = 0;
    int des = 0;

    // lastIndex we will not jumps
    for (int i = 0; i < n - 1; i++)
    {
        des = max(des, arr[i] + i);

        if (pos == i)
        {
            pos = des;
            jumps++;
        }
    }
    // not reached last index
    if (pos < n - 1)
        return -1;
    return jumps;

    /*  Time Complexity: O(n*log(n))
        Auxiliary Space: O(1) */
}
