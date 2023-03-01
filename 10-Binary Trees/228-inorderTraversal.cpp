#include <bits/stdc++.h>
using namespace std;

struct node
{
    int item;
    node *left, *right;
};

/* inroder traversal - recursive way */
void inorderTraversal(node *root)
{
    if (root)
    {
        // left root right
        inorderTraversal(root->left);
        cout << root->item << " ";
        inorderTraversal(root->right);
    }
    /* TC-O(n) SC-O(h), h-height of tree */
}

/* inorder traversal - itarative way */
void inorderTraversal(node *root)
{
    stack<node *> s;
    node *curr = root;

    while (curr != NULL || s.empty() == false)
    {
        /* Reach the left most Node of the curr Node */
        while (curr != NULL)
        {
            /* place pointer to a tree node on the stack before traversing
              the node's left subtree */
            s.push(curr);
            curr = curr->left;
        }

        /* Current must be NULL at this point */
        curr = s.top();
        s.pop();
        cout << curr->item << " ";
        /* we have visited the node and its left subtree.  Now, it's right
           subtree's turn */
        curr = curr->right;
    }
    /* TC-O(n) SC-O(n) */
}