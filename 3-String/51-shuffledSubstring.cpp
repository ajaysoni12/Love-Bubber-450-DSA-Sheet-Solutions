#include <bits/stdc++.h>
using namespace std;

/* method 1 (using sorting technique and extra space)*/
bool isShuffledSubstring(string a, string b)
{
    int n1 = a.size();
    int n2 = b.size();

    // if a string length greater then b string length then return false
    if (n1 > n2)
        return false;

    // sort a string
    sort(a.begin(), a.end());

    // check for all index from 0 to i+n1-1
    for (int i = 0; i < n2; i++)
    {
        // search space
        if (i + n1 - 1 >= n2)
            return false;

        // store string from j+i to n1
        string str = "";

        // storing char
        for (int j = 0; j < n1; j++)
            str += b[j + i];

        // sort string
        sort(str.begin(), str.end());

        // compare
        if (str == a)
            return true;
    }

    // string not shuffled 
    return false;
    /* TC-O(n1* n2*LogN) SC-O(n1) */
}

/* keep order of character */
bool isShuffledSubstring(string a, string b, string result)
{
    /* TC-O(N3) SC-O(1) */
    int n1 = a.size();
    int n2 = b.size();
    int n3 = result.size();

    if (n1 + n2 != n3)
        return false;

    int i = 0, j = 0, k = 0;

    while (k < n3)
    {
        if (i < n1 && a[i] == result[k])
            i++;
        else if (j < n2 && b[j] == result[k])
            j++;
        else
            break;

        k++;
    }
    if (i < n1 || j < n2)
        return false;
    return true;
}