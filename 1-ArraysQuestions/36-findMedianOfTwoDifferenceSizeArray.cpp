#include <bits/stdc++.h>
using namespace std;

/* method 1 (Brute Force Approach) */
double MedianOfArrays(vector<int> &arr1, vector<int> &arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();

    vector<int> mergeArr;

    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
            mergeArr.push_back(arr1[i++]);
        else
            mergeArr.push_back(arr2[j++]);
    }

    while (i < n1)
        mergeArr.push_back(arr1[i++]);

    while (j < n2)
        mergeArr.push_back(arr2[j++]);

    int length = mergeArr.size();
    if (length % 2 == 0) // even
        return (mergeArr[length / 2] + mergeArr[length / 2 - 1]) / 2.0;
    return mergeArr[length / 2];

    /*  Time Complexity: O(n1+n2)
        Auxiliary Space: O(n1+n2) */
}

double MedianOfArrays(vector<int> &arr1, vector<int> &arr2)
{
    /* TC-O(min((log(N),log(M))) SC-O(1) */
    int m1 = -1, m2 = -1;
    int i = 0, j = 0;
    int count;
    int n1 = arr1.size();
    int n2 = arr2.size();
    for (count = 0; count <= (n1 + n2) / 2; count++)
    {
        m2 = m1;
        if (i != n1 && j != n2)
            m1 = arr1[i] > arr2[j] ? arr2[j++] : arr1[i++];
        else if (i < n1)
            m1 = arr1[i++];
        else
            m2 = arr2[j++];
    }

    if ((n1 + n2) % 2 == 1)
        return m2;
    return (m1 + m2) / 2.0;
}

double MedianOfArrays(vector<int> &arr1, vector<int> &arr2)
{
    /* TC-O(N+M) SC-O(1) */
    int m1 = -1, m2 = -1;
    int i = 0, j = 0;
    int length = arr1.size() + arr2.size();
    int cnt = length / 2 + 1;
    int counter = 0;

    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] <= arr2[j])
        {
            m1 = m2;
            m2 = arr1[i];
            i++;
        }
        else
        {
            m1 = m2;
            m2 = arr2[j];
            j++;
        }
        counter++;

        if (counter == cnt)
            break;
    }

    while (i < arr1.size() && counter < cnt)
    {
        m1 = m2;
        m2 = arr1[i];
        counter++;
        if (counter == cnt)
            break;
        i++;
    }

    while (j < arr2.size() && counter < cnt)
    {
        m1 = m2;
        m2 = arr2[j];
        counter++;
        if (counter == cnt)
            break;
        j++;
    }

    if (length % 2 == 0)
        return (m1 + m2) / 2.0;
    return m2;
}

/* using binary search */
double Median(vector<int> &A, vector<int> &B)
{
    int n = A.size();
    int m = B.size();
    if (n > m)
        return Median(B, A); // Swapping to make A smaller

    int start = 0;
    int end = n;
    int realmidinmergedarray = (n + m + 1) / 2;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        int leftAsize = mid;
        int leftBsize = realmidinmergedarray - mid;
        int leftA = (leftAsize > 0)
                        ? A[leftAsize - 1]
                        : INT_MIN; // checking overflow of indices
        int leftB = (leftBsize > 0) ? B[leftBsize - 1] : INT_MIN;
        int rightA = (leftAsize < n) ? A[leftAsize] : INT_MAX;
        int rightB = (leftBsize < m) ? B[leftBsize] : INT_MAX;

        // if correct partition is done
        if (leftA <= rightB and leftB <= rightA)
        {
            if ((m + n) % 2 == 0)
                return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
            return max(leftA, leftB);
        }
        else if (leftA > rightB)
        {
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return 0.0;
}