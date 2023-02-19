#include <bits/stdc++.h>
using namespace std;

/* method 1 (using recursion) */
void solve(int n, string str, string res, unordered_map<string, int> &hashMap, vector<string> &ans)
{
    // when str size is zero means setence are ready
    if (str.size() == 0)
    {
        // remove last space
        ans.push_back(res.substr(0, res.size() - 1));
        res.clear(); // and clear res
        return;
    }

    // for all words
    for (int i = 0; i < str.size(); i++)
    {
        // 0 to ith word
        string left = str.substr(0, i + 1);

        // if left word find then search for other right part same code
        if (hashMap.find(left) != hashMap.end())
        {
            string right = str.substr(i + 1);
            solve(n, right, res + left + " ", hashMap, ans);
        }
        // then again take i+1th part
    }
}
vector<string> wordBreak(int n, vector<string> &dict, string s)
{
    vector<string> ans;
    unordered_map<string, int> hashMap;
    for (int i = 0; i < dict.size(); i++)
        hashMap[dict[i]] = 1;
    solve(n, s, "", hashMap, ans);
    return ans;
    /* Time Complexity: O(2^n). Because there are 2n combinations in The Worst Case.
    Auxiliary Space: O(n^2). Because of the Recursive Stack of wordBreakUtil(…) function in The Worst Case. */
}

/* word beak 1 */
int solve(string str, unordered_map<string, int> &dict)
{
    if (str.size() == 0)
        return 1;
    for (int i = 0; i < str.size(); i++)
    {
        string left = str.substr(0, i + 1);
        if (dict.find(left) != dict.end())
        {
            string right = str.substr(i + 1);
            if (solve(right, dict))
                return 1;
        }
    }
    return 0;
}
int wordBreak(string str, vector<string> &dict)
{

    unordered_map<string, int> mp;
    for (int i = 0; i < dict.size(); i++)
        mp[dict[i]] = 1;

    return solve(str, mp);
}