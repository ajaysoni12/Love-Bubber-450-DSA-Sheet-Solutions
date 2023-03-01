#include <bits/stdc++.h>
using namespace std;

/* method 1 (using dequeue)*/
int SumOfKsubArray(int arr[], int n, int k)
{
    deque<int> dq_max, dq_min;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        // window checking condtions
        if (!dq_max.empty() and dq_max.front() == i - k)
            dq_max.pop_front();
        if (!dq_min.empty() and dq_min.front() == i - k)
            dq_min.pop_front();

        // find min and max
        while (!dq_max.empty() and arr[i] > arr[dq_max.back()])
            dq_max.pop_back();
        while (!dq_min.empty() and arr[i] < arr[dq_min.back()])
            dq_min.pop_back();

        dq_max.push_back(i);
        dq_min.push_back(i);

        if (i >= k - 1)
        {
            cout << "\nmin: " << arr[dq_min.front()] << " , max: " << arr[dq_max.front()];
            sum += arr[dq_max.front()] + arr[dq_min.front()];
        }
    }
    return sum;
    /* TC-O(n) SC-O(k) */
}

int main()
{
    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << " \nsum is: "
         << SumOfKsubArray(arr, n, k);
    return 0;
}