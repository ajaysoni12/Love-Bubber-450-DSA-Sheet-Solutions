#include <bits/stdc++.h>
using namespace std;

bool check(string &str)
{
    // curr string size
    int n = str.size();

    // 1st invalid case: if size is 0 or greater then 3
    if (n <= 0 || n > 3)
        return false;

    // 2nd invalid case: if portion start from 0 and have greater then 1 size
    if (str[0] == '0' && n > 1)
        return false;

    // convert string to digit
    int num = stoi(str);

    // 1 part size is 8 bit that why
    if (num < 0 || num > 255)
        return false;

    // valid
    return true;
}

string generate(string &str, int i, int j, int k, int n)
{
    string s1, s2, s3, s4;

    // substr(where, sizeof_substring)
    s1 = str.substr(0, i + 1);         // 1st part (0 to i)
    s2 = str.substr(i + 1, j - i);     // 2nd part (i+1, j-1)
    s3 = str.substr(j + 1, k - j);     // 3rd part(j+1, k-j)
    s4 = str.substr(k + 1, n - 1 - k); // 4rth part (k+1, n-1-k)
    if (check(s1) and check(s2) and check(s3) and check(s4))
        return s1 + "." + s2 + "." + s3 + "." + s4; // return ans
    return "";                                      // empty string of size 0
}

vector<string> genIp(string &s)
{
    vector<string> ans; // store all ipv4 string
    int n = s.size();   // size of string

    // 4 part, 0-i,i-j, j-k, k-n

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                string str = generate(s, i, j, k, n);
                if (str.size() > 0)
                    ans.push_back(str);
            }
        }
    }
    return ans;
    /* TC-O(N^3) SC-O(N) */
}
