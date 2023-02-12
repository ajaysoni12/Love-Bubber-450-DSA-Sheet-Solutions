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

/* method 1 (but is not fullfill given constraints)*/
Node *addOne(Node *head)
{
    // edge case
    if (head == nullptr)
        return head;

    int num = 0; // store number

    Node *last = head;
    while (last != nullptr)
    {
        num = num * 10 + last->data; // add digit
        last = last->next;
    }

    last = nullptr; // this is head
    num = num + 1;  // add '1'

    while (num != 0) // number not equal to zero
    {
        int rem = num % 10;

        Node *temp = new Node(rem); // create node and put rem
        temp->next = last;
        last = temp;
        num /= 10;
    }
    return last;
}

/* method 2 (using reverse list and adding 1 and again reverse list)*/
Node *reverseList(Node *head)
{
    // base case
    if (head == nullptr or head->next == nullptr)
        return head;

    Node *prev, *next;
    prev = next = nullptr;
    while (head != nullptr)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
Node *addOne(Node *head)
{
    // first reverse list
    head = reverseList(head);
    int carry = 1; // intial carry will be 1

    Node *temp = head;
    // temp->next because in last you want to add carry
    while (temp->next != nullptr)
    {
        int sum = temp->data + carry;
        int rem = sum % 10;
        carry = sum / 10;
        temp->data = rem;

        temp = temp->next;
    }
    int sum = temp->data + carry;
    if (sum > 9)
    {
        int rem = sum % 10;
        carry = sum / 10;
        temp->data = rem;
        Node *n = new Node(carry);
        temp->next = n;
    }
    else
        temp->data = sum;

    head = reverseList(head);
    return head;
    /* TC-O(n) SC-O(1) */
}