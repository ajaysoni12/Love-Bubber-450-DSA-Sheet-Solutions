#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left, *right;
    Node(int data)
    {
        left = right = nullptr;
        key = data;
    }
};

/* method 1 (using vector - brute force approach) */
void inorderTraversal(Node *root, vector<int> &path)
{
    if (root)
    {
        inorderTraversal(root->left, path);
        path.push_back(root->key);
        inorderTraversal(root->right, path);
    }
}
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    vector<int> path;
    inorderTraversal(root, path);
    if (path.size() == 0)
        pre = suc = nullptr;

    int ind = 0;
    while (1)
    {
        // if value not found
        if (ind >= path.size())
        {
            pre = new Node(path[path.size() - 1]);
            suc = new Node(-1);
            return;
        }

        // if curr value is greater then key, then
        if (path[ind] > key)
        {
            if (ind - 1 >= 0)
                pre = new Node(path[ind - 1]);
            else
                pre = new Node(-1);
            suc = new Node(path[ind]);
            return;
        }

        // if key match
        if (path[ind] == key)
        {
            if (ind - 1 >= 0)
                pre = new Node(path[ind - 1]);
            else
                pre = new Node(-1);

            if (ind + 1 < path.size())
                suc = new Node(path[ind + 1]);
            else
                suc = new Node(-1);
            return;
        }
        ind++;
    }
    /* TC-O(n) SC-O(n) */
}

/* method 2 (uisng efficient approach)*/
Node *inPre(Node *root)
{
    Node *curr = root->left;
    while (curr->right)
        curr = curr->right;
    return curr;
}
Node *inSuc(Node *root)
{
    Node *curr = root->right;
    while (curr->left)
        curr = curr->left;
    return curr;
}
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    if (!root)
        return;
    if (root->key == key)
    {
        if (root->left)
            pre = inPre(root);
        if (root->right)
            suc = inSuc(root);
        return;
    }
    if (key > root->key)
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
    else if (key < root->key)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    /* TC-O(h) SC-O(h) */
}