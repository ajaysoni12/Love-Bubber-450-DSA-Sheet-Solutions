#include <bits/stdc++.h>
using namespace std;

/* method 1 (naive appraoch) */
vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{
    vector<long long int> ans;
    for (int i = 0; i < n; i++)
    {
        long long int prod = 1;
        for (int j = 0; j < n; j++)
        {
            if (i != j) // same index not multiply
                prod *= nums[j];
        }
        ans.push_back(prod);
    }
    /* TC-O(n^2) SC-O(1) */
}

/* method 2 (using extra space) */
vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{
    // base case when single element so return 1
    if (n == 1)
        return {1};

    // store left prod and right prod
    vector<long long> leftProd(n), rightProd(n);

    // intial we store
    leftProd[0] = nums[0];
    rightProd[n - 1] = nums[n - 1];

    // calculated left prod
    for (int i = 1; i < n; i++)
        leftProd[i] = nums[i] * leftProd[i - 1];

    // caclulated right prod
    for (int i = n - 2; i >= 0; i--)
        rightProd[i] = nums[i] * rightProd[i + 1];

    vector<long long int> ans;
    for (int i = 0; i < n; i++)
    {
        // 1-n-1
        if (i > 0 and i < n - 1)
            ans.push_back(leftProd[i - 1] * rightProd[i + 1]);
        else if (i == 0)
            ans.push_back(rightProd[i + 1]);
        else
            ans.push_back(leftProd[i - 1]);
    }
    return ans;
    /* TC-O(n) SC-O(n) */
}

/* method 3 (space optimization)*/
vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{
    // Initialize a variable to store the total product of the array elements
    int prod = 1;
    for (int i = 0; i < n; i++)
        prod *= nums[i];

    // we know x/y mathematically is same
    // as x*(y to power -1)
    // assuming array not have 0
    vector<long long int> ans;
    for (int i = 0; i < n; i++)
        ans.push_back((int)(prod * pow(nums[i], -1)));
    return ans;
    /* TC-O(N) SC-O(1) */
}
vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{
    vector<long long int> v;

    long long int prod = 1;
    long long int prod1 = 1;

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
            prod *= nums[i];
        else if (nums[i] == 0)
        {
            prod1 *= 0;
            cnt++;
        }
    }

    int j = 0;
    if (cnt >= 2)
        for (int i = 0; i < n; i++)
            v.push_back(0);

    if (prod1 != 0)
    {
        while (j < n)
        {
            long long int temp = prod / nums[j];
            v.push_back(temp);
            j++;
        }
    }
    else if (prod1 == 0)
    {
        while (j < n)
        {
            if (nums[j] != 0)
                v.push_back(0);
            else
                v.push_back(prod);
            j++;
        }
    }

    return v;
    /* TC-O(n) SC-O(1) */
}