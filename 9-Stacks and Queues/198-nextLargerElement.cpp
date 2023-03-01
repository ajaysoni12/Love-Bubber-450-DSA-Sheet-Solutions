#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach - using two loops) */
vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    vector<long long> nge(n);
    for (int i = 0; i < n; i++)
    {
        int next = -1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                next = arr[j];
                break; // we need to only nearest greater element
            }
        }
        nge[i] = next; // put next greater element
    }
    return nge;
    /* TC-O(n^2) SC-O(1) */
}

/* method 2 (using stack) */
vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    vector<long long> nge(n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        // we go back till these given conditions are true
        while (!st.empty() and arr[i] > arr[st.top()])
        {
            nge[st.top()] = arr[i];
            st.pop();
        }

        // now push back curr element index
        st.push(i);
    }

    // fill -1 in stack elemenet, whose not have greater element
    while (!st.empty())
    {
        nge[st.top()] = -1;
        st.pop();
    }
    return nge;
    /* TC-O(n) SC-O(n) */
}