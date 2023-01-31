#include <bits/stdc++.h>
using namespace std;

/* method 1 (using freq) */
string rearrangeString(string str)
{
    int n = str.size();

    // store freq of each char
    unordered_map<char, int> mp;
    for (int i = 0; i < n; i++)
        mp[str[i]]++;

    // because we need first max freq and second max freq
    priority_queue<pair<int, char>> pq;

    // apply loop for 'a' to 'z'
    for (int i = 'a'; i <= 'z'; i++)
    {
        if (mp[i] > 0)
            pq.push({mp[i], i});

        // when arrange not possible
        if (mp[i] > n / 2)
            return "-1";
    }

    string res = ""; // store ans

    // because left of the char are distinct
    while (pq.size() >= 2)
    {
        // first max freq char
        pair<int, char> a = pq.top();
        pq.pop();

        // second max freq char
        pair<int, char> b = pq.top();
        pq.pop();

        res += a.second; // add both of them
        res += b.second;

        // if it is have multiple freq then push one less freq
        if (a.first - 1 > 0)
            pq.push({a.first - 1, a.second});

        if (b.first - 1 > 0)
            pq.push({b.first - 1, b.second});
    }

    // rest of character
    while (!pq.empty())
    {
        res += pq.top().second;
        pq.pop();
    }
    return res;

    /* TC-O(2*n*Log(n)) SC-O(3N) */
}