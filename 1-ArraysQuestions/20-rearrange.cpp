#include <bits/stdc++.h>
using namespace std;

/* method 1 (using extra array) while array contain neg, pos or only pos - order doesn't matter*/
void rearrange(long long *arr, int n)
{
    sort(arr, arr + n);

    int temp[n];
    int low = 0, high = n - 1;
    int ind = 0;
    while (low <= high)
    {
        temp[ind++] = arr[low++];
        temp[ind++] = arr[high--];
    }
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];

    /*  Time Complexity: O(n*Log(n))
        Auxiliary Space: O(n) */
}

/* method 2 (using extra array) while array contain only neg and pos - order matter */
void rearrange(long long *arr, int n)
{
    vector<int> neg;
    vector<int> pos;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            neg.push_back(arr[i]);
        else
            pos.push_back(arr[i]);
    }

    int i, j, ind = 0;
    for (i = 0, j = 0; i < n; ind++)
    {
        if (i < neg.size())
            arr[ind] = neg[i];
        if (j < neg.size())
            arr[ind] = pos[i];
    }

    /*  Time Complexity: O(n + n)
       Auxiliary Space: O(n+m) */
}

/* method 3 (witout using extra space o(1)) remember order doesn't matter array contain neg element - but similar code for min and max alternative  */
void rearrange(long long *arr, int n)
{
    int left = 0, right = n - 1;
    while (left < right)
    {
        while (arr[left] >= 0 && left < right)
            left++;

        while (arr[right] < 0 && left < right)
            right--;

        if (left < right)
            swap(arr[left++], arr[right--]);
    }

    if (left == 0 || left == n) // means no neg, or pos
        return;

    for (int k = 0; k < n && left < n; k = k + 2)
        swap(arr[k], arr[left++]);

    /*  Time Complexity: O(n)
        Auxiliary Space: O(1) */
}

/* method 1 (using extra array) if array is given sorted (1l1s, 2l2s, 3l3s) */
void rearrange(long long *arr, int n)
{
    int min = 0, max = n - 1;
    vector<int> temp;
    while (min <= max)
    {
        if (min < max) // if min and max equal to
            temp.push_back(arr[max--]);
        temp.push_back(arr[min++]);
    }

    for (int i = 0; i < n; i++)
        arr[i] = temp[i];

    /*  Time Complexity: O(n)
        Auxiliary Space: O(n) */
}

/* method 2 (store 2 no at one array positions) (1l1s, 2l2s, 3l3s) */
void rearrange(long long *arr, int n)
{
    /*  formula - dividend(bajya) = quotient(bhagphal) * divisor(bajak)  + reminder(shesphal)*/
    /*  dividend / Divisor = Quetient
        dividened % divisor = reminder */

    int minIndex = 0;
    int maxIndex = n - 1;
    int maxElement = arr[n - 1] + 1;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            arr[i] = (arr[maxIndex--] % maxElement) * maxElement + arr[i];
        else
            arr[i] = (arr[minIndex++] % maxElement) * maxElement + arr[i];
    }

    for (int i = 0; i < n; i++)
        arr[i] /= maxElement;

    /*  Time Complexity: O(n)
        Auxiliary Space: O(1) */
}
