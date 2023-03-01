#include <bits/stdc++.h>
using namespace std;

// only for 4 binary operator and single digit
int evaluatePostfix(string str)
{
    stack<int> st;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            st.push(str[i] - '0');
            continue;
        }
        int first = st.top();
        st.pop();
        int second = st.top();
        st.pop();
        switch (str[i])
        {
        case '*':
            st.push(second * first);
            break;
        case '+':
            st.push(second + first);
            break;
        case '-':
            st.push(second - first);
            break;
        case '/':
            st.push(second / first);
            break;
        }
    }
    return st.top();
    /* TC-O(n) SC-O(n) */
}

/* multiple digit */
int evaluatePostfix(string str)
{
    stack<int> st;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
            continue;

        // extract number
        else if (str[i] >= '0' and str[i] <= '9')
        {
            int num = 0;
            while (str[i] >= '0' and str[i] <= '9')
            {
                num = num * 10 + (int)(str[i] - '0');
                i++;
            }
            i--;
            st.push(num);
            continue;
        }

        int first = st.top();
        st.pop();
        int second = st.top();
        st.pop();
        switch (str[i])
        {
        case '*':
            st.push(second * first);
            break;
        case '+':
            st.push(second + first);
            break;
        case '-':
            st.push(second - first);
            break;
        case '/':
            st.push(second / first);
            break; 
        }
    }
    return st.top();
    /* TC-O(n) SC-O(n) */
}