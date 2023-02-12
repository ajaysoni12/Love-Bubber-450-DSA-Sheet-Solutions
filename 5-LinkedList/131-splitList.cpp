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

/* method 1 (using floyd-cycle algo) */
void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // find last node address
    Node *tail = head;
    while (tail->next != head)
        tail = tail->next;

    // floyd-cycle algo
    Node *slow = head, *fast = head->next;
    while (fast != head and fast->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // pointer manipulation
    *head1_ref = head;
    *head2_ref = slow->next;
    slow->next = *head1_ref;
    tail->next = *head2_ref;
}
