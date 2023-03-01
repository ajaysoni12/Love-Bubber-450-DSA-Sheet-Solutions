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

/* method 1 (using recursive way) */
int height(Node *root)
{
    if (root == nullptr)
        return 0;
    int leftH = height(root->left);
    int rightH = height(root->right);
    return max(leftH, rightH) + 1;
}
void findMax(Node *root, int &maxDia)
{
    if (root == nullptr)
        return;
    int leftH = height(root->left);
    int rightH = height(root->right);
    maxDia = max(maxDia, leftH + rightH);
    findMax(root->left, maxDia);
    findMax(root->right, maxDia);
}
int diameter(Node *root)
{
    int maxDia = 0;
    findMax(root, maxDia);
    return maxDia;
    /* TC-O(n^2) SC-O(n^2) */
}

/* method 2 (using linear complexity) */
int findMax(Node *root, int &maxDia)
{
    if (root == nullptr)
        return 0;

    // caculated height of the tree
    int lh = findMax(root->left, maxDia);
    int rh = findMax(root->right, maxDia);

    // update diameter also
    maxDia = max(maxDia, lh + rh);
    return 1 + max(lh, rh);
}
int diameter(Node *root)
{
    int maxDia = 0;
    findMax(root, maxDia);
    return maxDia;
    /* TC-O(n) SC-O(n) */
}