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

/* method 1 (using extra space) - you can use stack, vector or other ds */
Node *reverseList(Node *head)
{
    Node *prev = nullptr, *next = nullptr;
    while (head != nullptr)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
bool isPalindrome(Node *head)
{
    Node *firstList = head;
    Node *secondList = reverseList(head); // reverseList store

    while (firstList != nullptr and secondList != nullptr)
    {
        if (firstList->data != secondList->data)
            return false; // data not match, not palindrome
        firstList = firstList->next;
        secondList = secondList->next;
    }
    return true; // it is palindrome
    /* TC-O(n+n) SC-O(n) */
}

/* method 2 (using o(1) space)*/
bool isPalindrome(Node *head)
{
    // slow point middle node
    Node *slow = head, *fast = head;
    while (fast != nullptr and fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // reveselist - middleNode to lastNode
    Node *prev = nullptr, *next = nullptr;
    while (slow != nullptr)
    {
        next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }

    // compare
    Node *first = head, *second = slow;
    while (first != slow and second != nullptr)
    {
        if (first->data != second->data)
            return false;
        first = first->next;
        second = second->next;
    }
    return true; // palindrome
    /* TC-O(n/2 + n/2 + n/2 = 3n/2 = o(n)) SC-O(1) */
}