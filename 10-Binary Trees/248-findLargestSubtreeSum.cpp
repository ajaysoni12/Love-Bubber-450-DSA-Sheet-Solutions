#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
};

/* method 1 (using leftSum tree and rightSum tree) */
int solve(Node *root, int &maxSum)
{
    if (root == nullptr)
        return 0;

    // left sum
    int leftSum = solve(root->left, maxSum);
    // right sum
    int rightSum = solve(root->right, maxSum);
    // update max
    maxSum = max(maxSum, (leftSum + rightSum + root->key));
    return leftSum + rightSum + root->key;
}
int findLargestSubtreeSum(Node *root)
{
    int maxSum = 0;
    solve(root, maxSum);
    return maxSum;
    /* TC-O(n) SC-O(h) */
}