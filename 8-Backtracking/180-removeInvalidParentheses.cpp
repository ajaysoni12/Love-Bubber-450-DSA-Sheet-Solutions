#include <bits/stdc++.h>
using namespace std;

vector<string> res;            // store resulatant
unordered_map<string, int> mp; // for res not contain duplicate

/* return how many parentesis are invalid */
int getMinInValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            st.push('(');
        else if (s[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
                st.pop();
            else
                st.push(')');
        }
    }
    return st.size();
}

void solve(string s, int minInv)
{
    // if string already present then no need to search
    if (mp[s] != 0)
        return;
    else
        mp[s]++; // otherwise increase cnt

    // means string not have invalid parenthesis
    if (minInv == 0)
    {
        // if all parenthesis is valid
        if (!getMinInValid(s))
            res.push_back(s);
        return;
    }

    // remove one character each and go for further recursion
    for (int i = 0; i < s.size(); i++)
    {
        string left = s.substr(0, i);
        string right = s.substr(i + 1);
        solve(left + right, minInv - 1);
    }
    return;
}

vector<string> removeInvalidParentheses(string s)
{
    solve(s, getMinInValid(s));
    sort(res.begin(), res.end());
    return res;
    /* Time Complexity: O(2^|S|)
    Expected Auxiliary Space: O(2^n) */
}