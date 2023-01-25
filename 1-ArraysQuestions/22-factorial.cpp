#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

/* method 1 (bigInteger) */
vector<int> factorial(int N)
{
    vector<int> ans;
    ull fact = 1;
    for (int i = 0; i < N; i++)
        fact = fact * i;

    while (fact)
    {
        ans.push_back(fact % 10);
        fact /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

/* method 2 (store digit of factorial in array) */
#define MAX 100000
vector<int> factorial(int n)
{
    int res[MAX];

    // Initialize result
    res[0] = 1;
    int res_size = 1;

    // Apply simple factorial formula n! = 1 * 2 * 3 * 4...* n
    for (int x = 2; x <= n; x++)
        res_size = multiply(x, res, res_size);

    vector<int> ans;
    for (int i = res_size - 1; i >= 0; i--)
        ans.push_back(res[i]);
    return ans;
}

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
int main()
{
    factorial(10);
}