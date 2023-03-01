#include <bits/stdc++.h>
using namespace std;

class twoStacks
{
private:
    int *arr;
    int size;
    int top1, top2;

public:
    twoStacks(int n = 100)
    {
        size = n;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }
    void push1(int x);
    void push2(int x);
    int pop1();
    int pop2();
};

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        twoStacks *sq = new twoStacks();

        int q;
        cin >> q;
        while (q--)
        {
            int stackNo;
            cin >> stackNo;
            int qeuryType = 0;
            cin >> qeuryType;
            if (qeuryType == 1)
            {
                int a;
                cin >> a;
                if (stackNo == 1)
                    sq->push1(a);
                else if (stackNo == 2)
                    sq->push2(a);
            }
            else if (qeuryType == 2)
            {
                if (stackNo == 1)
                    cout << sq->pop1() << " ";
                else if (stackNo == 2)
                    cout << sq->pop2() << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

void twoStacks::push1(int x)
{
    if (top1 < top2 - 1)
        arr[++top1] = x;
    /* TC-O(1) SC-O(1) */
}

void twoStacks ::push2(int x)
{
    if (top1 + 1 < top2)
        arr[--top2] = x;
    /* TC-O(1) SC-O(1) */
}

int twoStacks ::pop1()
{
    int data = -1;
    if (top1 >= 0)
        data = arr[top1--];
    return data;
    /* TC-O(1) SC-O(1) */
}

int twoStacks ::pop2()
{
    int data = -1;
    if (top2 < size)
        data = arr[top2++];
    return data;
    /* TC-O(1) SC-O(1) */
}
