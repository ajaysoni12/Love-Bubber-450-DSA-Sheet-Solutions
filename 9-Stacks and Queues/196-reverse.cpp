#include <bits/stdc++.h>
using namespace std;

/* difference method available but here only we do by main method what is questioh req. */

/* method 1 (using stack) */
char *reverse(char *str, int len)
{
    // push all element into stack
    stack<char> st;
    for (int i = 0; i < len; i++)
        st.push(str[i]);

    // fetch top element and store into str
    int i = 0;
    while (!st.empty())
    {
        char ch = st.top();
        str[i++] = ch;
        st.pop();
    }

    // return reverse string
    return str;

    /* TC-O(2n) SC-O(n) */
}