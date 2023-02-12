#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

/* method 1 (using itrative way)*/
struct Node *reverseList(struct Node *head)
{
    Node *t1, *t2;
    t1 = t2 = nullptr; // intilally it contain null
    while (head != nullptr)
    {
        t2 = head->next; // t2 contain just next node address
        head->next = t1;
        t1 = head;
        head = t2; // head = head->next
    }
    return t1; // point to last node
    /* TC-O(n) SC-O(1) */
}

/* method 2 (using recursive way) */
struct Node *reverseList(struct Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    struct Node *newNode = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newNode;
    /* TC-O(n) SC-O(n) stack*/
}
