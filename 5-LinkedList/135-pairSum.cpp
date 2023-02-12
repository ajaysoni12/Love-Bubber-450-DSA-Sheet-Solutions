#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next, *prev;
};

/* method 1 (extremly brute force approach) */
void pairSum(struct Node *head, int x)
{
    Node *outerLoop = head;
    while (outerLoop->next != nullptr)
    {
        Node *innerLoop = outerLoop->next;
        while (innerLoop != nullptr)
        {
            int sum = outerLoop->data + innerLoop->data;
            if (sum == x)
                cout << "(" << outerLoop->data << "," << innerLoop->data << ") ";
            innerLoop = innerLoop->next;
        }
        outerLoop = outerLoop->next;
    }
    /* TC-O(n^2) SC-O(1) */
}

/* method 2 (two pointer appraoch) */
void pairSum(struct Node *head, int x)
{
    // edge case
    if (head == nullptr)
        return;

    // find last node
    Node *start = head, *tail = head;
    while (tail->next != nullptr)
        tail = tail->next;

    bool ok = false; // pair found or not

    // start->prev !- tail or tail->next != start means both node cross each other
    while (start != tail and start->prev != tail)
    {
        int sum = start->data + tail->data;
        if (sum == x)
        {
            ok = true;
            cout << "(" << start->data << "," << tail->data << ") ";
            start = start->next;
            tail = tail->prev;
        }
        else if (sum < x)
            start = start->next;
        else
            tail = tail->prev;
    }
    if (ok == false)
        cout << "No pair found";
    /* TC-O(n) SC-O(1) */
}
