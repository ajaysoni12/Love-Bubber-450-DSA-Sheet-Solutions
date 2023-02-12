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
Node *mergeSort(Node *head)
{
    vector<int> ans;
    Node *temp = head;
    while (temp)
    {
        ans.push_back(temp->data);
        temp = temp->next;
    }
    sort(ans.begin(), ans.end());
    int j = 0;
    temp = head;
    while (temp)
    {
        temp->data = ans[j++];
        temp = temp->next;
    }
    return head;
    /* TC-O(n*log(n)) SC-O(2n) */
}

/* method 2 (using merge sort algo)*/

// return middle element address (floyd-cycle algo)
Node *getMiddle(Node *head)
{
    if (head == nullptr)
        return head;

    Node *slow = head;
    Node *fast = head->next;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow; // middle element
}
// merge two list
Node *mergeList(Node *first, Node *second)
{
    if (first == nullptr or second == nullptr)
        return first == nullptr ? second : first;

    // connect two list
    Node *ans = new Node(0);
    Node *curr = ans; // curr wil point last Node

    // merge two list till anyone not have nullptr
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
        curr = curr->next; // move curr
    }

    // if any one list is empty
    if (first != nullptr or second != nullptr)
        curr->next = (first != nullptr) ? first : second;

    return ans->next; // because list started from ans->next
}
// divided list till not have single node
Node *mergeSort(Node *head)
{
    // base case
    if (head == nullptr or head->next == nullptr)
        return head;

    // seprate two list
    Node *first = head;
    Node *mid = getMiddle(head);
    Node *second = mid->next;
    mid->next = nullptr;

    first = mergeSort(first);
    second = mergeSort(second);
    Node *result = mergeList(first, second);
    return result; // final ans

    /* TC-O(n*Log(n)) SC-O(n) */
}