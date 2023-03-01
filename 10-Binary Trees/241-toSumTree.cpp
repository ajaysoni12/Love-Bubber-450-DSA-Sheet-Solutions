#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

/* method 1 (using recursive way) */
int toSumTree(Node *root)
{
    // Base case
    if (root == NULL)
        return 0;

    // Store the old value
    int old_val = root->data;

    // Recursively call for left and
    // right subtrees and store the sum as
    // old value of this node
    root->data = toSumTree(root->left) + toSumTree(root->right);

    // Return the sum of values of nodes
    // in left and right subtrees and
    // old_value of this node
    return root->data + old_val;
    /* TC-O(n) SC-O(h) */
}