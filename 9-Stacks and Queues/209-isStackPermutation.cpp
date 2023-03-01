#include <bits/stdc++.h>
using namespace std;

int isStackPermutation(int n, vector<int> &a, vector<int> &b)
{
    stack<int> st;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        // push element
        st.push(a[i]);

        // check if jth index element is equal to top, if yes then pop up
        while (!st.empty() and b[j] == st.top())
        {
            st.pop();
            j++;
        }
    }

    // permutation possible 
    if (st.size() == 0)
        return true;
    return false;  // permutation not possible 
}
