#include <bits/stdc++.h>
using namespace std;

/* method 1 (using stack) */
void interLeaveQueue(queue<int> &q)
{
    // To check the even number of elements
    if (q.size() % 2 != 0)
        cout << "Input even number of integers." << endl;

    // Initialize an empty stack of int type
    stack<int> s;
    int halfSize = q.size() / 2;

    // Push first half elements into the stack
    // queue:16 17 18 19 20, stack: 15(T) 14 13 12 11
    for (int i = 0; i < halfSize; i++)
    {
        s.push(q.front());
        q.pop();
    }

    // enqueue back the stack elements
    // queue: 16 17 18 19 20 15 14 13 12 11
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    // dequeue the first half elements of queue
    // and enqueue them back
    // queue: 15 14 13 12 11 16 17 18 19 20
    for (int i = 0; i < halfSize; i++)
    {
        q.push(q.front());
        q.pop();
    }

    // Again push the first half elements into the stack
    // queue: 16 17 18 19 20, stack: 11(T) 12 13 14 15
    for (int i = 0; i < halfSize; i++)
    {
        s.push(q.front());
        q.pop();
    }

    // interleave the elements of queue and stack
    // queue: 11 16 12 17 13 18 14 19 15 20
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
    /* TC-O(n) SC-O(n) */
}

/* method 2 (using extra space) */
void interLeaveQueue(queue<int> &q)
{
    vector<int> arr(q.size());

    // copy all element
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = q.front();
        q.pop();
    }

    // find middle index
    int mid = arr.size() / 2;
    for (int i = 0; mid < arr.size(); i++)
    {
        q.push(arr[i]);
        q.push(arr[mid]);
        mid++;
    }
    /* TC-O(n) SC-O(n) */
}

/* method 3 (using queue) */
void interLeaveQueue(queue<int> &q)
{
    // To check the even number of elements
    if (q.size() % 2 != 0)
        cout << "Input even number of integers." << endl;

    // Initialize an empty queue of int type
    queue<int> temp;
    int halfSize = q.size() / 2;

    // Push first half elements into the stack
    // queue:16 17 18 19 20, queue: 11 12 13 14 15
    for (int i = 0; i < halfSize; i++)
    {
        temp.push(q.front());
        q.pop();
    }

    // enqueue back the queue elements alternatively
    // queue: 11 16 12 17 13 18 14 19 15 20
    while (!temp.empty())
    {
        q.push(temp.front());
        q.push(q.front());
        q.pop();
        temp.pop();
    }
    /* TC-O(n) SC-O(n) */
}

int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    interLeaveQueue(q);
    int length = q.size();
    for (int i = 0; i < length; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}