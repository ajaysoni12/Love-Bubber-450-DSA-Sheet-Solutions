#include <bits/stdc++.h>
using namespace std;

/* method 1 (generate all permutations) */
void recurPermute(string str, int l, int r)
{
    int i;
    if (l == r)
        cout << str << endl;
    else
    {
        for (int i = l; i <= r; i++)
        {
            // swaping
            int temp = str[i];
            str[i] = str[l];
            str[l] = temp;

            recurPermute(str, l + 1, r);

            // backtracking
            int temp = str[i];
            str[i] = str[l];
            str[l] = temp;
        }
    }
}

void recurPermute(string &ds, string &nums, vector<string> &ans, int freq[])
{
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (!freq[i])
        {
            ds.push_back(nums[i]);
            freq[i] = 1;
            recurPermute(ds, nums, ans, freq);
            ds.pop_back();
            freq[i] = 0;
        }
    }
}

vector<string> find_permutation(string s)
{
    vector<string> ans;
    string ds;
    int freq[s.size()] = {0};

    recurPermute(ds, s, ans, freq);
    return ans;
}