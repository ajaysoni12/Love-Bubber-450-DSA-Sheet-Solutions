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

/* method 1 (using naive appraoch) */
int printNthFromLast(Node *head, int N)
{
    int len = 0, i;
    Node *temp = head;

    // Count the number of nodes in Linked List
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }

    // Check if value of N is not more than length of the linked list
    if (len < N)
        return -1;

    temp = head;

    // Get the (len-N+1)th node from the beginning
    for (i = 1; i < len - N + 1; i++)
        temp = temp->next;
    return temp->data;
    /* TC-O(n + (n-N) = 2n-N) SC-O(1) */
}

/* method 2 (using optimized approach) */
Node *reverseList(Node *head)
{
    Node *prev = nullptr, *next = nullptr;

    while (head != nullptr)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
int getNthFromLast(Node *head, int n)
{
    head = reverseList(head);

    int cnt = 0;
    while (head != nullptr)
    {
        cnt++;
        if (cnt == n)
            return head->data;
        head = head->next;
    }
    return -1;
    /* TC-O(2n) SC-O(1) */
}
