#include <bits/stdc++.h>
using namespace std;

/* method 1 (using stack)*/
bool ispar(string x)
{
    // create stack of char type
    stack<char> stack;

    // apply loop from 0 to x.size()
    for (int i = 0; i < x.size(); i++)
    {
        // if empty push back
        if (stack.empty())
            stack.push(x[i]);

        // now compare with top
        else if ((stack.top() == '(' && x[i] == ')') || (stack.top() == '{' && x[i] == '}') || (stack.top() == '[' && x[i] == ']'))
            stack.pop();

        // if not equal then push_back
        else
            stack.push(x[i]);
    }

    // in last return true if empty or return false
    return stack.empty();
    /* TC-O(N) SC-O(N) */
}