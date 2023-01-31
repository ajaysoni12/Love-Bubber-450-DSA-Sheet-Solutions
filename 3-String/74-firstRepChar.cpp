#include <bits/stdc++.h>
using namespace std;

/* method 1 (using map or set) */
string firstRepChar(string s)
{
    // store freq of char
    unordered_map<char, int> mp;

    // store result
    string result = "";
    for (int i = 0; i < s.size(); i++)
    {
        // if char found means it is comes before
        if (mp.find(s[i]) != mp.end())
        {
            result += s[i];
            return result;
        }

        // insert char freq
        mp[s[i]]++;
    }

    // if char not found
    return "-1";
    /* TC-O(N) SC-O(N) */
}

/* method 2 (using array of all alphabets)*/
string firstRepChar(string s)
{
    // store freq of char
    int arr[26] = {0};
    string result = ""; // store ans

    for (int i = 0; i < s.size(); i++)
    {
        arr[s[i] - 97]++;        // increase freq
        if (arr[s[i] - 97] == 2) // if freq is equal == 2 means it is comes before
        {
            result += s[i];
            return result; // return string
        }
    }
    return "-1"; // otherwise char not repaeted
    /* TC-O(N) SC-O(26)*/
}