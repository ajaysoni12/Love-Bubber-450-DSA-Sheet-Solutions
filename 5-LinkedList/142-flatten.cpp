#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

/* method 1 (brute force approach - using extra space) */
Node *flatten(Node *root)
{
    // edge case
    if (root == nullptr)
        return root;

    vector<int> v; // store ele of linked-list

    // traverse all element
    Node *row = root;
    while (row != nullptr)
    {
        Node *col = row;
        while (col != nullptr)
        {
            v.push_back(col->data);
            col = col->bottom;
        }
        row = row->next;
    }

    // need to sort
    sort(v.begin(), v.end());

    // need to flat
    Node *head = new Node(0);
    Node *curr = head;
    for (int i : v)
    {
        curr->bottom = new Node(i);
        curr = curr->bottom;
    }
    curr->bottom = nullptr;
    return head->bottom; // return bottom pointer because question need
    /* TC-O(n*k) k = bottom list size(differ) SC-O(2*n*k) */
}

/* method 2 (using recursion) */
Node *mergeList(Node *first, Node *second)
{
    // this point currLast node
    Node *temp = new Node(0);

    // this point bottom flatter list head
    Node *res = temp;

    // till anyone not empty
    while (first != nullptr and second != nullptr)
    {
        if (first->data <= second->data)
        {
            temp->bottom = first;
            first = first->bottom;
        }
        else
        {
            temp->bottom = second;
            second = second->bottom;
        }
        temp = temp->bottom;
    }

    // if any one empty then assign other list
    temp->bottom = first != nullptr ? first : second;
    return res->bottom; // res->bottom is head of flatten list
}
Node *flatten(Node *root)
{
    // base case
    if (root == nullptr or root->next == nullptr)
        return root;

    // till when we not reach last node
    root->next = flatten(root->next);

    // then merge second_last and last list
    root = mergeList(root, root->next);

    return root; // return first list
    /* TC-O(n*n*m) SC-O(1) */
 }