#include <bits/stdc++.h>
using namespace std;

/* method 1 (using counter) */
int minimumNumberOfSwaps(string str)
{
    // count open, close bracket, minSwaps, unBalnced
    int openbrac = 0, closebrac = 0, minSwaps = 0, unbalnced = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '[')
        {
            // increment count
            openbrac++;

            // if it is unbalnced
            if (unbalnced > 0)
            {
                // store answer(swap adjacent swaps)
                minSwaps += unbalnced;
                unbalnced--; // and it make right then do decrement
            }
        }
        else
        {
            // close bracket counter
            closebrac++;

            // count total unbalnced
            unbalnced = closebrac - openbrac;
        }
    }

    return minSwaps;
    /* TC-O(N) SC-O(1) */
}
