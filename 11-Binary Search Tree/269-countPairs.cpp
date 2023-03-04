#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

/* method 1 (using brute force approach) */
int counter = 0;
void inorder(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}
int countPairsInSortedVectors(vector<int> &a, vector<int> &b, int x)
{
    int i = 0;
    int j = b.size() - 1;

    // find pair
    while (i < a.size() && j >= 0)
    {
        int sum = a[i] + b[j];
        if (sum < x)
            i++;
        else if (sum > x)
            j--;
        else
        {
            counter++;
            i++;
            j--;
        }
    }
    return counter;
}
int countPairs(Node *root1, Node *root2, int x)
{
    vector<int> v1, v2;
    inorder(root1, v1);
    inorder(root2, v2);
    countPairsInSortedVectors(v1, v2, x);
    return counter;
    /* TC-O(n+n) SC-O(n) */
}

/* method 2 (using freq) */
void inorder(Node *root, unordered_map<int, int> &mp)
{
    if (root)
    {
        inorder(root->left, mp);
        mp[root->data]++;
        inorder(root->right, mp);
    }
}
void count(Node *root, unordered_map<int, int> &mp, int &cnt, int x)
{
    if (root)
    {
        count(root->left, mp, cnt, x);
        if (mp.find(x - root->data) != mp.end())
            cnt++;
        count(root->right, mp, cnt, x);
    }
}

int countPairs(Node *root1, Node *root2, int x)
{
    // declare map for first root element
    unordered_map<int, int> mp;
    inorder(root1, mp); // freq of first bst
    int cnt = 0;
    count(root2, mp, cnt, x); // x-root->data is present increment cnt
    return cnt;
    /* TC-O(n+n) SC-O(n) */
}
