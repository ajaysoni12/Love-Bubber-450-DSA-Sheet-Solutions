#include <bits/stdc++.h>
using namespace std;
#define MAX 10000000

/* method 1 (using brute force approach) */
int multiply(int x, int res[], int res_size)
{
    int carry = 0; // Initialize carry

    // One by one multiply n with individual digits of res[]
    for (int i = 0; i < res_size; i++)
    {
        int prod = res[i] * x + carry;

        // Store last digit of 'prod' in res[]
        res[i] = prod % 10;

        // Put rest in carry
        carry = prod / 10;
    }

    // Put carry in res and increase result size
    while (carry)
    {
        res[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    }
    return res_size;
}

int factorial(int n)
{
    int res[MAX];

    // Initialize result
    res[0] = 1;
    int res_size = 1;

    // Apply simple factorial formula n! = 1 * 2 * 3 * 4...* n
    for (int x = 2; x <= n; x++)
        res_size = multiply(x, res, res_size);

    int ans = 0;
    vector<int> temp;
    for (int i = res_size - 1; i >= 0; i--)
        temp.push_back(res[i]);

    for (int i = temp.size() - 1; i >= 0; i--)
        if (temp[i] == 0)
            ans++;
        else
            break;
    return ans;
}

int findNum(int n)
{
    int fact;
    for (long long i = 0; i < MAX; i++)
    {
        int cnt = 0;
        fact = factorial(i);
        // cout << i << ": "<<fact<<endl;
        if (fact == n)
            return i;
    }
    return -1;
}

/* method 2 (using binary search) */

// this function count tralling zeros
bool check(int p, int n)
{
    int temp = p, count = 0, fact = 5;

    // its means fact not increase to temp
    while (fact <= temp)
    {
        // count tralling zeros
        count += temp / fact;
        // increase fact by 5
        fact = fact * 5;
    }
    // if it is greater then return 0
    if (count >= n)
        return true;
    return false;
}

int findNum(int n)
{
    if (n == 1)
        return 5;

    // you can take high to max Int range but here you can take 5*n, just observe
    int low = 0, high = 5 * n;
    int ans;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (check(mid, n))
        {
            high = mid - 1;
            ans = mid; // update ans symultaneously
        }
        else
            low = mid + 1;
    }
    return ans;
    /* TC-O(log2(n) + log5(n)) SC-O(1) */
}