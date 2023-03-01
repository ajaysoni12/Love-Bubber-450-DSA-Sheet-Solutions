#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

/* method 1 (using recursive way) */
bool ok = true;
int toSumTree(Node *root)
{
    if (root == NULL)
        return 0;

    int leftSum = toSumTree(root->left);
    int rightSum = toSumTree(root->right);

    if ((leftSum != 0 or rightSum != 0) and leftSum + rightSum != root->data)
        ok = false;

    return root->data + leftSum + rightSum;
    /* TC-O(n) SC-O(h) */
}
bool isSumTree(Node *root)
{
    toSumTree(root);
    return ok;
}
