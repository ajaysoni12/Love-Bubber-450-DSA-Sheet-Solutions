#include <bits/stdc++.h>
using namespace std;

/* method 1 (using naive appraoch - using two loops)*/
vector<int> duplicates(int arr[], int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            if (arr[i] == arr[j])
                mp[arr[i]]++;
    }

    vector<int> ans;
    for (auto it : mp)
        ans.push_back(it.first);
    return ans;

    /*  Time Complexity: O(n^2)
        Auxiliary Space: O(2n) */
}

/* method 2 (if array can modified, using sorting)*/
vector<int> duplicates(int arr[], int n)
{
    vector<int> ans; // store duplicate element

    sort(arr, arr + n);

    for (int i = 0; i < n - 1; i++)
    {
        // first duplicate value inserting
        if (arr[i] == arr[i + 1])
            ans.push_back(arr[i++]);

        // and next all duplicate value skip
        while (arr[i] == arr[i + 1] && i < n)
            i++;
    }

    if (ans.size() == 0)
        return {-1};
    return ans;

    /*  Time Complexity: O(n * log(n))
        Auxiliary Space: O(n) */
}

/* method 3 (if array can't modified - counting frequncy)*/
vector<int> duplicates(int arr[], int n)
{
    unordered_map<int, int> mp; // store frequency
    vector<int> ans;            // store duplicate element

    // counting frequncy
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    // check element freq is greater then 1, if yes then store
    for (int i = 0; i < n; i++)
        if (mp[arr[i]] > 1)
            ans.push_back(i);

    // if no duplicate element
    if (ans.size() == 0)
        return {-1};
    return ans;

    /*  Time Complexity: O(2n)
        Auxiliary Space: O(2n) */
}

/* method 4 (mark (-ve), if all element in array less than n-1) */
int duplicates(vector<int> arr, int n)
{

    for (int i = 0; i < n; i++)
    {
        int index = abs(arr[i]); // find index

        if (arr[index] < 0) // if it's neg then previously same element reapted
            return index;

        arr[index] = -arr[index];
    }
    return -1;

    /*  Time Complexity: O(n)
        Auxiliary Space: O(n) */
}

/* using floyed-cycle alogrithm if array is read only */
