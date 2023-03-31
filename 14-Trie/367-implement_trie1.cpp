#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    bool flag = false;

    bool containKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd() { flag = true; }
    bool isEnd() { return flag; }
};

class Trie
{
private:
    Node *root;

public:
    // constructor
    Trie() { root = new Node(); }

    // insert
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containKey(word[i]))
                node->put(word[i], new Node());

            // move to the reference trie
            node->get(word[i]);
        }
        node->setEnd(); // turn into flag
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->containKey(prefix[i]))
                return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
};