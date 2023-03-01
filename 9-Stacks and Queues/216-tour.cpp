#include <bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

/* method 1 (brute force appraoch) */
int tour(petrolPump p[], int n)
{
    // consider every petrol pumps as a starting index
    for (int i = 0; i < n; i++)
    {
        // find diff if its positive then search for other
        int curr = p[i].petrol - p[i].distance;

        if (curr >= 0)
        {
            int ind = i;   // starting index
            int cnt = 0;   // cnt we can reach or not
            int carry = 0; // sum carry left

            while (cnt <= n)
            {
                // find diff + add carry
                curr = p[ind].petrol - p[ind].distance + carry;

                // if curr is negative then break loop
                if (curr < 0)
                    break;

                // increase index, and keep remember it's circular
                ind = (ind + 1) % n;
                cnt++; // increaes counter

                // if counter is equal to n means we reach
                if (cnt == n)
                    return i;

                // otherwise take left part as a carry
                carry = curr;
            }
        }
    }
    return -1; // we can't reach
    /* TC-O(n^2) SC-O(1) */
}

int tour(petrolPump p[], int n)
{
    int start = 0; // starting petrol pump index
    int requiredFuel = 0;
    int extraFuel = 0;

    // starting from 0
    for (int i = 0; i < n; i++)
    {
        // keep tracking how many extra fuel do you have
        extraFuel += (p[i].petrol - p[i].distance);

        // if extraFuel is neg then we can't start from start index so update it
        if (extraFuel < 0)
        {
            start = i + 1;
            requiredFuel += extraFuel; // update required fuel
            extraFuel = 0;
        }
    } 
    if (requiredFuel + extraFuel >= 0)
        return start;
    return -1;
    /* TC-O(n) SC-O(1) */
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        petrolPump p[n];
        for (int i = 0; i < n; i++)
            cin >> p[i].petrol >> p[i].distance;
        cout << tour(p, n);
    }
}