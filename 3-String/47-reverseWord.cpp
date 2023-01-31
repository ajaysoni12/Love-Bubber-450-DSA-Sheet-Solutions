#include <bits/stdc++.h>
using namespace std;

/* Method 1 (using extra space) */
string reverseWord(string str)
{
    string temp = "";

    for (int i = str.size() - 1; i >= 0; i--)
        temp += str[i];

    return temp;

    /*
        stack<char> st;
        for (int i=0; i<str.length(); i++)
            st.push(str[i]);

        for (int i=0; i<str.length(); i++) {
            str[i] = st.top();
            st.pop();
        }
    */
    /* TC-O(N) SC-O(N) */
}

/* Method 2 (using reverse function) */
string reverseWord(string str)
{
    reverse(str.begin(), str.end());
    return str;
    /* TC-O(N) SC-O(1) */
}

/* Method 3 (using two pointer approach) */
string reverseWord(string str)
{
    int start = 0;
    int end = str.size() - 1;

    while (start < end)
        swap(str[start++], str[end--]);
    return str;
    /* TC-O(N) SC-O(1) */
}

/* Method 4 (using recursive approach) */
void reverseWord(string str, int start, int end)
{
    if (start >= end)
        return;

    swap(str[start], str[end]);
    reverseWord(str, start + 1, end - 1);
}
