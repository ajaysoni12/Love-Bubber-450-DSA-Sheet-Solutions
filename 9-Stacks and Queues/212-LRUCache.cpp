#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int key, value;
    node *prev, *next;

    node(int key, int value)
    {
        this->key = key;
        this->value = value;
    }
};

class LRUCache
{
private:
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);

public:
    void addNode(int key, int value)
    {
        node *ptr = new node(key, value);
        ptr->next = head->next;
        head->next->prev = ptr;
        head->next = ptr;
        ptr->prev = head;
    }
    void delNode(node *ptr)
    {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        delete ptr;
    }

    int size;
    unordered_map<int, node *> mp;
    LRUCache(int cap)
    {
        size = cap;
        head->prev = nullptr;
        head->next = tail;
        tail->prev = head;
        tail->next = nullptr;
    }

    int GET(int key)
    {
        if (mp.find(key) != mp.end())
        {
            // addNode
            addNode(key, mp[key]->value);
            delNode(mp[key]);
            mp[key] = head->next;
            return head->next->value;
        }
        return -1;
    }

    void SET(int key, int value)
    {
        if (mp.size() == size)
        {
            if (mp.find(key) != mp.end())
            {
                mp[key]->value = value;
                delNode(mp[key]);
                addNode(key, value);
                mp[key] = head->next;
            }
            else 
            {
                
            }
        }
        else
        {
        }
    }
};