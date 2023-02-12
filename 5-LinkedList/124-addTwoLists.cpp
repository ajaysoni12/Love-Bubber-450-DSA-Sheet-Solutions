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

/* method 1 (using brute force appraoch - but its fail to some bigger task)*/
struct Node *addTwoLists(struct Node *first, struct Node *second)
{
    long long num1, num2;
    num1 = num2 = 0;

    Node *temp = first;

    // generate first num1
    while (temp != nullptr)
    {
        num1 = num1 * 10 + temp->data;
        temp = temp->next;
    }

    temp = second;
    // generate first num2
    while (temp != nullptr)
    {
        num2 = num2 * 10 + temp->data;
        temp = temp->next;
    }

    long long res = num1 + num2; // res
    long long rem;               // remaning
    temp = nullptr;

    // till res != 0
    while (res != 0)
    {
        rem = res % 10;
        Node *n = new Node(rem);
        n->next = temp;
        temp = n;
        res = res / 10;
    }
    return temp;
    /* TC-O(n+m) SC-O(1) */
}

/* method 2 (using reverse + additions + carry) */
struct Node *reverseList(struct Node *head)
{
    if (head == nullptr or head->next == nullptr)
        return head;

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
struct Node *addTwoLists(struct Node *first, struct Node *second)
{
    first = reverseList(first);   // reverse first list
    second = reverseList(second); // reverse second list

    struct Node *res = nullptr; // store resultant list

    int carry = 0;

    while (first != nullptr and second != nullptr)
    {
        int sum = first->data + second->data + carry;
        Node *n = new Node(sum % 10);
        n->next = res;
        res = n;
        carry = sum / 10;
        first = first->next;
        second = second->next;
    }

    // if one of them list is empty
    Node *t = first == nullptr ? second : first;

    while (t != nullptr)
    {
        int sum = t->data + carry;
        Node *n = new Node(sum % 10);
        n->next = res;
        res = n;
        carry = sum / 10;
        t = t->next;
    }
    // if sum carry is available
    if (carry > 0)
    {
        Node *n = new Node(carry);
        n->next = res;
        res = n;
    }
    return res;
    /* TC-(n+m) SC-O(max(n+m)) */
}
