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

/* method 1 (using two loops)*/
void removeDuplicates(struct Node *start)
{
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = start;

    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        /* Compare the picked element with rest
           of the elements */
        while (ptr2->next != NULL)
        {
            /* If duplicate then delete it */
            if (ptr1->data == ptr2->next->data)
            {
                /* sequence of steps is important here */
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else /* This is tricky */
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    /* TC-O(n^2) SC-O(1) */
}

/* method 2 (using set or map data structure)*/
Node *removeDuplicatess(Node *head)
{
    // edge case
    if (head == nullptr or head->next == nullptr)
        return head;

    Node *curr = head;
    unordered_set<int> set;
    set.insert(curr->data);

    while (curr->next != nullptr)
    {
        // if found then not remove link
        if (set.find(curr->next->data) != set.end())
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            continue;
        }
        // update and inserted data
        curr = curr->next;
        set.insert(curr->data);
    }
    return head;
    /* TC-O(n) SC-O(n) */
}