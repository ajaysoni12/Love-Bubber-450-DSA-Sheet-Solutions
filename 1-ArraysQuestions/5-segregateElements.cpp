#include <bits/stdc++.h>
using namespace std;

/* first priority understand problem, ask interviewer which side shifted(left, right) and maintain order */

/*  for without order
    1) sorting alogrithm,  TC - O(N*LOGN) SC - O(1)
    2) two poihnter approach,  TC - O(N) SC - O(1)
*/

/* without order - sorting */
vector<int> separateNegativeAndPositive(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    return arr;
    /* TC - O(N*Log(N)) SC - O(1) */
}
/* without order - using extra space */
vector<int> separateNegativeAndPositive(vector<int> &arr)
{
    int n = arr.size();
    vector<int> temp(n); // store neg to pos

    int left = 0, right = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            temp[left++] = arr[i];
        else
            temp[right--] = arr[i];
    }

    return temp;
    /* TC - O(N) SC - O(N) */
}

/* without order - using partion approach */
void separateNegativeAndPositive(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }
    /* TC - O(N) SC-O(1) */
}

/* without order - two pointer technique(dutch national flag approach) */
void separateNegativeAndPositive(int arr[], int n)
{
    /*
        arr[1…low-1] negative integers
        arr[low…high] unknown
        arr[high+1…N] positive integers
        int left = 0;
        int right = n - 1;
    */
    int left = 0, right = n - 1;
    while (left < right)
    {
        if (arr[left] < 0)
            left++;
        else if (arr[right] >= 0)
            right--;
        else
            swap(arr[left++], arr[right--]);
    }

    /*
    Antoher syntax

        while(left < right )
        {
            while(arr[left] < 0) left++; // left (-ve)
            while(arr[right] >= 0) right--; // right (+ve)

            // edge case - when left is geater then right (array have all neg element)
            if(left>=right) break;

            swap(arr[left], arr[right]); left++; right--;
        }
    */

    /*
        int i = -1;
        int pivot = 0;
        for(int j=0; j<n; ++j) {
            if(arr[j] < pivot) {
                i++;
                swap(arr[i],arr[j]);
            }
        }
    */

    /* TC - O(N) SC - O(1) */
}

/* with order - using extra space */
vector<int> separateNegativeAndPositive(vector<int> &arr)
{
    int size = arr.size();
    vector<int> temp(size);
    int negCnt = 0;

    for (int i = 0; i < size; i++)
        if (arr[i] < 0)
            negCnt++;

    for (int i = 0, j = 0; i < size; i++)
    {
        if (arr[i] < 0)
            temp[j++] = arr[i];
        else
            temp[negCnt++] = arr[i];
    }
    return temp;
    /* TC - O(2N) SC - O(N) */
}

/* with order - using two loops */
vector<int> separateNegativeAndPositive(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int j = i;
        while (arr[j] < 0 && j > 0 && arr[j - 1] >= 0)
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
    return arr;
    /* TC - O(N^2) SC - O(1) */
}
