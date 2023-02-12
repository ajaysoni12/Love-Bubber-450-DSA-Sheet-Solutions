#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* method 1 (using floyd-cycle algo)*/
bool isCircular(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) // circular linked-list
            return 1;
    }
    return 0; // not circular
}

/* method 2 (using brute force approach) */
bool isCircular(Node *head)
{
    Node *temp = head->next;
    while (temp != nullptr)
    {
        if (temp == head)
            return 1;
        temp = temp->next;
    }
    return 0;
}
