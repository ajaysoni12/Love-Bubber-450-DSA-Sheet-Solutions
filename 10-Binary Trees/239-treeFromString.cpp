#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int data) { this->data = data; }
};

int ind = 0;
Node *strToTree(string str)
{
    // ending
    if (ind >= str.size())
        return nullptr;

    // check node value is neg
    bool neg = false;
    if (str[ind] == '-')
    {
        neg = true;
        ind++;
    }

    // generate number
    int num = 0;
    while (ind < str.size() and str[ind] >= '0' and str[ind] <= '9')
    {
        int digit = str[ind] - '0';
        num = num * 10 + digit;
        ind++;
    }

    // do neg
    if (neg)
        num = -num;

    Node *root = new Node(num);

    // string length complete
    if (ind >= str.size())
        return root;

    // left subtreee
    if (ind < str.size() and str[ind] == '(')
    {
        ind++;
        root->left = strToTree(str);
    }
    if (ind < str.size() and str[ind] == ')')
    {
        ind++;
        return root;
    }

    // right subtree
    if (ind < str.size() and str[ind] == '(')
    {
        ind++;
        root->right = strToTree(str);
    }
    if (ind < str.size() and str[ind] == ')')
    {
        ind++;
        return root;
    }

    return root;
}

Node *treeFromString(string str)
{
    if (str.size() == 0)
        return nullptr;
    return strToTree(str);
    /* TC-O(n) SC-O(n) */
}