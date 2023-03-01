#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
private:
    int arr[100005];
    int front;
    int rear;

public:
    MyQueue()
    {
        front = 0;
        rear = 0;
    }
    void push(int);
    int pop();
};

void MyQueue ::push(int x)
{
    if (rear != 100004)
    {
        arr[rear] = x;
        rear++;
    }
    /* TC-O(1) SC-O(1) */
}

int MyQueue ::pop()
{
    int x = -1;
    if (rear != front)
    {
        x = arr[front];
        front++;
    }
    return x;
    /* TC-O(1) SC-O(1) */
}
