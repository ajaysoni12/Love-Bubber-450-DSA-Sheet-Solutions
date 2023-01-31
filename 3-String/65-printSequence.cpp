#include <bits/stdc++.h>
using namespace std;

string printSequence(string S)
{
    // storing numeric sequence in array
    string str[] = {"2", "22", "222", "3", "33", "333", "4",
                    "44", "444", "5", "55", "555", "6", "66",
                    "666", "7", "77", "777", "7777", "8", "88",
                    "888", "9", "99", "999", "9999"};

    // store final output
    string output = "";

    // string size
    int n = S.size();

    // traverse whole string
    for (int i = 0; i < n; i++)
    {
        // if its space then add 0, according to question
        if (S[i] == ' ')
            output += "0";
        else
        {
            // find positions of s[i]
            int positon = S[i] - 'A';
            output += str[positon];
        }
    }

    // return final output
    return output;

    /* TC-O(N) SC-O(str.size())*/
}