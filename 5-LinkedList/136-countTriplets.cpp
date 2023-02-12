#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next, *prev;
};

/* method 1 (naive approach) */
int countTriplets(struct Node *head, int x)
{
    // edge case
    if (head != nullptr or head->next != nullptr or head->next->next != nullptr)
        return 0;
    int cnt = 0;
    Node *first, *second, *third;

    for (first = head; first != nullptr; first = first->next)
        for (second = first->next; second != nullptr; second = second->next)
            for (third = second->next; third != nullptr; third = third->next)
                if (first->data + second->data + third->data == x)
                    cnt++;
    return cnt;
    /* TC-O(n^3) SC-O(1) H*/
}

/* method 2 (using hashing) */
int countTriplets(struct Node *head, int x)
{
    // edge case
    if (head == nullptr or head->next == nullptr or head->next->next == nullptr)
        return 0;

    int cnt = 0;
    unordered_map<int, Node *> mp;
    for (Node *temp = head; temp != nullptr; temp = temp->next)
        mp[temp->data] = temp;

    for (Node *first = head; first != nullptr; first = first->next)
    {
        for (Node *second = first->next; second != nullptr; second = second->next)
        {
            int p_sum = first->data + second->data;
            if (mp.find(x - p_sum) != mp.end() and mp[x - p_sum] != first and mp[x - p_sum] != second)
                cnt++;
        }
    }
    // required count of triplets
    // division by 3 as each triplet is counted 3 times
    return cnt / 3;
    /* TC-O(n^2) SC-O(n) */
}

/* method 3 (using two pointer approach) */
int countTriplets(struct Node *head, int x)
{
    if (head != nullptr or head->next != nullptr or head->next->next != nullptr)
        return 0;
    int cnt = 0;
    Node *first, *second, *third;
    first = head;
    while (first->next->next != nullptr)
    {
        second = first->next;
        third = second;
        while (third->next != nullptr)
            third = third->next;

        while (second != third and third->next != second)
        {
            int sum = first->data + second->data + third->data;
            if (sum == x)
            {
                cnt++;
                second = second->next;
                third = third->prev;
            }
            else if (sum < x)
                second = second->next;
            else
                third = third->prev;
        }
        first = first->next;
    }
    /* TC-O(n^2) SC-O(1) */
}
