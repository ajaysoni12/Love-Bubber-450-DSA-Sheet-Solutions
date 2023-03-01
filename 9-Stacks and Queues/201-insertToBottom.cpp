#include <bits/stdc++.h>
using namespace std;

/* method 1 (using extra space)*/
void insertToBottom(stack<int> st, int num)
{
    // create new stack
    stack<int> temp;

    // push all element into temp
    while (!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }

    // push num into st
    st.push(num);

    // again push temp element into st
    while (!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }
    /* TC-O(n) SC-O(n) */
}

/* method 2 (using recursion-efficient approach) */
void insertToBottom(stack<int> &st, int num)
{
    // if stack empty then push num
    if (st.empty())
    {
        st.push(num);
        return;
    }

    // keep track of curr top() elemenet
    int temp = st.top();
    st.pop(); // pop element

    // further call till stack not empty
    insertToBottom(st, num);

    // now when we backtrack we put all other elemenet one by one
    st.push(temp);
    /* TC-O(n) SC-O(n) */
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    insertToBottom(st, 15);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}