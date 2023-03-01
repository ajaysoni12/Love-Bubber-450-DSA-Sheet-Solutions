#include <bits/stdc++.h>
using namespace std;

struct node
{
    int item;
    node *left, *right;
};

/* postorder traversal */
void postorderTraversal(node *root)
{
    if (root)
    {
        // left right root
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->item << " ";
    }
    /* TC-O(n) SC-O(h), h-height of tree */
}

void postorderTraversal(node *root)
{
    stack<node *> s;

    // Using unordered map as hash table for hashing to mark  the visited nodes
    unordered_map<node *, int> vis;

    // push the root node in the stack to traverse the tree
    s.push(root);

    // stack will be empty when traversal is completed
    while (!s.empty())
    {
        // mark the node on the top of stack as visited
        vis[s.top()] = 1;

        // if left child of the top node is not NULL and not
        // visited push it into the stack
        if (s.top()->left != 0)
        {
            if (!vis[s.top()->left])
            {
                s.push(s.top()->left);
                continue;
            }
        }

        // Otherwise if the right child of the top node is
        // not NULL and not visited push it into the stack
        if (s.top()->right != 0)
        {
            if (!vis[s.top()->right])
            {
                s.push(s.top()->right);
                continue;
            }
        }

        // Add the value of the top node in our postorder
        // traversal answer if none of the above two
        // conditions are met
        cout << s.top()->item << " ";

        // Remove the top node from the stack
        s.pop();
    }
    /* TC-O(n) SC-O(n) */
}