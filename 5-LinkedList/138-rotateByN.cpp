#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

/* method 1 (brute force appraoch) */
void rotateByN(Node *&head, int pos)
{
    if (head == nullptr or pos == 0 or head->next == nullptr)
        return;

    // point last node
    Node *last = head;
    int len = 1;
    while (last->next != nullptr)
    {
        last = last->next;
        len++;
    }

    // because 1 time rotate and 6 time rotate are similar
    pos = pos % len;

    // bind all the nodes
    last->next = head;
    head->prev = last;

    // pos time rotate
    while (pos--)
    {
        // this is head, and last node positions
        head = head->next;
        last = last->next;
    }

    // in last, head->prev is null and last->next is also null
    head->prev = nullptr;
    last->next = nullptr;
    /* TC-O(n) SC-O(1) */
}

void insertAtHead(Node *&head, int data)
{
    Node *n = new Node(data);
    if (head == NULL)
    {
        head = n;
        return;
    }
    n->next = head;
    head->prev = n;
    head = n;
    return;
}
void insertAtTail(Node *&head, int data)
{
    if (head == NULL)
    {
        insertAtHead(head, data);
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *n = new Node(data);
    temp->next = n;
    n->prev = temp;
    return;
}
void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node *head = NULL;
    insertAtTail(head, 'a');
    insertAtTail(head, 'b');
    insertAtTail(head, 'c');
    insertAtTail(head, 'd');
    insertAtTail(head, 'e');

    int n = 4;
    cout << "Given linked list \n";
    display(head);
    rotateByN(head, n);
    cout << "\nRotated Linked list \n";
    display(head);
    cout << "\n\n";

    return 0;
}