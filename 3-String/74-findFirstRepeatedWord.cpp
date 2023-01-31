#include <bits/stdc++.h>
using namespace std;

/* method 1 (traverse right to left and find greater then 1)*/
string firstRepChar(string s)
{
    // store freq of string
    unordered_map<string, int> mp;

    // store currWord, storeResult
    string temp = "", result = "";

    // Traverse right left
    for (int i = s.size() - 1; i >= 0; i--)
    {
        // word seprated
        if (s[i] != ' ')
            temp += s[i];
        else
        {
            // store freq
            mp[temp]++;

            // freq greater 1
            if (mp[temp] > 1)
                result = temp;

            // store next word
            temp = "";
        }
    }

    // stroe first word
    mp[temp]++;
    if (mp[temp] > 1)
        result = temp;

    // if ans not store
    if (result != "")
    {
        reverse(result.begin(), result.end());
        return result;
    }
    else
        return "-1";
}
