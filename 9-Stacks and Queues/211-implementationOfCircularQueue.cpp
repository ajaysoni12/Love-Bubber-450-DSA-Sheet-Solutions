#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int rear, front;
    int size;
    int *arr;

public:
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        arr = new int[size];
    }

    void enqueue(int value)
    {
        if ((front == 0 and rear == size - 1) or rear == (front - 1) % (size - 1))
        {
            cout << "\nQueue is full..!";
            return;
        }
        else if (front == -1)
            front = rear = 0;
        else if (rear == size - 1 and front != 0)
            rear = 0;
        else
            rear++;
        arr[rear] = value;
    }
    int dequeue()
    {
        if (front == -1)
        {
            cout << "\nQueue is empty !";
            return -1;
        }

        int data = arr[front];
        arr[front] = -1;

        if (front == rear)
            front = rear = -1;
        else if (front == size - 1)
            front = 0;
        else
            front++;
        return data;
    }
    void printQ()
    {
        if (front == -1)
        {
            printf("\nQueue is Empty");
            return;
        }
        printf("\nElements in Circular Queue are: ");
        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
                printf("%d ", arr[i]);
        }
        else
        {
            for (int i = front; i < size; i++)
                printf("%d ", arr[i]);

            for (int i = 0; i <= rear; i++)
                printf("%d ", arr[i]);
        }
    }
};

int main()
{
    Queue q(5);

    // Inserting elements in Circular Queue
    q.enqueue(14);
    q.enqueue(22);
    q.enqueue(13);
    q.enqueue(-6);

    // Display elements present in Circular Queue
    q.printQ();

    // Deleting elements from Circular Queue
    printf("\nDeleted value = %d", q.dequeue());
    printf("\nDeleted value = %d", q.dequeue());

    q.printQ();

    q.enqueue(9);
    q.enqueue(20);
    q.enqueue(5);

    q.printQ();

    q.enqueue(20);
    return 0;
}