#include <bits/stdc++.h>
using namespace std;

/* Method 1 - (using sorting) */
void duplicateChar(string str)
{
    // find length of string
    int n = str.size();

    // sort given string
    sort(str.begin(), str.end());

    // edge case
    if (n == 0)
        cout << "Empty String ";

    else if (n == 1)
        cout << "No Duplicate ";

    else
    {
        int cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (str[i - 1] == str[i])
                cnt++;
            else
            {
                if (cnt >= 2) // duplicate element
                {
                    cout << str[i] << " " << cnt << endl;
                    cnt = 1;
                }
            }

            // for last index
            if (i == n - 1 && cnt >= 2)
            {
                cout << str[i] << " " << cnt << endl;
                cnt = 1;
            }
        }
    }

    /* TC-O(N*LogN) SC-O(1) */
}

/* Method 2 (using unordered map) */
void duplicateChar(string str)
{
    unordered_map<char, int> mp;
    for (int i = 0; i < str.size(); i++)
        mp[str[i]]++;

    for (auto it : mp)
        if (it.second > 1)
            cout << it.first << ", count = " << it.second << "\n";
    /* TC-O(N) SC-O(1) */
}