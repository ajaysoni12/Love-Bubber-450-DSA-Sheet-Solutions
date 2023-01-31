#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    int start = 0, end = s.size() - 1;
    while (start < end)
        if (s[start] != s[end])
            return false;
    return true;
}

/* method 1 (using three loops) */
string longestPalSubstr(string s)
{
    string longestSubStr = "";
    for (int i = 0; i < s.size(); i++)
    {
        string temp = "";
        for (int j = i; j < s.size(); j++)
        {
            temp = temp + s[j];
            if (isPalindrome(temp))
            {
                if (longestSubStr.size() < temp.size())
                    longestSubStr = temp;
            }
        }
    }
    return longestSubStr; 
    /* TC-O(N^3) SC-O(N) */
}

/* method 2 (expland from center) */
int expandFromCenter(string str, int i, int j)
{
    while (i >= 0 && j < str.size() && str[i] == str[j])
        i--, j++;

    return j - i - 1;
    /* TC-O(N) SC-O(1) */
}

string longestPalSubstr(string s)
{
    int start = 0, end = 0;

    for (int i = 0; i < s.size(); i++)
    {
        int len1 = expandFromCenter(s, i, i + 1);
        int len2 = expandFromCenter(s, i, i);
        int len = max(len1, len2);
        if (end - start < len)
        {
            start = i - (len - 1) / 2; // aba
            end = i + len / 2;
        }
    }
    return s.substr(start, end + 1);
    /* TC-O(N*N) = O(N^2)  SC-O(1) */
}

/* method 3  (visit every index) */
string longestPalSubstr(string s)
{
    string longestStr = "";

    if (s.size() < 2)
        return s;

    for (int i = 0; i < s.size(); i++)
    {
        int start = i - 1;
        int end = i + 1;

        while (end < s.size() && s[i] == s[end])
            end++;

        while (start >= 0 && s[i] == s[start])
            start--;

        while (start >= 0 && end < s.size() && s[start] == s[end])
        {
            start--;
            end++;
        }

        if (end - start - 1 > longestStr.size())
        {
            string temp = "";
            for (int i = start + 1; i < end; i++)
                temp += s[i];
            longestStr = temp;
        }

        // cout << "start = " << start << " i = " << i << " end = " << end << endl;
        // cout << "LontestStr = " << longestStr << endl
        //      << endl;
    }

    return longestStr;
    /* TC-O(N^2) SC-O(N) */
}
