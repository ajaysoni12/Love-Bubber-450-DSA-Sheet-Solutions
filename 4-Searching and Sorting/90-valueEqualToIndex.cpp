#include <bits/stdc++.h>
using namespace std;

/* method 1 (using linear search) */
vector<int> valueEqualToIndex(int arr[], int n)
{
    vector<int> res; // store index who value equal to index

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == i + 1) // question condtions
            res.push_back(i + 1);
    }

    // return
    return res;
    /* TC-O(N) SC-O(1 - not considerd res vector) */
}

/* method 2 (using binary search) if array is sorted */
int binarySearch(int arr[], int low, int high)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (mid == arr[mid])
            return mid;
        else if (mid > arr[mid])
            return binarySearch(arr, mid + 1, high);
        else
            return binarySearch(arr, low, mid - 1);
    }
    return -1;
    /* TC-O(Log(n)) SC-O(Log(n)) - stack */
}

int main()
{
    int arr[] = {-10, -5, 0, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Fixed Point is " << binarySearch(arr, 0, n - 1);
    return 0;
}