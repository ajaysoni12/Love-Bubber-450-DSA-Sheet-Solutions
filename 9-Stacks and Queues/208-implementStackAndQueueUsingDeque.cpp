#include <bits/stdc++.h>
using namespace std;

struct node
{
    int item;
    node *prev;
    node *next;
};

class Deque
{
private:
    node *head, *tail;

public:
    Deque() { head = tail = nullptr; }
    bool isEmpty() { return head == nullptr; }
    int size()
    {
        if (!isEmpty())
        {
            node *temp = head;
            int len = 0;
            while (temp != nullptr)
            {
                len++;
                temp = temp->next;
            }
            return len;
        }
        return 0;
    }
    void insertFirst(int item)
    {
        node *n = new node();
        n->item = item;
        if (head == nullptr)
        {
            n->prev = n->next = nullptr;
            head = tail = n;
        }
        else
        {
            head->prev = n;
            n->next = head;
            n->prev = nullptr;
            head = n;
        }
    }
    void insertLast(int item)
    {
        node *n = new node();
        n->item = item;
        if (head == nullptr)
        {
            n->prev = n->next = nullptr;
            head = tail = n;
        }
        else
        {
            n->prev = tail;
            n->next = nullptr;
            tail->next = n;
            tail = n;
        }
    }
    void removeFirst()
    {
        if (head)
        {
            node *temp = head;
            head = head->next;
            if (head)
                head->prev = nullptr;
            delete temp;
            if (temp == nullptr)
                tail = nullptr;
            return;
        }
        cout << "\nList is empty!";
    }
    void removeLast()
    {
        if (head)
        {
            node *temp = tail;
            tail = tail->prev;
            if (tail)
                tail->next = nullptr;
            delete temp;
            if (tail == nullptr)
                head = nullptr;
            return;
        }
        cout << "\nList is empty!";
    }
    void display()
    {
        if (head)
        {
            cout << "\nList is: ";
            node *n = head;
            while (n != nullptr)
            {
                cout << n->item << " ";
                n = n->next;
            }
            cout << endl;
            return;
        }
        cout << "\nList is empty!";
    }
};

class Stack : public Deque
{
public:
    void push(int x) { insertLast(x); }
    void pop() { removeLast(); }
    /* TC-O(n) SC-O(n) */
};

class Queue : public Deque
{
public:
    void enqueue(int x) { insertLast(x); }
    void dequeue() { removeFirst(); }
    /* TC-O(n) SC-O(n) */
};

int main()
{
    Stack st;
    st.push(1);
    st.push(4);
    st.push(2);
    st.display();

    Queue q;
    q.enqueue(5);
    q.enqueue(3);
    q.enqueue(2);
    q.display();
    return 0;
}