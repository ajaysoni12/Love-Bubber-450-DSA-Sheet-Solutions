#include <bits/stdc++.h>
using namespace std;

string chooseandswap(string str)
{
    // we need no duplicate char and need sorted order
    set<char> set;
    for (char i : str)
        set.insert(i);

    for (int i = 0; i < str.size(); i++)
    {
        // replate curr char
        set.erase(str[i]);

        // edge case, eg: abba
        if (set.empty())
            break;

        // get first smallest character
        char ch = *set.begin();

        // if curr ch is less than str[i], means need to replace
        if (ch < str[i])
        {
            int ch2 = str[i];
            for (int j = 0; j < str.length(); j++)
            {
                if (str[j] == ch)
                    str[j] = ch2;
                else if (str[j] == ch2)
                    str[j] = ch;
            }
            break; // further not proceed
        }
    }
    return str;
}
