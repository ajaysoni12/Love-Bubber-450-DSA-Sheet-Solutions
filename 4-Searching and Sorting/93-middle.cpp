#include <bits/stdc++.h>
using namespace std;

/* method 1 (just check these basic condtions-minimum conditons)*/
int middle(int a, int b, int c)
{
    if (a > b and a > c)
        if (b > c)
            return b;
        else
            return c;
    else if (a < b and a < c)
        if (b > c)
            return c;
        else
            return b;
    else
        return a;
}