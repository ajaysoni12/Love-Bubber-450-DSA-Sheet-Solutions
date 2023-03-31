#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    bool flag = false;

    bool containKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    void setEnd() { flag = true; }
    bool isEnd() { return flag; }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containKey(word[i]))
                node->put(word[i], new Node());
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool checkPrefixExists(string &word)
    {
        bool flag = true;
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containKey(word[i]))
            {
                node = node->get(word[i]);
                if (node->isEnd() == false)
                    return false;
            }
            else
                return false;
        }
        return true;
    }
};

string completeString(int n, vector<string> &str)
{
    Trie trie;
    for (auto &it : str)
        trie.insert(it);

    string longest = "";

    for (auto it : str)
    {
        if (checkPrefixExists(it))
        {
            if (it.length() > longest.size())
                longest = it;
            else if (it.length() == longest.size() and it < longest)
                longest = it;
        }
    }

    if (longest == "")
        return "None";
    return longest;
}