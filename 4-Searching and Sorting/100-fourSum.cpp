#include <bits/stdc++.h>
using namespace std;

/* method 1 (using four loops)*/
void findFourElements(int A[], int n, int X)
{
    set<vector<int>> set;
    // Fix the first element and find other three
    for (int i = 0; i < n - 3; i++)
    {
        // Fix the second element and find other two
        for (int j = i + 1; j < n - 2; j++)
        {
            // Fix the third element and find the fourth
            for (int k = j + 1; k < n - 1; k++)
            {
                // find the fourth
                for (int l = k + 1; l < n; l++)
                    if (A[i] + A[j] + A[k] + A[l] == X)
                        set.insert(A[i], A[j], A[k], A[l]);
            }
        }
    }
    vector<vector<int>> ans;
    for (auto it : set)
        ans.push_back(it);
    return ans;
    /* TC-O((n*n*n*n) = n^4) SC-O(n^2) */
}

/* method 2 (using three loops and two pointer technique + set)*/
vector<vector<int>> fourSum(vector<int> &arr, int k)
{
    int n = arr.size(); // vector size

    sort(arr.begin(), arr.end()); // sort vector because we apply two pointer technique

    set<vector<int>> st; // remove duplicate pairs

    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            int low = j + 1, high = n - 1;
            while (low < high)
            {
                int sum = arr[i] + arr[j] + arr[low] + arr[high];
                if (sum == k) // if sum equal, inserted
                    st.insert({arr[i], arr[j], arr[low], arr[high]});
                if (k > sum)
                    low++;
                else
                    high--;
            }
        }
    }

    vector<vector<int>> ans; // return in the form of vector
    for (auto it : st)
        ans.push_back(it);

    return ans;
    /* TC-O(n*log(n) + (n*n*n) + O(n)) = O(n^3) SC-O(n + (n*n)) = O(n^2)*/
}