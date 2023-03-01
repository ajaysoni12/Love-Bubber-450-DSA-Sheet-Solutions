#include <bits/stdc++.h>
using namespace std;

/* method 1 (using stack) */
bool checkRedundancy(string &str)
{
    stack<char> st; // store character

    for (int i = 0; i < str.size(); i++)
    {
        // if curr char is not equal to ')' then push all other character
        // except stack not empty
        if (str[i] != ')' or st.empty())
            st.push(str[i]);
        else
        {
            // remove all element till not get open bracket and when remove then also check that bracket between any operator present or not
            bool flag = true;
            while (!st.empty() and st.top() != '(')
            {
                if (st.top() == '+' or st.top() == '-' or st.top() == '*' or st.top() == '/')
                    flag = false;
                st.pop();
            }

            // if flag true means redundancy present
            if (flag)
                return true;
            st.pop();
        }
    }
    return false; // redundancy not present
    /* TC-O(n) SC-O(n) */
}

/* method 2 (using count variable) */
bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}
bool hasRedundantBrackets(string str)
{
    int n = str.length();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
            count++;
        else if (str[i] == ')')
        {
            if (count <= 1)
                return true;
            else
            {
                count--;
                while (i < n - 1 && isOperator(str[i + 1]))
                    i += 2;
            }
        }
        else if (isOperator(str[i]))
            continue;
    }
    return false;
    /* TC-O(n) SC-O(1) */
}