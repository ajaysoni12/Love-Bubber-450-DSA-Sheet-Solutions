#include <bits/stdc++.h>
using namespace std;

void solve(string str, vector<string> &ans, int curr_ind)
{
    if (curr_ind == str.size())
    {
        ans.push_back(str);
        return;
    }

    for (int i = curr_ind; i < str.size(); i++)
    {
        if (str[i] == str[i + 1])
            continue;
        swap(str[curr_ind], str[i]);
        solve(str, ans, curr_ind + 1);
        swap(str[curr_ind], str[i]);
    }
}

vector<string> find_permutation(string str)
{
    vector<string> ans;
    solve(str, ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
    /* TC-O(n * n!) SC-O(n) */
}