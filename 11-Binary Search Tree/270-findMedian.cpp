#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

/* method 1 (using extra space) */
void inorder(Node *root, vector<float> &in)
{
    if (root == NULL)
        return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}
float findMedian(struct Node *root)
{
    vector<float> ans;
    inorder(root, ans);
    int s = 0;
    int e = ans.size() - 1;
    int size = ans.size();
    int mid = (s + e) / 2;
    if (size % 2 != 0)
        return ans[mid];
    else
        return (ans[mid + 1] + ans[mid]) / 2.0;
    /* TC-O(n) SC-O(n) */
}

/* method 2 (using recursive way) */
void inorderBST(struct Node *root, int &count)
{
    if (root)
    {
        inorderBST(root->left, count);
        count++;
        inorderBST(root->right, count);
    }
}
float solveRec(struct Node *root, int &k, int count)
{
    if (root)
    {
        solveRec(root->left, k, count);
        k++;
        if (k == count)
            return root->data;
        solveRec(root->right, k, count);
    }
}
float findMedian(struct Node *root)
{
    // step 1 : count number of nodes
    int count = 0;
    inorderBST(root, count);
    // step 2 : check if count is even or odd
    int k = 0;
    if (count & 1) // count is odd
        return solveRec(root, k, (count + 1) / 2);
    // even
    else
    {
        float a = solveRec(root, k, count / 2);
        k = 0;
        float b = solveRec(root, k, (count / 2) + 1);
        return (a + b) / 2;
    }
    /* TC-O(n) SC-O(h) */
}