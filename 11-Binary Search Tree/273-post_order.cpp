#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

Node *newNode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node *solve(int pre[], int &i, int bound, int size)
{
    if (i == size or pre[i] > bound)
        return nullptr;
    Node *root = newNode(pre[i++]);
    root->left = solve(pre, i, root->data, size);
    root->right = solve(pre, i, bound, size);
    return root;
}
Node *post_order(int pre[], int size)
{
    int i = 0;
    return solve(pre, i, INT_MAX, size - 1);
}