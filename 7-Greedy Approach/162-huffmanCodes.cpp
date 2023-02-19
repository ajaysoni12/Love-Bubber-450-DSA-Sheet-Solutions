#include <bits/stdc++.h>
using namespace std;

// node structure
struct node
{
    int data;
    node *left, *right;

    node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

// compartor made minHeap
class cmp
{
public:
    bool operator()(node *left, node *right)
    {
        return left->data > right->data;
    }
};

// preOrder traversal
void preOrder(node *root, string str, vector<string> &res)
{
    if (root->left == nullptr and root->left == nullptr)
    {
        res.push_back(str);
        return;
    }
    preOrder(root->left, str + '0', res);
    preOrder(root->right, str + '1', res);
}

vector<string> huffmanCodes(string str, vector<int> freq, int n)
{
    // make mminHeap
    priority_queue<node *, vector<node *>, cmp> pq;

    // push all freq nodes
    for (int i = 0; i < n; i++)
    {
        node *n = new node(freq[i]);
        pq.push(n);
    }

    // till minHeap have greater then 1 node
    while (pq.size() > 1)
    {
        // take two minimum freq oodes
        node *left = pq.top();
        pq.pop();
        node *right = pq.top();
        pq.pop();

        // and create parent nodes have some of min nodes data
        node *parentNode = new node(left->data + right->data);
        parentNode->left = left;
        parentNode->right = right;
        pq.push(parentNode); // and push
    }

    // now just need to traverse
    node *root = pq.top();
    vector<string> res;
    string temp;
    preOrder(root, temp, res);
    return res;
    /* TC-O(n*log(n)) SC-O(n) */
}