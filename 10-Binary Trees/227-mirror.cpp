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

/* method 1 (recursive way) */
void mirror(Node *node)
{
    if (node)
    {
        // swap node address
        Node *t = node->left;
        node->left = node->right;
        node->right = t;

        // process left child
        if (node->left)
            mirror(node->left);

        // process right child
        if (node->right)
            mirror(node->right);
    }
    /* TC-O(n) SC-O(h) */
}