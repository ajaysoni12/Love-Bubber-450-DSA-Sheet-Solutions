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

/* method 1 (using two loops - extreamly brute force appraoch) */
int intersectPoint(Node *head1, Node *head2)
{
    Node *first = head1, *second;

    while (first != nullptr)
    {
        second = head2;
        while (second != nullptr)
        {
            if (first == second)
                return first->data; // not found
            second = second->next;
        }
        first = first->next;
    }
    return -1; // node not found
    /* TC-O(n*m) SC-O(1) - (n-fist list size, m-second list size) */
}

/* method 2 (using hashing)*/
int intersectPoint(Node *head1, Node *head2)
{
    unordered_set<Node *> set;
    Node *temp = head2;
    while (temp != nullptr)
    {
        set.insert(temp);
        temp = temp->next;
    }

    temp = head1;
    while (temp != nullptr)
    {
        if (set.find(temp) != set.end())
            return temp->data;
        temp = temp->next;
    }
    return -1;
    /* TC-O(n+m) SC-O(n) */
}

/* method 3 (first optimized approach)*/
int intersectPoint(Node *head1, Node *head2)
{
    int cnt1 = 0, cnt2 = 0;
    Node *temp1 = head1, *temp2 = head2;

    // count first list size
    while (temp1 != nullptr)
    {
        cnt1++;
        temp1 = temp1->next;
    }

    // count second list size
    while (temp2 != nullptr)
    {
        cnt2++;
        temp2 = temp2->next;
    }

    // make equal both of them
    while (head1 != nullptr and cnt1 > cnt2)
    {
        head1 = head1->next;
        cnt1--;
    }
    while (head2 != nullptr and cnt2 > cnt1)
    {
        head2 = head2->next;
        cnt2--;
    }

    // update by single node, when both of them equal break
    while (head1 != nullptr and head2 != nullptr and head1 != head2)
    {
        head1 = head1->next;
        head2 = head2->next;
    }

    // node found
    if (head1 != nullptr and head2 != nullptr and head1 == head2)
        return head1->data;
    return -1; // node not found
    /* TC-(n+m + (m-n) + n = o(n+m)) SC-O(1) */
}

/* method 4 (second optmized method) */
int intersectPoint(Node *head1, Node *head2)
{
    if (head1 == nullptr or head2 == nullptr)
        return -1;
    Node *first = head1, *second = head2;

    while (first != second)
    {
        first = first == nullptr ? head2 : first->next;
        second = second == nullptr ? head1 : second->next;
    }

    if (first == nullptr or second == nullptr)
        return -1;
    return first->data;
    /* TC-O(2m) SC-O(1) */
}