#include <bits/stdc++.h>
using namespace std;

class QueueStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int);
    int pop();
};

void QueueStack ::push(int x)
{
    q1.push(x);
    /* TC-O(1) SC-O(1) */
}

int QueueStack ::pop()
{
    // if q1 empty then return -1
    if (q1.size() == 0)
        return -1;
    else
    {
        // pop all element and insert into q2
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q1.pop(); // and delete remaning one element

        // then copy all element into previous queue(q1)
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return x;
    }
    /* TC-O(n) SC-O(1) */
}