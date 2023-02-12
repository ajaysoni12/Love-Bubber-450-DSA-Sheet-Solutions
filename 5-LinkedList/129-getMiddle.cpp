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

/* method 1 (using extra space) */
int getMiddle(Node *head)
{
    if (head == nullptr)
        return -1;
    vector<int> temp;
    Node *curr = head;
    while (curr != nullptr)
    {
        temp.push_back(curr->data);
        curr = curr->next;
    }

    return temp[temp.size() / 2];
    /* TC-O(n) SC-O(n) */
}

/* method 2 (using floyed-cycle algo)*/
int getMiddle(Node *head)
{
    if (head == nullptr)
        return -1;

    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data; // middle element
    /* TC-O(n) SC-O(1) */
}