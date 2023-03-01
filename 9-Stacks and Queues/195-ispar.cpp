#include <bits/stdc++.h>
using namespace std;

bool ispar(string str)
{
    stack<char> st;
    for (int i = 0; i < str.size(); i++)
    {
        if (st.empty())
            st.push(str[i]);
        else if ((st.top() == '(' and str[i] == ')') or (st.top() == '[' and str[i] == ']') or (st.top() == '{' and str[i] == '}'))
            st.pop();
        else
            st.push(str[i]);
    }
    return st.empty();
    /* TC-O(n) SC-O(n) n = str.size() */
}
