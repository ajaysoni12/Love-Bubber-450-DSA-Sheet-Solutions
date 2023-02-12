#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* method 1 (data copy) */
struct node *moveToFront(struct node *head)
{
    if (head == nullptr or head->next == nullptr)
        return head;

    node *last = head;
    while (last->next != nullptr)
        last = last->next;

    int temp = head->data;
    head->data = last->data;
    last->data = temp;
    return head;
}

/* method 2 (using pointer manipulations) */
struct node *moveToFront(struct node *head)
{
    if (head == nullptr or head->next == nullptr)
        return head;

    node *last = head;
    while (last->next->next != nullptr)
        last = last->next;

    last->next->next = head;
    head = last->next;
    last->next = nullptr;
    return head;
}

void push(node **head_ref, int new_data)
{
    /* allocate node */
    node *new_node = new node(new_data);

    /* link the old list of the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

void printList(node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

int main()
{
    node *start = NULL;

    /* The constructed linked list is:
    1->2->3->4->5 */
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);

    cout << "Linked list before moving last to front\n";
    printList(start);

    // Function call
    start = moveToFront(start);

    cout << "\nLinked list after removing last to front\n";
    printList(start);

    return 0;
}
