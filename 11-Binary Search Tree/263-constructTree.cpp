#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int val)
    {
        this->val = val;
        left = right = nullptr;
    }
};

/* method 1(create bst from given values )*/
/* method 2 (sort pre-order and convert into inorder, then construct bst using pre, and in order traversal)*/

/* method 3 (using efficent approach) */
Node *solve(int pre[], int &i, int bound, int size)
{
    if (i == size or pre[i] > bound)
        return nullptr;
    Node *root = new Node(pre[i++]);
    root->left = solve(pre, i, root->val, size);
    root->right = solve(pre, i, bound, size);
    return root;
}
Node *constructTree(int pre[], int size)
{
    int i = 0;
    return solve(pre, i, INT_MAX, size);
    /* TC-O(n) SC-O(h) */
}