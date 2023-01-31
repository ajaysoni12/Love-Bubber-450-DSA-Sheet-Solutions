#include <bits/stdc++.h>
using namespace std;

/* method 1 (using two loops) */
string lookandsay(int n)
{
    if (n == 1)
        return "1";
    else if (n == 2)
        return "11";
    string temp = "11";
    int counter;
    int i, j;
    for (i = 3; i <= n; i++)
    {
        counter = 1;
        temp = temp + '&'; // for checking conditions
        string curr = "";
        for (j = 1; j < temp.size(); j++)
        {
            if (temp[j] != temp[j - 1])
            {
                curr += to_string(counter);
                curr += temp[j - 1];
                counter = 1;
            }
            else
                counter++;
        }
        temp = curr;
    }
    return temp;
    /* TC-O(N^2) SC-O(N) */
}