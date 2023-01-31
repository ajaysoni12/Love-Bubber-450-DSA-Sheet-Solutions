#include <bits/stdc++.h>
using namespace std;

/* method 1 (Roman Numerals to Integer Number) */
// This function returns value of a Roman symbol
int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;

    return -1;
}

// roman decimal value to roman numeral
int romanToDecimal(string &str)
{
    int res = 0; // store result

    // traverse given string
    for (int i = 0; i < str.size(); i++)
    {
        // getting value of str[i]
        int s1 = value(str[i]);
        if (i + 1 < str.size())
        {
            // getting value of str[i+1]
            int s2 = value(str[i + 1]);

            // Value of current symbol is greater or equal to the next symbol
            if (s1 >= s2)
                res += s1;
            else
                // Value of current symbol is less than the next symbol(Eg: CM - 100-1000 = 900)
                res += s2 - s1;
        }
        else
            // add last value
            res += s1;
    }

    // return last value
    return res;
    /* TC-O(N) SC-O(1) */
}

int romanToDecimal(string &str)
{
    // map value of roman and integer
    unordered_map<char, int> roman = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};

    // store final ans
    int ans = 0;
    int i = 0;

    // traverse given string
    while (i < str.size())
    {
        // remeber privous conditions of method 1
        if (roman[str[i]] < roman[str[i + 1]])
        {
            ans += (roman[str[i + 1]] - roman[str[i]]);
            i = i + 2; // because we add i+1 also
            continue;  // back,no need to run below code
        }
        // normal addtions
        ans += roman[str[i]];
        i++;
    }
    // return final ans
    return ans;
    /* TC-O(N) SC-O(1) */
}

/* method 3 (else if ladder) */
int romanToDecimal(string s)
{
    /* declare two variables first will calculate the number and second will help
       in iterating through the string character-wise*/
    int ans = 0, i;
    for (i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == 'I' && s[i + 1] == 'V')
        {
            ans += 4;
            i++;
            continue;
        }
        else if (s[i] == 'I' && s[i + 1] == 'X')
        {
            ans += 9;
            i++;
            continue;
        }
        else if (s[i] == 'X' && s[i + 1] == 'L')
        {
            ans += 40;
            i++;
            continue;
        }
        else if (s[i] == 'X' && s[i + 1] == 'C')
        {
            ans += 90;
            i++;
            continue;
        }
        else if (s[i] == 'C' && s[i + 1] == 'D')
        {
            ans += 400;
            i++;
            continue;
        }
        else if (s[i] == 'C' && s[i + 1] == 'M')
        {
            ans += 900;
            i++;
            continue;
        }
        // till this we checked all the category like 4,9,40,90 etc.
        else if (s[i] == 'I')
            ans += 1;
        else if (s[i] == 'V')
            ans += 5;
        else if (s[i] == 'X')
            ans += 10;
        else if (s[i] == 'L')
            ans += 50;
        else if (s[i] == 'C')
            ans += 100;
        else if (s[i] == 'D')
            ans += 500;
        else if (s[i] == 'M')
            ans += 1000;
    }

    /* for last character that left in the string if last two char comes not in the category of 4,9,40,90 etc as loop is iterating till size-1*/
    if (s.size() > i)
    {
        if (s[i] == 'I')
            ans += 1;
        else if (s[i] == 'V')
            ans += 5;
        else if (s[i] == 'X')
            ans += 10;
        else if (s[i] == 'L')
            ans += 50;
        else if (s[i] == 'C')
            ans += 100;
        else if (s[i] == 'D')
            ans += 500;
        else if (s[i] == 'M')
            ans += 1000;
    }

    return ans;
    /* TC-O(N) SC-O(1) */
}
