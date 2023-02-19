#include <bits/stdc++.h>
using namespace std;

/* method 1 (greedy approach) */
int minimumCostOfBreaking(vector<int> x, vector<int> y, int m, int n)
{
    sort(x.begin(), x.end(), greater<int>()); // sort the horizontal cost in reverse order
    sort(y.begin(), y.end(), greater<int>()); // sort the vertical cost in reverse order

    int res = 0; // store min cost

    int horiz = 1, verti = 1; // intially width is one

    // loop until one or both cost array are proceed
    int i = 0, j = 0;
    while (i < m - 1 and j < n - 1)
    {
        if (x[i] > y[j])
        {
            res += x[i] * verti;
            horiz++; // increase horizontal part by 1
            i++;
        }
        else
        {
            res += y[j] * horiz;
            verti++; // increase vertical part by 1
            j++;
        }
    }

    while (i < m - 1)
    {
        res += x[i] * verti;
        i++;
        horiz++;
    }

    while (j < n - 1)
    {
        res += y[j] * horiz;
        j++;
        verti++;
    }

    return res;
    /* TC-O(n*log(n) + m*log(m)) SC-O(1) */
}
