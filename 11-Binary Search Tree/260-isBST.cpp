#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        left = right = nullptr;
        data = data;
    }
};

bool check(Node *root, int mini, int maxi)
{
    if (root == NULL)
        return true;
    bool left = check(root->left, mini, root->data);
    bool right = check(root->right, root->data, maxi);
    if (left && right && (root->data > mini && root->data < maxi))
        return true;
    return false;
}
bool isBST(Node *root)
{
    return check(root, INT_MIN, INT_MAX);
}