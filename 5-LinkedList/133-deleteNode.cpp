#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

/* method 1 (brute force approach) */
void deleteNode(struct Node **head, int key)
{
    // convert ** to single pointer
    Node *temp = *head;

    // base case, if single not or empty list
    if (head == nullptr or temp->next == nullptr)
        return;

    // first node and last node exclude while deleting node
    // that's why curr = temp->next
    // and curr != temp means you cann't deleted first node and last node but list is circular so both point to same(first == last)
    Node *prev = temp, *curr = temp->next;
    while (curr != temp)
    {
        // data found, need to deleted
        if (curr->data == key)
        {
            // delete node
            prev->next = curr->next;
            delete curr;
            return;
        }
        // update pointers
        prev = curr;
        curr = curr->next;
    }
    /* TC-O(n) SC-O(1) */
}

void reverse(struct Node **head_ref)
{
    Node *head = *head_ref;
    Node *prev = head;
    while (prev->next != head)
        prev = prev->next;
    Node *next;
    Node *temp = head;
    do
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    } while (temp != head);
    head_ref = &prev;
    /* TC-O(n) SC-O(1)*/
}