#include <bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    int arr[1000];
    int top;

public:
    MyStack() { top = -1; }
    int pop();
    void push(int);
};

/* push element */
void MyStack ::push(int x)
{
    if (top >= 1000)
        return;
    top++;
    arr[top] = x;
    /* TC-O(1) SC-O(1) */
}

/* pop element */
int MyStack ::pop()
{
    if (top == -1)
        return -1;
    int x = arr[top];
    top--;
    return x;
    /* TC-O(1) SC-O(1) */
}
