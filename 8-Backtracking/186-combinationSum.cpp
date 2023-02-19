#include <bits/stdc++.h>
using namespace std;

void findNumbers(vector<int> &arr, int sum, vector<vector<int>> &res, vector<int> &r, int i)
{
    // if we get exact answer
    if (sum == 0)
    {
        res.push_back(r);
        return;
    }

    // Recur for all remaining elements that have value smaller than sum.
    while (i < arr.size() && sum - arr[i] >= 0)
    {
        // Till every element in the arrray starrting
        // from i which can contribute to the sum
        r.push_back(arr[i]); // add them to list

        // recursive call for next numbers
        findNumbers(arr, sum - arr[i], res, r, i);
        i++;

        // Remove number from list (backtracking)
        r.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int> &arr, int sum)
{
    // sort input arrray
    sort(arr.begin(), arr.end());

    // remove duplicates
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    vector<int> r;
    vector<vector<int>> res;
    findNumbers(arr, sum, res, r, 0);
    return res;
    /* Time Complexity: O(k*(2^n)) where n is the size of array, and k is average length
    Auxiliary Space: O(k*x) where is x is number of possible combinations */
}