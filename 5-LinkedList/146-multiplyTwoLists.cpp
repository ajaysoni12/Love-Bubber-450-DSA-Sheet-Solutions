#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* method 1 (using brute force approach) */
const int mod = 1e9 + 7;
long long multiplyTwoLists(Node *l1, Node *l2)
{
    long long num1 = 0, num2 = 0;

    // generate numbers
    while (l1 or l2)
    {
        if (l1)
        {
            num1 = (num1 * 10 + l1->data) % mod;
            l1 = l1->next;
        }
        if (l2)
        {
            num2 = (num2 * 10 + l2->data) % mod;
            l2 = l2->next;
        }
    }

    long long mul = (num1 * num2) % mod;
    return mul;
    /* TC-O(n+m) SC-O(1) */
}