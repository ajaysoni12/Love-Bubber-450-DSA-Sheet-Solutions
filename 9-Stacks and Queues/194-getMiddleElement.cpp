#include <bits/stdc++.h>
using namespace std;

class myStack
{
    stack<int> st;
    deque<int> dq;

public:
    void add(int data)
    {
        dq.push_back(data);
        if (dq.size() > st.size() + 1)
        {
            int temp = dq.front();
            dq.pop_front();
            st.push(temp);
        }
    }

    void pop()
    {
        int data = dq.back();
        dq.pop_back();
        if (st.size() > dq.size())
        {
            int temp = st.top();
            st.pop();
            dq.push_front(temp);
        }
    }

    int getMiddleEle() { return dq.front(); }
    int deleteMiddleEle()
    {
        dq.pop_front();
        if (st.size() > dq.size())
        {
            int temp = st.top();
            st.pop();
            dq.push_front(temp);
        }
    }
};