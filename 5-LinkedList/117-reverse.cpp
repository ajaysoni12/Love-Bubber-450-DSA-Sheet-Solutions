#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }

} * head;

/* Reverses the linked list in groups of size k and returns the pointer to the new head node.

    method 1 (using extra space + recursive)*/
struct node *reverse(struct node *head, int k)
{
    // base case
    if (head == nullptr)
        return head;
    node *prev, *next, *curr;
    prev = next = nullptr;
    curr = head;
    int cnt = 0;

    // reverse k nodes in given linked-list
    while (curr != nullptr and cnt < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    // next will be point k+1th nodes, if linked-list is not empty we again apply rec
    if (next != nullptr)
        head->next = reverse(next, k);

    return prev; // this will be assign in head->next

    /* Complexity Analysis :
        Time Complexity : O(n)
        Traversal of list is done only once and it has ‘n’ elements.

        Auxiliary Space : O(n / k)
        For each Linked List of size n, n / k or (n / k) + 1 calls will be made during the recursion.
    */
}

/* method 2 (using iterative way - space optimization) */
struct node *reverse(struct node *head, int k)
{
    // If head is NULL or K is 1 then return head
    if (head == nullptr or k == 1)
        return head;

    // creating dummy node
    node *dummy = new node(-1);
    dummy->next = head;

    // Initializing three points prev, curr, next
    node *prev = dummy, *curr = dummy, *next = dummy;

    // Calculating the length of linked list
    int cnt = 0;
    while (curr != nullptr)
    {
        cnt++;
        curr = curr->next;
    }

    // itrating till cnt >= k(cnt/k - no. of group of size k)
    while (cnt >= k)
    {
        // curr pos after reversing
        curr = prev->next;
        // next always point curr->next
        next = curr->next;

        // apply loop less than k because if k is three so we need to change only two pointers
        for (int i = 1; i < k; i++)
        {
            // pointer manipulations
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }
        // next group my prev update
        prev = curr;
        cnt -= k;
    }
    // dummy -> next will be our new head for output linked list
    return dummy->next;
    /* TC-O(n/k * k = n) SC-O(1) */
}