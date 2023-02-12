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

/* method 1 (using set or map data structure) */
int findFirstNode(Node *head)
{
    // edge case
    if (head == nullptr or head->next == nullptr)
        return -1;
    if (head->next == head)
        return head->data;

    unordered_set<Node *> set;

    Node *curr = head;
    while (curr != nullptr)
    {
        if (set.find(curr) != set.end())
            return curr->data;
        set.insert(curr);
        curr = curr->next;
    }
    return -1;
    /* TC-O(n) SC-O(n) */
}

/* method 2 (using floyd-cycle alog)*/
int findFirstNode(Node *head)
{
    if (head == nullptr or head->next == nullptr)
        return -1;
    if (head->next == head)
        return head->data;

    Node *slow = head, *fast = head;

    while (slow != nullptr and fast != nullptr and fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) // cycle found
            break;
    }
    if (slow == head and fast == head)
        return head->data; // just need to return data
    else if (slow == fast)
    {
        slow = head; // need to traverse starting
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow->data;
    }
    return -1; // cycle not found
    /* TC-O(n) SC-O(1) */
}