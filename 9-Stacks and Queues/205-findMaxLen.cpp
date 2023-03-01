#include <bits/stdc++.h>
using namespace std;

int findMaxLen(string s)
{
    stack<char> ct; // store brackets
    stack<int> ind; // store problem bracket index

    // intial step - store -1 into ind stack(because it's perfect for getting length)
    ind.push(-1);

    int len = 0;
    for (int i = 0; i < s.size(); i++)
    {
        // opening bracket always push
        if (s[i] == '(')
        {
            ct.push('(');
            ind.push(i);
        }
        else // closing bracket
        {
            if (!ct.empty() and ct.top() == '(')
            {
                ct.pop();
                ind.pop();
                len = max(len, i - ind.top()); // last problem bracket index
            }
            else
                ind.push(i); // problem brackets index store
        }
    }
    return len;
    /* TC-O(n) SC-O(2n) */
}

/* method 2 (space otimization)*/
int findMaxLen(string str)
{
    int mx_len = 0;
    int o_brac = 0, c_brac = 0;

    // left to right
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
            o_brac++;
        else
            c_brac++;

        if (o_brac == c_brac)
            mx_len = mx_len < (o_brac + c_brac) ? (o_brac + c_brac) : mx_len;
        else if (c_brac > o_brac)
            c_brac = o_brac = 0;
    }

    o_brac = c_brac = 0;
    // right to left
    for (int i = str.size() - 1; i >= 0; i--)
    {
        if (str[i] == '(')
            o_brac++;
        else
            c_brac++;

        if (o_brac == c_brac)
            mx_len = mx_len < (o_brac + c_brac) ? (o_brac + c_brac) : mx_len;
        else if (o_brac > c_brac)
            o_brac = c_brac = 0;
    }

    return mx_len;
    /* TC-O(n) SC-O(1) */
}