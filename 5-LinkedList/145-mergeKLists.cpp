#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* method 1 (brute force appraoch - using priority queue) */
Node *mergeKLists(Node *arr[], int k)
{
    priority_queue<int> pq; // store all elemenets of list
    for (int i = 0; i < k; i++)
    {
        while (arr[i] != nullptr)
        {
            pq.push(arr[i]->data);
            arr[i] = arr[i]->next;
        }
    }

    // now insert
    Node *newHead = new Node(0);
    Node *curr = newHead;
    while (pq.size() > 0)
    {
        int val = pq.top();
        pq.pop();
        Node *n = new Node(val);
        curr->next = n;
        curr = n;
    }
    return newHead->next;
    /* TC-O(n*k*log(k)) SC-O(k) */
}

/* method 2 (using merge sort technique) */
Node *mergeList(Node *first, Node *second)
{
    Node *newHead = new Node(0);
    Node *curr = newHead;

    while (first != nullptr and second != nullptr)
    {
        if (first->data <= second->data)
        {
            curr->next = first;
            first = first->next;
        }
        else
        {
            curr->next = second;
            second = second->next;
        }
        curr = curr->next;
    }

    curr->next = first == nullptr ? second : first;
    return newHead->next;
}

Node *mergeKLists(Node *arr[], int k)
{
    if (arr[0] == nullptr)
        return arr[0];

    for (int i = k - 1; i > 0; i--)
        arr[i - 1] = mergeList(arr[i], arr[i - 1]);
    return arr[0];
    /* TC-O(k*n) SC-O(1) */
}