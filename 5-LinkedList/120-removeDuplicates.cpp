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

/* method 1 (using map data structure)*/
void removeDuplicatess(Node *head)
{
    unordered_map<int, bool> track;
    Node *temp = head;
    while (temp)
    {
        if (track.find(temp->data) == track.end())
            cout << temp->data << " ";
        track[temp->data] = true;
        temp = temp->next;
    }
    /* TC-O(n) SC-O(n) */
}

/* method 2 (using comparing)*/
Node *removeDuplicates(Node *head)
{
    if (head == nullptr or head->next == nullptr)
        return head;

    Node *curr = head;

    while (curr->next != nullptr)
    {
        if (curr->data == curr->next->data)
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            continue;
        }
        curr = curr->next;
    }
    return head;
    /* TC-O(n) SC-O(1) */
}