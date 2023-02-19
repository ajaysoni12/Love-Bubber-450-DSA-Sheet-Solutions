#include <bits/stdc++.h>
using namespace std;

void solve(string str, string &ans, int indx, int k)
{
    ans = max(ans, str);
    if (k == 0)
        return;
    for (int i = indx; i < str.size() - 1; i++)
    {
        for (int j = i + 1; j < str.size(); j++)
        {
            if (str[j] > str[i])
            {
                swap(str[i], str[j]);
                solve(str, ans, i + 1, k - 1);
                swap(str[i], str[j]);
            }
        }
    }
}
string findMaximumNum(string str, int k)
{
    // code here.
    string ans = "";
    solve(str, ans, 0, k);
    return ans;
}
