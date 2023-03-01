#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach) */
void insertAtBottom(stack<int> &st, int x)
{
    // if stack empty then push x
    if (st.size() == 0)
        st.push(x);
    else
    {
        int temp = st.top();
        st.pop();
        insertAtBottom(st, x);

        // backtacking push element
        st.push(temp);
    }
}
void reverseStack(stack<int> &st)
{
    if (st.size() > 0)
    {
        int x = st.top();
        st.pop();
        reverseStack(st);
        insertAtBottom(st, x);
    }
    /* TC-O(n^2) SC-O(n) */
}

/* method 2 (efficient approach)*/
void recurr(stack<int> st, stack<int> &temp)
{
    // call recur functiont till st not empty
    if (st.empty())
        return;

    int x = st.top();
    st.pop();

    recurr(st, temp);

    // backtracking, put same value into another stack
    temp.push(x);
}
void reverseStack(stack<int> &st)
{
    stack<int> temp;  // create new stack
    recurr(st, temp); // call rec function

    // clear all elements
    while (!st.empty())
        st.pop();

    // now copy element in revese all
    while (!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }
    /* TC-O(n + n + n = 3n) SC-O(n + n)*/
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    reverseStack(st);
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    return 0;
}