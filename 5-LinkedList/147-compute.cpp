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

/* method 1 (brute force approach-using two loops) */
Node *compute(Node *head)
{
    // some edge cases
    if (head == nullptr or head->next == nullptr)
        return head;

    // this just pointing list
    Node *newHead = new Node(0);
    Node *curr = newHead;

    // for head - check all head->next element
    while (head != nullptr)
    {
        Node *temp = head->next;
        bool ok = false;
        while (temp != nullptr)
        {
            if (head->data < temp->data)
            {
                ok = true;
                break;
            }
            temp = temp->next;
        }

        // if head->data is lesser
        if (ok == true)
        {
            Node *t = head;
            head = head->next;
            delete t;
        }
        else
        {
            curr->next = head;
            curr = curr->next;
            head = head->next;
        }
    }
    return newHead->next;
    /* TC-O(n^2) SC-O(1) */
}

/* method 2 (optimized approach) */
Node *compute(Node *head)
{
    Node *curr = head;
    while (curr->next)
    {
        if (curr->data < curr->next->data)
        {
            curr->data = curr->next->data; // this condtions
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            curr = head; // this conditons
        }
        else
            curr = curr->next;
    }
    return head;
    /* TC-O(n) SC-O(1) */
}