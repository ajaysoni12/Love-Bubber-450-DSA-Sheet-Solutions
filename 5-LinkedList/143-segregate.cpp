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

/* method 1 (using extra space) */
Node *segregate(Node *head)
{
    struct Node *temp = head;
    vector<int> arr;
    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    sort(arr.begin(), arr.end());

    temp = head;
    int i = 0;
    while (temp != NULL)
    {
        temp->data = arr[i];
        temp = temp->next;
        i++;
    }
    return head;
    /* TC-O(2n) SC-O(n) */
}

/* method 2 (using optimized approach) */
Node *segregate(Node *head)
{
    // edge case
    if (head == nullptr or head->next == nullptr)
        return head;

    // count how many times 0, 1, 2 present
    int cnt_0 = 0, cnt_1 = 0, cnt_2 = 0;
    Node *loop;
    for (loop = head; loop != nullptr; loop = loop->next)
    {
        if (loop->data == 0)
            cnt_0++;
        else if (loop->data == 1)
            cnt_1++;
        else
            cnt_2++;
    }

    // now put 0,1,2 symultaneously
    loop = head;
    int cnt = 0;
    while (cnt < cnt_0)
    {
        loop->data = 0;
        loop = loop->next;
        cnt++;
    }
    while (cnt < cnt_1 + cnt_0)
    {
        loop->data = 1;
        loop = loop->next;
        cnt++;
    }
    while (cnt < cnt_0 + cnt_1 + cnt_2)
    {
        loop->data = 2;
        loop = loop->next;
        cnt++;
    }
    return head; // return heat pointer
    /* TC-O(n+n = 2n) SC-O(1) */
}