#include <bits/stdc++.h>
using namespace std;

class SortedStack
{
public:
    stack<int> s;
    void sort();
};

/* method 1 (brute force approach - apply insertion sort logic) */
void insertAtPlace(stack<int> &st, int curr)
{
    // if stack will be empty or top element will be lessthan or equal, so that is currect position of insertion curr element
    if (st.empty() or st.top() <= curr)
    {
        st.push(curr);
        return;
    }

    int top = st.top();
    st.pop();
    insertAtPlace(st, curr);
    st.push(top); // backtrack
}
void SortedStack ::sort()
{
    // start from 1th size array
    if (s.size() == 0 or s.size() == 1)
        return;
    int curr = s.top();
    s.pop();
    sort();
    insertAtPlace(s, curr);
    /* TC-O(n^2) SC-O(n) */
}

/* method 2(using priority queue) */
void SortedStack ::sort()
{
    priority_queue<int> pq; // maxHeap
    while (!s.empty())
    {
        pq.push(s.top());
        s.pop();
    }

    while (!pq.empty())
    {
        s.push(pq.top());
        pq.pop();
    }
    /* TC-O(n * log(n) + n) SC-O(n) */
}

int main()
{
    SortedStack obj;

    obj.s.push(3);
    obj.s.push(2);
    obj.s.push(1);
    // obj.s.push(7);
    obj.sort();

    while (!obj.s.empty())
    {
        cout << obj.s.top() << " ";
        obj.s.pop();
    }
    return 0;
}