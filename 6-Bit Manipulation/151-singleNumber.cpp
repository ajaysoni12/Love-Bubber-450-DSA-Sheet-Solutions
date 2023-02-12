#include <bits/stdc++.h>
using namespace std;

/* method 1 (using sorting) */
vector<int> singleNumber(vector<int> nums)
{
    // sort array 
    sort(nums.begin(), nums.end());

    vector<int> res; // store ans 
    // i+=2 because if element not match then need to increase by 2
    for (int i = 0; i < nums.size(); i += 2)
    {
        if (nums[i] != nums[i + 1])
        {
            res.push_back(nums[i]);
            i = i - 1; // back to one positions
        }
    }
    // if res have one element the confirm second element is last element of nums array
    if (res.size() == 1)
        res.push_back(nums[nums.size() - 1]);
    return res;
    /* TC-O(n*log(n)) SC-O(1) */
}

/* method 2 (using hashing) */
vector<int> singleNumber(vector<int> nums)
{
    // store freq
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
        mp[nums[i]]++;

    // store ans
    vector<int> res;

    for (auto it : mp)
        if (it.second == 1) // if freq is one means it's unique
            res.push_back(it.first);

    // arrange in increasing order 
    if (res[0] > res[1])
        swap(res[0], res[1]);

    return res;
    /* TC-O(n) SC-O(n) */
}

/* method 3 (using bit-manipulation technique) */
vector<int> singleNumber(vector<int> nums)
{
    // store all nums ele x_or 
    int x_or = 0;
    for (int i = 0; i < nums.size(); i++)
        x_or = x_or ^ nums[i];

    // first num1 store one distinct value, and num2 second distinct value 
    int num1 = 0, num2 = 0;

    // find right set bit  
    // all ares zeros or ones -- set bit -- all ares ones
    // take one's compliment and add one binary for getting two complicant and do and 
    int rightSetBit = x_or & -x_or; // (~x_or + 1)

    // now seperate 1's and 0's rsb 
    for (int i = 0; i < nums.size(); i++)
    {
        if ((nums[i] & rightSetBit) == 0)
            num1 = (num1 ^ nums[i]);
        else
            num2 = (num2 ^ nums[i]);
    }

    // increasing order 
    if (num1 < num2)
        return { num1, num2 };
    return { num2, num1 };

    /* TC-O(2n) SC-O(1) */
}