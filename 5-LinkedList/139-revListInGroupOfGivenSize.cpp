#include <bits/stdc++.h>

using namespace std;

// a node of the doubly linked list
struct Node
{
    int data;
    Node *next, *prev;
};

Node *reverseList(Node *head)
{
    if (head == nullptr or head->next == nullptr)
        return head;

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

/* method 1 (brute force approach) */
Node *revListInGroupOfGivenSize(Node *head, int k)
{
    Node *newHead = head;
    while (newHead != nullptr)
    {
        // point last node in k pos
        int cnt = 1;
        Node *last = newHead;
        while (cnt < k and last->next != nullptr)
        {
            cnt++;
            last = last->next;
        }

        Node *t = last->next; // no need to caculate again next head pointer

        // swap data using two pointer technique
        while (newHead != last and newHead->prev != last)
        {
            swap(newHead->data, last->data);
            newHead = newHead->next;
            last = last->prev;
        }
        newHead = t; // next window
    }
    return head; // this is head pointer of list
    /* TC-O(n*k) SC-O(1) */
}

Node *getNode(int data)
{
    // allocate space
    Node *new_node = (Node *)malloc(sizeof(Node));

    // put in the data
    new_node->data = data;
    new_node->next = new_node->prev = NULL;
    return new_node;
}

// function to insert a node at the beginning
// of the Doubly Linked List
void push(Node **head_ref, Node *new_node)
{
    // since we are adding at the beginning,
    // prev is always NULL
    new_node->prev = NULL;

    // link the old list of the new node
    new_node->next = (*head_ref);

    // change prev of head node to new node
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    // move the head to point to the new node
    (*head_ref) = new_node;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

// Driver program to test above
int main()
{
    // Start with the empty list
    Node *head = NULL;

    // Create doubly linked: 10<->8<->4<->2
    push(&head, getNode(1));
    push(&head, getNode(2));
    push(&head, getNode(3));
    push(&head, getNode(4));
    push(&head, getNode(5));
    push(&head, getNode(6));
    push(&head, getNode(7));
    push(&head, getNode(8));
    int k = 3;

    cout << "Original list: ";
    printList(head);

    // Reverse doubly linked list in groups of
    // size 'k'
    head = revListInGroupOfGivenSize(head, k);

    cout << "\nModified list: ";
    printList(head);

    return 0;
}