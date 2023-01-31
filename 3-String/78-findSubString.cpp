#include <bits/stdc++.h>
using namespace std;

/* method 1 (using two loops)*/
string findSubString(string str)
{
    int n = str.length();

    // Count all distinct characters.
    int dist_count = 0;
    unordered_map<int, int> hash_map;
    for (int i = 0; i < n; i++)
        hash_map[str[i]]++;

    dist_count = hash_map.size();

    int size = INT_MAX;

    string res;

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        int visited[256] = {0};
        string sub_str = "";
        for (int j = i; j < n; j++)
        {
            if (visited[str[j]] == 0)
            {
                count++;
                visited[str[j]] = 1;
            }
            sub_str += str[j];
            if (count == dist_count)
                break;
        }
        if (sub_str.length() < size && count == dist_count)
        {
            res = sub_str;
            size = res.length();
        }
    }
    return res;
    /* TC-O(N^2) SC-O(N) */
}

/* method 2 (using extra space or say counting freq)*/
int findSubString(string str)
{
    int ans = INT_MAX;                               // store final answer
    unordered_map<char, int> mp;                     // freq of each char
    unordered_set<char> set(str.begin(), str.end()); // count total char
    int len = set.size();

    int cnt = 1;  // it is count total char in window
    mp[str[0]]++; // intially push one element

    int i = 0, j = 1;
    while (j < str.size() && i <= j)
    {
        // if cnt is less than len means all char not present in window so increase j
        if (cnt < len)
        {
            // new character
            if (mp[str[j]] == 0)
                cnt++;
            mp[str[j]]++;
            j++;
        }
        else
        {
            // means all char present in window, now decrease windows through i++
            while (cnt == len)
            {
                ans = min(ans, j - i);

                // it means char not present in windows so we do cnt--
                if (mp[str[i]] == 1)
                    cnt--;
                mp[str[i]]--;
                i++;
            }
        }
    }

    // again check because upper loop end with j so we need to small windows that why
    while (cnt == len)
    {
        ans = min(ans, j - i);
        if (mp[str[i]] == 1)
            cnt--;
        mp[str[i]]--;
        i++;
    }
    return ans;
    /* TC- O(N) SC-O(N) */
}