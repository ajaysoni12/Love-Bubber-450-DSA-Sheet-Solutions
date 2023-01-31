#include <bits/stdc++.h>
using namespace std;

/* method 1 (count 0's and 1's)*/
int maxSubStr(string str)
{
    // To store the count of 0s and 1s
    int cnt_1 = 0, cnt_2 = 0, cnt = 0;

    // To store the count of maximum substrings str can be divided into
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '0')
            cnt_1++;
        else
            cnt_2++;

        // It is not possible to split the string
        if (cnt_1 == cnt_2)
            cnt++;
    }
    return cnt;
    /* TC-O(N) SC-O(1) */
}
