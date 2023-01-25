// C++ program of above implementation
#include <bits/stdc++.h>
using namespace std;

/* Using Sorting */
pair<int, int> getMinMax(int arr[], int n)
{
    if (n == 0)
        return {NULL, NULL};
    if (n == 1)
        return {arr[0], arr[0]};

    sort(arr, arr + n);
    return {arr[0], arr[n - 1]};

    /* Time Complexity: O(n*Log(n)) Auxiliary Space: O(1) */
}

/* Iterative Way */
pair<int, int> getMinMax(int arr[], int n)
{
    int min, max;
    
    // If there is only one element then return it as min and max both
    if (n == 1)
    {
        min = max = arr[0];
        return {min, max};
    }

    for (int i = 2; i < n; i++)
    {
        max = max < arr[i] ? arr[i] : max;
        min = min > arr[i] ? arr[i] : min;
    }
    return {min, max};

    /* Time Complexity: O(n) Auxiliary Space: O(1) */
}

/* Recursive Way - Divide and Conquer */
pair<int, int> getMinMax(int arr[], int low, int high)
{
    pair<int, int> minmax, mml, mmr;

    if (low == high)
        return minmax = {arr[low], arr[high]};
    if (low + 1 == high)
        return minmax = {min(arr[low], arr[high]), max(arr[low], arr[high])};

    int mid = (low + high) / 2;
    mml = getMinMax(arr, low, mid);
    mmr = getMinMax(arr, mid + 1, high);

    minmax.first = mml.first < mmr.first ? mml.first : mmr.first;
    minmax.second = mml.second > mmr.second ? mml.second : mml.second;
    return minmax;

    /* Time Complexity: O(n) Auxiliary Space: O(Log(n)) as the stack space will be filled for the maximum height of the tree formed during recursive calls same as a binary tree */
}

// Driver code
int main()
{
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int arr_size = 6;

    pair<int, int> temp = getMinMax(arr, arr_size);

    cout << "Minimum element is " << temp.first << endl;
    cout << "Maximum element is " << temp.second << endl;

    return 0;
}
