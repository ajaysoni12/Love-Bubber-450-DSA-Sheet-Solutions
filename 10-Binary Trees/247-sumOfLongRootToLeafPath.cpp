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
        left = NULL;
        right = NULL;
    }
};

pair<int, int> sol(Node *root)
{
    // root null
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    // left subtreee height and their sum
    pair<int, int> left = sol(root->left);

    // right subntree height and their sum
    pair<int, int> right = sol(root->right);

    // update height
    pair<int, int> ans;
    ans.first = max(left.first, right.first) + 1;

    // update sum
    if (left.first == right.first)
        ans.second = max(left.second, right.second) + root->data;
    else if (left.first > right.first)
        ans.second = left.second + root->data;
    else
        ans.second = right.second + root->data;
    return ans;
}
int sumOfLongRootToLeafPath(Node *root)
{
    return sol(root).second;
    /* TC-O(n) O(h) */
}

/* method 2 (using efficient approach) */
void sumOfLongRootToLeafPath(Node *root, int sum,
                             int len, int &maxLen, int &maxSum)
{
    // if true, then we have traversed a
    // root to leaf path
    if (!root)
    {
        // update maximum length and maximum sum
        // according to the given conditions
        if (maxLen < len)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if (maxLen == len && maxSum < sum)
            maxSum = sum;
        return;
    }

    // recur for left subtree
    sumOfLongRootToLeafPath(root->left, sum + root->data,
                            len + 1, maxLen, maxSum);

    // recur for right subtree
    sumOfLongRootToLeafPath(root->right, sum + root->data,
                            len + 1, maxLen, maxSum);
}

// utility function to find the sum of nodes on
// the longest path from root to leaf node
int sumOfLongRootToLeafPath(Node *root)
{
    // if tree is NULL, then sum is 0
    if (!root)
        return 0;

    int maxSum = INT_MIN, maxLen = 0;

    // finding the maximum sum 'maxSum' for the
    // maximum length root to leaf path
    sumOfLongRootToLeafPath(root, 0, 0, maxLen, maxSum);

    // required maximum sum
    return maxSum;

    /* TC-O(n) SC-O(h) */
}