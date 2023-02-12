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

/* method 1 (using set data structure) */
bool detectLoop(Node *head)
{
    // unique node address store
    unordered_set<Node *> set;

    while (head != nullptr)
    {
        // if node address found means cycle created
        if (set.find(head) != set.end())
            return true;
        // otherwise node address inserted
        set.insert(head);
        // keep updating pointer
        head = head->next;
    }
    return false; // cycle not found
    /* TC-O(n) SC-O(n) */
}

/* method 2 (floyd cycle-finding algorithm) */
bool detectLoop(Node *head)
{
    // edge case
    if (head == nullptr or head->next == nullptr)
        return false;

    // self loop
    if (head == head->next)
        return true;

    Node *slow, *fast;
    slow = head;
    fast = head;

    while (slow != nullptr and fast != nullptr and fast->next != nullptr)
    {
        // slow update by one
        slow = slow->next;
        // fast update by two
        fast = fast->next->next;
        if (slow == fast)
            return true; // cycle found
    }

    return false; // cycle not found
    /* TC-O(n) SC-O(1) */
}