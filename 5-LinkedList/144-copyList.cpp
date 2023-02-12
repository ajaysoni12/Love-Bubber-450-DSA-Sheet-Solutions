#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next, *arb;
    Node(int x)
    {
        data = x;
        next = arb = nullptr;
    }
};

/* method 1 (using hashing - extra space) */
Node *copyList(Node *head)
{
    Node *temp = head, *newHead;
    unordered_map<Node *, Node *> mp; // store temp, and their deep copy node address

    // first node , their deep copy
    newHead = new Node(temp->data);
    mp[temp] = newHead;

    // map node and their deep copy address
    while (temp->next != nullptr)
    {
        newHead->next = new Node(temp->next->data);
        temp = temp->next;
        newHead = newHead->next;
        mp[temp] = newHead;
    }

    // now connect arb address
    temp = head;
    while (temp != nullptr)
    {
        mp[temp]->arb = mp[temp->arb];
        temp = temp->next;
    }

    return mp[head]; // return head of copy list
    /* TC-O(n+n) SC-O(n) */
}

/* method 2 (using constant space) */
Node *copyList(Node *head)
{
    Node *iter = head;
    Node *front = head;

    /*  First Round: make copy of each node,
        and link them together side-by-side in a single list */
    while (iter != nullptr)
    {
        front = iter->next;
        Node *copy = new Node(iter->data);
        iter->next = copy;
        copy->next = front;
        iter = front;
    }

    /* Second Round: assign random pointers for the copy code */
    iter = head;
    while (iter != nullptr)
    {
        if (iter->arb != nullptr)
            iter->next->arb = iter->arb->next;
        iter = iter->next->next;
    }

    /* Third Round: restore the original list, and extract the copy list */
    iter = head;
    Node *pseudoHead = new Node(0);
    Node *copy = pseudoHead;

    while (iter != nullptr)
    {
        front = iter->next->next;

        // extra the copy
        copy->next = iter->next;

        // restore the orignal list
        iter->next = front;

        copy = copy->next;
        iter = front;
    }
    return pseudoHead->next;
    /* TC-(n+n+n = 3n) SC-O(1) */
}