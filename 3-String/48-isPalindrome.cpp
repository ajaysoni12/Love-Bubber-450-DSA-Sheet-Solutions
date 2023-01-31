#include <bits/stdc++.h>
using namespace std;

/* Method 1 - (string reverse) */
int isPalindrome(string S)
{
    string temp = S;
    reverse(temp.begin(), temp.end());
    return S == temp;
    /* TC-O(N) SC-O(N) */
}

/* Method 2 - (two pointer technique) */
int isPalindrome(string s)
{
    for (int i = 0; i < s.size() / 2; i++)
        if (s[i] != s[s.size() - 1 - i])
            return 0; // not palindrome string

    return 1; // palindrome string
    /* TC-O(N) SC-O(1) */
}

/* Method 3 - (using recursive approach) */
int isPalindrome(string s, int start, int end)
{
    /* TC-O(N) SC-O(1) */
    if (start >= end)
        return 1;

    if (s[start] != s[end])
        return 0;

    isPalindrome(s, start + 1, end - 1);
}