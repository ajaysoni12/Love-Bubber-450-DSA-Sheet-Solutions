#include <bits/stdc++.h>
using namespace std;

/* method 1 (using extra space - array) */
int doUnion(int a[], int n, int b[], int m)
{
    int newLength = n + m;
    int c[newLength];

    // copy a - c array
    for (int i = 0; i < n; i++)
        c[i] = a[i];

    // copy b - c array
    for (int j = n, i = 0; j < newLength; i++, j++)
        c[j] = b[i];

    sort(c, c + newLength);

    // find how many data are present in c array, here we remeove duplicate element also
    int cnt = 0;
    for (int i = 1; i < newLength; i++)
        if (c[i] != c[i - 1]) // For Inersection check ==
            cnt++;

    // because we start from 1
    return cnt + 1; // For Intersection return only cnt

    /*  Time Complexity: O((m+n)Log(m+n))
        Auxiliary Space: O(m + n) */
}

/* method 2 (using set data structure) */
int doUnion(int a[], int n, int b[], int m)
{
    // Defining set container s
    set<int> s;

    // Inserting array elements in s
    for (int i = 0; i < n; i++)
        s.insert(a[i]);

    for (int i = 0; i < m; i++)
        s.insert(b[i]);

    cout << "Number of elements after union operation: " << s.size() << endl;
    cout << "The union set of both arrays is :" << endl;

    for (auto itr = s.begin(); itr != s.end(); itr++)
        cout << *itr << " ";
    // s will contain only distinct elements from array a and b

    set<int> hs;

    // Insert the elements of arr1[] to set S
    for (int i = 0; i < n; i++)
        hs.insert(a[i]);

    for (int i = 0; i < m; i++)

        // If element is present in set then push it to vector V
        if (hs.find(b[i]) != hs.end())
        {
            // erase element from set because if same element is present again in the array we don't need to count it again.
            hs.erase(b[i]);
            cout << b[i] << " ";
        }

    /*  Time Complexity: O(m * log(m) + n * log(n))
        Auxiliary Space: O(m + n) */
}

/* method 3 (using map data structure) */
int doUnion(int a[], int n, int b[], int m)
{
    // Defining map container mp
    map<int, int> mp;

    // Inserting array elements in mp
    for (int i = 0; i < n; i++)
        mp.insert({a[i], i});

    for (int i = 0; i < m; i++)
        mp.insert({b[i], i});

    cout << "The union set of both arrays is :" << endl;
    for (auto itr = mp.begin(); itr != mp.end(); itr++)
        cout << itr->first << " ";
    // mp will contain only distinct elements from array a and b

    /*  Time Complexity: O(m * log(m) + n * log(n))
        Auxiliary Space: O(m + n) */
}

/* Method 3 (naive approach)

Union:
    Initialize union U as empty.
    Copy all elements of the first array to U.
    Do the following for every element x of the second array:
    If x is not present in the first array, then copy x to U.
    Return U.

Intersection:
    Initialize intersection I as empty.
    Do the following for every element x of the first array
    If x is present in the second array, then copy x to I.
    Return I.
*/

/* method 5 (using sorting) */
int doUnion(int a[], int n, int b[], int m)
{
    int cnt = 0; // You just return number of union elmenet no need to create new array
    int left = 0;
    int right = 0;

    sort(a, a + n);
    sort(b, b + m);    

    while (left < n || right < m)
    {
        // skip duplicate
        while (left > 0 && left < n && a[left] == a[left - 1])
            left++;
        while (right > 0 && right < m && b[right] == b[right - 1])
            right++;

        // one array exh
        if (left >= n)
        {
            cnt++;
            left++;
            continue; // code skip and execute from starting
        }
        if (right >= m)
        {
            cnt++;
            right++;
            continue;
        }

        // comparison
        if (a[left] < b[right])
        {
            cnt++;
            left++;
        }
        else if (a[left] > b[right])
        {
            cnt++;
            right++;
        }
        else
        {
            cnt++;
            left++;
            right++;
        }
    }
    return cnt;

    /*  Time Complexity: O(m * log(m) + n * log(n))
        Auxiliary Space: O(m + n) */
}

/* method 5 (using sorting)*/
int doIntersection(int a[], int n, int b[], int m)
{
    int cnt = 0;
    int left = 0;
    int right = 0;

    sort(a, a + n);
    sort(b, b + m);

    while (left < n && right < m)
    {
        // comparison
        if (a[left] < b[right])
            left++;
        else if (a[left] > b[right])
            right++;
        else
        {
            cnt++;
            left++;
            right++;

            // duplicate
            while (left < n && a[left] == a[left - 1])
                left++;
            while (right < m && a[right] == a[right - 1])
                right++;
        }
    }
    return cnt;

    /*  Time Complexity: O(m * log(m) + n * log(n))
        Auxiliary Space: O(m + n) */
}
