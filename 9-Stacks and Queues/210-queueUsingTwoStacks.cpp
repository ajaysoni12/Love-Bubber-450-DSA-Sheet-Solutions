#include <bits/stdc++.h>
using namespace std;

class StackQueue
{
private:
    stack<int> s1;
    stack<int> s2;

public:
    void push(int);
    int pop();
};

void StackQueue ::push(int x)
{
    s1.push(x); // push x in s1
    /* TC-O(1) SC-O(1) */
}

int StackQueue ::pop()
{
    // check s1 not empty
    if (s1.empty())
        return -1;

    // pop all element, only left single element and push in s2 stack
    while (s1.size() > 1)
    {
        s2.push(s1.top());
        s1.pop();
    }

    // than pop last ele of s1 stack
    int ele = s1.top();
    s1.pop();

    // then agian push element in s1
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
    return ele; // pop element return
    /* TC-O(n+n=2n) SC-O(1) */
}