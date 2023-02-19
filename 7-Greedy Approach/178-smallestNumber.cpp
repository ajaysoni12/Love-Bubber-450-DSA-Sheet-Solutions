#include <bits/stdc++.h>
using namespace std;

string smallestNumber(int s, int d)
{
    // not generate number
    if (d * 9 < s)
        return "-1";

    string res = "";
    for (int i = 1; i < d; i++)
    {
        if (s > 9)
        {
            res += "9";
            s = s - 9;
        }
        else
        {
            res += to_string(s - 1);
            s = 1;
        }
    }
    res += to_string(s);
    reverse(res.begin(), res.end());
    return res;
    /* TC-O(D) SC-O(1) */
}