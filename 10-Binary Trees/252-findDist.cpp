#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

/* method 1 (using brute force approach) */
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

int findDist(Node *root, int a, int b)
{
    vector<int> path1, path2;
    findPath(root, path1, a);
    findPath(root, path2, b);
    int cnt = path1.size() + path2.size();
    for (int i = 0; i < path1.size() and i < path2.size(); i++)
    {
        if (path1[i] == path2[i])
            cnt -= 2;
        return cnt;
    }
    /* TC-O(n) SC-O(n) */
}