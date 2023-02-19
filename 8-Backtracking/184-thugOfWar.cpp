#include <bits/stdc++.h>
using namespace std;

int minDiff = INT_MAX;
string ans = "";

void thugOfWar(int arr[], int n, int vidx, string set1, string set2, int soset1, int soset2)
{
    if (vidx == n)
    {
        int delta = abs(soset1 - soset2);
        if (delta < minDiff)
        {
            minDiff = delta;
            ans = set1 + " " + set2;
        }
        return;
    }

    if (set1.size() < (n + 1) / 2)
    {
        set1.push_back(arr[vidx]);
        thugOfWar(arr, n, vidx + 1, set1, set2, soset1 + arr[vidx], soset2);
        set1.pop_back();
    }

    if (set2.size() < (n + 1) / 2)
    {
        set2.push_back(arr[vidx]);
        thugOfWar(arr, n, vidx + 1, set1, set2, soset1, soset2 + arr[vidx]);
        set2.pop_back();
    }
}