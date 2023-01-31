#include <bits/stdc++.h>
using namespace std;

bool checkString(string &s1, string &s2, int indexFound, int size)
{
    for (int i = 0; i < size; i++)
        if (s1[i] != s2[(indexFound + i) % size])
            return false;
    return true;
}

bool areRotations(string s1, string s2)
{
    if(s1.length() != s2.length()) 
        return false; 

    vector<int> indexes;
    bool isRotation = false;
    char firstChar = s1[0];

    for (int i = 0; i < s1.size(); i++)
        if (s2[i] == firstChar)
            indexes.push_back(i);

    for (int i = 0; i < indexes.size(); i++)
    {
        isRotation = checkString(s1, s2, indexes[i], s1.size());
        if (isRotation)
            return true;
    }
    return false;
}