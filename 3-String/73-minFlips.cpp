#include <bits/stdc++.h>
using namespace std;

int minFlips(string S)
{
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < S.size(); i++)
    {
        // pattern : 0 1 0 1 0 1 0 1
        // index even and value 1 then need to flips
        if (i % 2 == 0 && S[i] != '0')
            cnt1++;
        // index odd and value 0 then need to flips
        if (i % 2 != 0 && S[i] != '1')
            cnt1++;

        // pattern: 1 0 1 0 1 0
        // index even and value 0 then need to filips
        if (i % 2 == 0 && S[i] != '1')
            cnt2++;
        // index odd and value 1 then need to flips
        if (i % 2 != 0 && S[i] != '0')
            cnt2++;
    }
    // return minimum of both counter
    return min(cnt1, cnt2);
    /* TC-O(N) SC-O(1) */
}

// for change character alternate that's why
char flip(char ch) { return (ch == '0') ? '1' : '0'; }

//  Utility method to get minimum flips when alternate
//  string starts with expected char
int getFlipWithStartingCharcter(string str, char expected)
{
    int flipCount = 0;
    for (int i = 0; i < str.length(); i++)
    {
        // if current character is not expected, increase flip count
        if (str[i] != expected)
            flipCount++;

        //  flip expected character each time
        expected = flip(expected);
    }
    return flipCount;
}

// method return minimum flip to make binary string
// alternate
int minFlipToMakeStringAlternate(string str)
{
    //  return minimum of following two
    //  1) flips when alternate string starts with 0
    //  2) flips when alternate string starts with 1
    return min(getFlipWithStartingCharcter(str, '0'),
               getFlipWithStartingCharcter(str, '1'));
    /* TC-O(N) SC-O(1) */
}