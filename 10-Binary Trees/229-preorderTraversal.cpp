#include <bits/stdc++.h>
using namespace std;

struct node
{
    int item;
    node *left, *right;
};

/* preorder traversal - recursive way */
void preorderTraversal(node *root)
{
    if (root)
    {
        // root left right
        cout << root->item << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
    /* TC-O(n) SC-O(h), h-height of tree */
}

/* preorder traversal - iterative way */
void preorderTraversal(node *root)
{
    if (root == nullptr)
        return;
    stack<node *> st;
    st.push(root);

    while (!st.empty())
    {
        // Pop the top item from stack and print it
        node *node = st.top();
        cout << node->item << " ";
        st.pop();

        // Push right and left children of the popped node to stack
        if (node->right)
            st.push(node->right);
        if (node->left)
            st.push(node->left);
    }
    /* TC-O(n) SC-O(h) */
}