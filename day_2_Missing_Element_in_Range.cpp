// Link: https://www.geeksforgeeks.org/problems/missing-element-in-range/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> missinRange(vector<int> &arr, int low, int high)
    {
        // code here
        unordered_set<int> hashSet(arr.begin(), arr.end());

        vector<int> res;

        for (int num = low; num <= high; num++)
        {
            if (hashSet.find(num) == hashSet.end())
            { // not find in hash map
                res.push_back(num);
            }
        }

        return res;
    }
};