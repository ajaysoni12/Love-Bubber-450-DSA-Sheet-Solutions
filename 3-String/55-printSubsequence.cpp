#include <bits/stdc++.h>
using namespace std;

/* take it, and don't take it */
void printSubsequence(int ind, string output, string input, int n)
{
    if (ind == n)
    {
        cout << output << endl;
        return;
    }

    output.push_back(input[ind]);
    printSubsequence(ind + 1, output, input, n); // take it

    output.pop_back();
    printSubsequence(ind + 1, output, input, n); // not take it
}

int main()
{
    string input = "abcd";
    string output = "";
    printSubsequence(0, output, input, 4);
    return 0;
}