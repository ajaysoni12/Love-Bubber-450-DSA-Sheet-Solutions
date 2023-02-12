#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

/* method 1 (using set or map data structure)*/
void removeLoop(Node *head)
{
    // base case
    if (head == nullptr or head->next == nullptr)
        return;

    // no duplicate address
    unordered_set<Node *> set;

    // intially curr is head
    Node *curr = head;

    while (curr != nullptr)
    {
        // first insert
        set.insert(curr);

        // check for next addresss
        if (set.find(curr->next) != set.end())
        {
            curr->next = nullptr;
            return;
        }

        curr = curr->next;
    }
    /* TC-O(n) SC-O(n) */
}

/* method 2 (floyd-cycle algorithm)*/
void removeLoop(Node *head)
{
    // edge case
    if (head == nullptr or head->next == nullptr)
        return;

    // self loop
    if (head->next == head)
    {
        head->next = nullptr;
        return;
    }

    Node *slow = head, *fast = head, *prev = nullptr;

    while (slow != nullptr and fast != nullptr and fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    // if slow and fast pointing to head then we need to incease high find slow and break loop
    if (slow == head and fast == head)
    {
        while (fast->next != slow)
            fast = fast->next;
        fast->next = nullptr;
        return;
    }
    // if slow and fast is same then we need to search from starting, so update slow = head then move both of the pointer by one
    else if (slow == fast)
    {
        slow = head;
        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = nullptr;
        return;
    }
    /* TC-O(n) SC-O(1) */
}