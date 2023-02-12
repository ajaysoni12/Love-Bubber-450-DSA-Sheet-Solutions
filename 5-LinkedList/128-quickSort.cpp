#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* method 1 (using extra space) */
void quickSort(struct node **headRef)
{
    node *temp = *headRef;
    vector<int> v;
    while (temp != NULL)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }
    sort(v.begin(), v.end());
    temp = *headRef;
    for (int i = 0; i < v.size(); i++)
    {
        temp->data = v[i];
        temp = temp->next;
    }
}

/* method 2 (using quick sort algo) */
node *getTailNode(node *head)
{
    node *temp = head;
    while (temp != nullptr and temp->next != nullptr)
        temp = temp->next;
    return temp;
}
node *partion(node *head, node *tail)
{
    // head node my pivot
    node *pivot = head;

    node *curr = head->next, *prev = head;

    // go till curr to last node
    while (curr != tail->next)
    {
        // if pivot data is greater then curr data then swap prev and curr data
        if (pivot->data > curr->data)
        {
            swap(prev->next->data, curr->data);
            prev = prev->next;
        }
        curr = curr->next;
    }

    // in last swap prev and pivot data
    swap(prev->data, pivot->data);
    return prev; // and prev my pivot node
}
void solve_sort(node *head, node *tail)
{
    // if single node contain or no node then return
    if (head == nullptr or tail == nullptr or head == tail)
        return;

    node *pivot = partion(head, tail); // return correct positions pivot(left part less than and right part grater then pviot)
    solve_sort(head, pivot);           // left part
    solve_sort(pivot->next, tail);     // right part
}
void quickSort(struct node **headRef)
{
    node *head = *headRef;
    // if array already sorted
    if (head == nullptr or head->next == nullptr)
        return;

    node *tail = getTailNode(head); // find lastNode

    solve_sort(head, tail);
}