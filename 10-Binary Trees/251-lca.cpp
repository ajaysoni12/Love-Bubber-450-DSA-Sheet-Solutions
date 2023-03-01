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

/* method 1 (using vector) */
bool findPath(Node *root, vector<int> &path, int k)
{
    // base case
    if (root == NULL)
        return false;

    // Store this node in path vector. The node will be
    // removed if not in path from root to k
    path.push_back(root->data);

    // See if the k is same as root's data
    if (root->data == k)
        return true;

    // Check if k is found in left or right sub-tree
    if ((root->left && findPath(root->left, path, k)) || (root->right && findPath(root->right, path, k)))
        return true;

    // If not present in subtree rooted with root, remove
    // root from path[] and return false
    path.pop_back();
    return false;
}

// Returns LCA if node n1, n2 are present in the given
// binary tree, otherwise return -1
int findLCA(Node *root, int n1, int n2)
{
    // to store paths to n1 and n2 from the root
    vector<int> path1, path2;

    // Find paths from root to n1 and root to n2. If either
    // n1 or n2 is not present, return -1
    if (!findPath(root, path1, n1) || !findPath(root, path2, n2))
        return -1;

    /* Compare the paths to get the first different value */
    int i;
    for (i = 0; i < path1.size() && i < path2.size(); i++)
        if (path1[i] != path2[i])
            break;
    return path1[i - 1];
    /* TC-O(n) SC-O(n) */
}

/* method 2 (using recursive way) */
Node *lca(Node *root, int n1, int n2)
{
    // if root found or root have null
    if (root == nullptr or root->data == n1 or root->data == n2)
        return root;

    Node *left = lca(root->left, n1, n2);
    Node *right = lca(root->right, n1, n2);

    // if left null, take right
    if (left == nullptr)
        return right;
    // if right null, take left
    else if (right == nullptr)
        return left;
    // othewise root is lca, return root
    else
        return root;
    /* TC-O(n) SC-O(h) */
}