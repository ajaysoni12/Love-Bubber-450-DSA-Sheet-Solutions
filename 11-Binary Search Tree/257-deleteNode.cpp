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

Node *deleteNode(Node *root, int val)
{
    if (root == nullptr)
        return nullptr;
    if (root->data > val)
        root->left = deleteNode(root->left, val);
    else if (root->data < val)
        root->right = deleteNode(root->right, val);
    else
    {
        // no child
        if (!root->left and !root->right)
        {
            delete root;
            return nullptr;
        }
        // single child
        if (!root->left or !root->right)
        {
            Node *child = root->left ? root->left : root->right;
            delete root;
            return child;
        }
        // two child
        Node *pred = root->left;

        // right successor
        while (pred and pred->right)
            pred = pred->right;

        // copy data
        root->data = pred->data;

        // delete pred data
        root->left = deleteNode(pred, pred->data);
    }
    return root;
    /* TC-O(log2(n)) SC-O(log2(n)) - height of tree */
}
