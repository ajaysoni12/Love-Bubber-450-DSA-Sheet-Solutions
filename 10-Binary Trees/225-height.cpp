#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

/* metod 1 - (using recursive way) */
int height(struct Node *node)
{
    if (node == nullptr)
        return 0;
    int leftH = height(node->left);   // process left child
    int rightH = height(node->right); // process right child
    return max(leftH, rightH) + 1;    // then whateve maxHeight we have, we return maxH+1
    /* TC-O(n) SC-O(n) */
}

/* method 2 - (using queue) */
int height(struct Node *node)
{
    if (node == nullptr)
        return 0;

    int depth = 0;
    queue<Node *> q;

    // Pushing first level element along with NULL
    q.push(node);
    q.push(nullptr);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        // When NULL encountered, increment the value
        if (temp == nullptr)
            depth++;

        // If NULL not encountered, keep moving
        if (temp != nullptr)
        {
            if (temp->left)
                q.push(temp->left);
            else
                q.push(temp->right);
        }

        // If queue still have elements left,
        // push NULL again to the queue.
        else if (!q.empty())
            q.push(nullptr);
    }
    return depth;
    /* TC-O(n) SC-O(n) */
}