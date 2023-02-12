#include <bits/stdc++.h>
using namespace std;

/* method 1 */
vector<string> AllPossibleStrings(string s)
{
    // store all sub sequence
    vector<string> res;

    // i need to calculate n because we need to go till 1 to 2^n-1
    long long n = 1 << s.size();
    for (long long i = 1; i < n; i++)
    {
        string sub = "";
        long long num = i;
        int j = 0;
        while (num)
        {
            // bit set
            if (num & 1)
                sub += s[j]; // then add jth positions char
            j++;             // increase index
            num >>= 1;       // and also divide number by 2
        }
        res.push_back(sub); // store sub sequence
    }
    // need to sort
    sort(res.begin(), res.end());
    return res;
    /* TC-O(2^n * n) SC-O(2^n * n) */
}