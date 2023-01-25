#include <bits/stdc++.h>
using namespace std;

/* method 1 (generate all subarray) */
long long maxProduct(vector<int> arr, int n)
{
    long long ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        long long prod = 1;
        for (int j = i; j < n; j++)
        {
            prod = prod * arr[j];
            ans = prod > ans ? prod : ans;
        }
    }
    return ans;
    /*  Time Complexity: O(n^2)
        Auxiliary Space: O(1) */
}

/* method 2 (using both side traversing) */
long long maxProduct(vector<int> arr, int n)
{
    long long ans = INT_MIN;
    long long prod = 1;

    for (int i = 0; i < n; i++)
    {
        prod = prod * arr[i];
        ans = prod > ans ? prod : ans;
        prod = prod == 0 ? 1 : prod;
    }

    /* test case - -4, 3, 6, 8 */
    prod = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        prod = prod * arr[i];
        ans = prod > ans ? prod : ans;
        prod = prod == 0 ? 1 : prod;
    }
    return ans;

    /*  Time Complexity: O(2n)
        Auxiliary Space: O(1) */
}

/* method 3 (using calculation) */
long long maxProduct(vector<int> arr, int n)
{
    int maxAns = arr[0];
    int minAns = arr[0];
    int ans = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < 0) // -neg * pos --> lesser, -neg * -neg --> greater
            swap(maxAns, minAns);

        maxAns = max(arr[i], maxAns * arr[i]);
        minAns = min(arr[i], minAns * arr[i]);
        ans = max(ans, maxAns);
    }
    return ans;

    /*
        for(int i=0; i<n; i++)
        {
            if(arr[i] == 0) {
                max = 1;
                min = 1;
                continue;
            }

            int temp1 = arr[i] * max;
            int temp2 = arr[i] * min;

            max = max(temp1, temp2);
            max = max(max, arr[i]);
            min = min(temp1, temp2);
            min = min(min, arr[i]);
            ans = max(ans, max);
        }
        return ans;
    */

    /*  Time Complexity: O(n)
        Auxiliary Space: O(1) */
}
