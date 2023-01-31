#include <bits/stdc++.h>
using namespace std;

// compare both of string
string commonPrefix(string &str1, string &str2)
{
    // store final answer
    string result = "";

    // minLength of both of the string
    int length = min(str1.size(), str2.size());

    // traverse each character
    for (int i = 0; i < length; i++)
    {
        if (str1[i] != str2[i])
            break;
        result += str1[i];
    }
    // return final answer
    return result;
}
string longestCommonPrefix(string arr[], int N)
{
    // starting prefix
    string prefix = arr[0];

    // visit each index
    for (int i = 1; i < N; i++)
        prefix = commonPrefix(prefix, arr[i]);

    // return final longestCommonPrefix
    return prefix;
    /* TC-O(N*M) SC-O(M) */
}

/* method 2 (compare character one by one) */
string longestCommonPrefix(string arr[], int N)
{
    // store minLength string
    int minLenght = INT_MAX;

    // find minLength string
    for (int i = 0; i < N; i++)
        minLenght = arr[i].size() < minLenght ? arr[i].size() : minLenght;

    // store final answer
    string result = "";
    char currChar; // store curr character
    for (int i = 0; i < minLenght; i++)
    {
        currChar = arr[0][i];
        for (int j = 1; j < N; j++)
        {
            // if not equal just return
            if (arr[j][i] != currChar)
            {
                if (result == "")
                    return "-1";
                return result;
            }
        }
        // push one by one
        result.push_back(currChar);
    }
    return result;
    /* TC-O(N*M) SC-O(M) */
}