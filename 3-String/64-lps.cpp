#include <bits/stdc++.h>
using namespace std;

/* method 1 (using comparing)*/
int lps(string s)
{
    // proper prefix means start from 0 to till n-1
    // proper suffix means start from n-1 to till 1
    int maxLength = 0;
    string a = "", b = "";
    for (int i = 0; i < s.size() - 1; i++)
    {
        a = a + s[i];
        b = s[s.size() - i - 1] + b; // it take o(n)

        if (a == b)
            maxLength = a.size();
    }
    return maxLength;
    /* TC-O(n^2) SC-O(2s) */
}