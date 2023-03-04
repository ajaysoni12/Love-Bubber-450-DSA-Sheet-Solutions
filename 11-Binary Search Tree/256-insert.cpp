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

/* method 1 (using iterative way) */
Node *insert(Node *root, int Key)
{
    // prepare node
    Node *n = new Node(Key);
    if (root == nullptr)
        root = n;
    else
    {
        Node *ptr = root;
        // till we not get duplicate element or not get left null or right null, mention in if-eles condtions
        while (ptr->data != Key)
        {
            // go left side
            if (ptr->data > Key)
            {
                if (ptr->left)
                    ptr = ptr->left;
                else
                {
                    // here we need to insertion
                    ptr->left = n;
                    break;
                }
            }
            else
            {
                if (ptr->right)
                    ptr = ptr->right;
                else
                {
                    ptr->right = n;
                    break;
                }
            }
        }
        // duplicate value not allowed
        if (root->data == Key)
            delete n;
    }
    return root;
    /* TC-O(height of tree) SC-O(1) */
}

/* method 2 (recursive way) */
Node *insert(Node *root, int Key)
{
    if (root == nullptr)
        return new Node(Key);
    if (root->data > Key)
        root->left = insert(root->left, Key);
    if (root->data < Key)
        root->right = insert(root->right, Key);
    return root;
    /* TC-O(height of tree) SC-O(height of tree) */
}

/* searching */
Node *search(Node *root, int Key)
{
    if (root == nullptr or root->data == Key)
        return root;
    if (root->data > Key)
        return insert(root->left, Key);
    if (root->data < Key)
        return insert(root->right, Key);
    /* TC-O(height of tree) SC-O(height of tree) */
}
