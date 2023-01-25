#include <bits/stdc++.h>
using namespace std;

/* brute force apprach */
// generate all subarray with less than k size element present in array and check 
// bad element in array return min 

/* method 2 (sliding window approach) */
int minSwap(int arr[], int n, int k)
{ 
    /* TC-O(N) SC-O(1) */
    int count = 0; 
    for(int i=0; i<n; i++) 
        if(arr[i] <= k) 
            count++; 
    
    int bad = 0; 
    for(int i=0; i<count; i++) 
        if(arr[i] > k) 
            bad++; 

    int ans = bad; 
    for(int i=0, j=count; j<n; j++, i++) 
    {
        if(arr[i] > k) 
            --bad; 
        if(arr[j] > k) 
            ++bad; 
        
        ans = min(ans, bad); 
    }
    return ans; 
}