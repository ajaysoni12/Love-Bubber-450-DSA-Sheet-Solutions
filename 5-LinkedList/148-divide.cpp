#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

/* method 1 (using extra space) */
Node *divide(int n, Node *head)
{
    vector<int> v1, v2;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
            v1.push_back(temp->data);
        else
            v2.push_back(temp->data);
        temp = temp->next;
    }

    temp = head;
    for (int i = 0; i < v1.size(); i++)
    {
        temp->data = v1[i];
        temp = temp->next;
    }
    for (int i = 0; i < v2.size(); i++)
    {
        temp->data = v2[i];
        temp = temp->next;
    }
    return head;
    /* TC-O(n+m+k) SC-O(1), n=size of list, m=size of v1, k=size of v2 */
}

/* method 2 (optimized approach) */
Node *divide(int N, Node *head)
{
    if (head == nullptr or head->next == nullptr)
        return head;

    Node *even = new Node(0);
    Node *odd = new Node(0);
    Node *curr_even = even;
    Node *curr_odd = odd;

    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data % 2 == 0)
        {
            curr_even->next = temp;
            curr_even = temp;
        }
        else
        {
            curr_odd->next = temp;
            curr_odd = temp;
        }
        temp = temp->next;
    }

    curr_odd->next = nullptr;
    curr_even->next = odd->next;
    return even->next;
    /* TC-O(n) SC-O(1) */
}