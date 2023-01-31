#include <bits/stdc++.h>
using namespace std;

/* method 1(brute force approach) */
bool searchPattern(string str, string pat)
{
    // find size of string
    int str_size = str.size();
    int pat_size = pat.size();

    //  visit every index
    for (int i = 0; i + pat_size <= str_size; i++)
    {
        // if first char match, then we search for all other character
        if (str[i] == pat[0])
        {
            int k = i;
            int j;
            for (j = 0; j < pat_size; j++, k++)
            {
                // if any char not match
                if (str[k] != pat[j])
                    break;
            }

            // pattern found
            if (j == pat_size)
                return true;
        }
    }
    // patern not found
    return false;

    /* TC-O(n^2) SC-O(1) */
}



