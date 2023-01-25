#include <bits/stdc++.h>
using namespace std;

int PalinArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        // digit count
        string temp = ""+a[i];

        // palindrome
        int start = 0, end = temp.size();
        while (start < end)
        {
            if (temp[start] != temp[end])
                return false;
            start++;
            end++;
        }
    }
    return true;
}