#include <bits/stdc++.h>
using namespace std;

/* method 1 (using two loop) */
string isSubset(int a1[], int a2[], int n, int m)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a2[i] == a1[j])
                break;
        }
        if (j == n)
            return "No";
    }
    return "Yes";

    /*  Time Complexity: O(n^2)
        Auxiliary Space: O(1) */
}

/* method 2 (using sorting and merging)*/
string isSubset(int a1[], int a2[], int m, int n)
{
    int i = 0, j = 0;
    if (m < n)
        return "No";

    // Sort both the arrays
    sort(a1, a1 + m);
    sort(a2, a2 + n);

    while (i < n && j < m)
    {
        // If the element is smaller then Move ahead in the first array
        if (a1[j] < a2[i])
            j++;

        // If both are equal, then move both of them forward
        else if (a1[j] == a2[i])
        {
            j++;
            i++;
        }

        // If we do not have an element smaller or equal to the second array then break
        else if (a1[j] > a2[i])
            return "No";
    }
    return i < n ? "No" : "Yes";
}

/* method 3 (using set) */
string isSubset(int arr1[], int arr2[], int n, int m)
{
    // Using STL set for hashing
    set<int> hashset;

    // hashset stores all the values of arr1
    for (int i = 0; i < n; i++)
        hashset.insert(arr1[i]);

    // loop to check if all elements of arr2 also lies in arr1
    for (int i = 0; i < m; i++)
    {
        if (hashset.find(arr2[i]) == hashset.end())
            return false;
    }
    return true;
    /*  Time Complexity: O(n + m * logM)
        Auxiliary Space: O(n) */
}

/* method 4 (using unroder_set) */
string isSubset(int arr1[], int arr2[], int n, int m)
{
    // Using STL Unorderd_set for hashing
    set<int> hashset;

    // hashset stores all the values of arr1
    for (int i = 0; i < n; i++)
        hashset.insert(arr1[i]);

    int size = hashset.size();

    // loop to check if all elements of arr2 also lies in arr1
    for (int i = 0; i < m; i++)
        hashset.insert(a2[i]);

    if (size == hashset.size())
        return true;

    return false;
    /*  Time Complexity: O(n + m)
        Auxiliary Space: O(n) */
}
