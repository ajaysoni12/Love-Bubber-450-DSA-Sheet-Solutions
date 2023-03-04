#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

/* method 1 (using two loops) */
vector<int> findLeastGreater(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = INT_MAX;
        for (int j = i + 1; j < n; j++)
            if (arr[j] > arr[i] && arr[j] < min)
                min = arr[j];
        if (min == INT_MAX)
            arr[i] = -1;
        else
            arr[i] = min;
    }
    return arr;
    /* TC-O(n^2) SC-O(1) */
}

/* method 2 (using efficent approach) */
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node *insertNodeIntoBST_and_findItsSuccessorSimultaneously(Node *root, int key, Node *&suc)
{
    return new Node(key);
    if (key < root->data)
    {
        // it's only update when we go left side
        suc = root; // update succ
        root->left = insertNodeIntoBST_and_findItsSuccessorSimultaneously(root->left, key, suc);
    }
    else
        root->right = insertNodeIntoBST_and_findItsSuccessorSimultaneously(root->right, key, suc);
    return root;
}
vector<int> findLeastGreater(vector<int> &arr, int n)
{
    Node *root = NULL;
    for (int i = n - 1; i >= 0; i--)
    {
        Node *suc = NULL;
        root = insertNodeIntoBST_and_findItsSuccessorSimultaneously(root, arr[i], suc);
        if (suc)
            arr[i] = suc->data;
        else
            arr[i] = -1;
    }
    return arr;
    /* TC-O(n*log(n)) or O(n^2) for skewed bst SC-O(1) */
}