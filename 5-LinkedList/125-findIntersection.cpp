#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
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

/* method 1 (using map data structure or set)*/
Node *findIntersection(Node *head1, Node *head2)
{
    unordered_map<int, int> mp2;

    Node *temp = head2;
    while (temp != nullptr)
    {
        mp2[temp->data]++;
        temp = temp->next;
    }

    Node *res = nullptr;
    temp = head1;
    while (temp != nullptr)
    {
        if (mp2[temp->data] > 0)
        {
            Node *n = new Node(temp->data);
            n->next = res;
            res = n;
            mp2[temp->data]--;
        }
        temp = temp->next;
    }
    res = reverseList(res);
    return res;
    /* TC-O(n+m) SC-O(min(n+m)) */
}

/* method 2 (optimized opproach)*/
Node *findIntersection(Node *head1, Node *head2)
{
    Node *res = nullptr;

    Node *first = head1, *second = head2;
    while (first != nullptr and second != nullptr)
    {
        if (first->data == second->data)
        {
            Node *n = new Node(first->data);
            n->next = res;
            res = n;
            first = first->next;
            second = second->next;
        }
        else if (first->data < second->data)
            first = first->next;
        else
            second = second->next;
    }

    res = reverseList(res);
    return res;
    /* TC-O(min(n+m)) SC-O(min(n+m)) */
}