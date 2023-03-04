#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

/* method 1 (itarative way) */
int minValue(Node *root)
{
    if (root == nullptr)
        return -1;
    while (root->left)
        root = root->left;
    return root->data;
    /* TC-O(height of tree) SC-O(1) */
}

/* method 2 (using recursive way) */
int minValue(Node *root)
{
    if (root == nullptr)
        return -1;
    if (root->left)
        return root->data;
    return minValue(root->left);
    /* TC-O(height of tree) SC-O(height of treee) */
}
