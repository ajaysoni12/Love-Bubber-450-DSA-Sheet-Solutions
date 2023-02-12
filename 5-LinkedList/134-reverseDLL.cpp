#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

/* method 1 (brute force appraoch) */
Node *reverseDLL(Node *head)
{
    // edge case, no need to reversal
    if (head == nullptr or head->next == nullptr)
        return head;

    // universal reversal technique
    Node *prev = nullptr, *next = nullptr;
    while (head != nullptr)
    {
        next = head->next; // next point to head->next
        head->next = prev; // head->next point to prev
        head->prev = next; // head->prev point to next
        prev = head;       // prev point to head
        head = next;       // head update to next
    }
    return prev; // prev point to last node or say reverse list first node
    /* TC-O(n) SC-O(1) */
}