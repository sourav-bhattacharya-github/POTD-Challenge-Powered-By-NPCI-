// Link: https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long subarrayXor(vector<int> &arr, int k)
    {
        // code here
        int res = 0;

        unordered_map<int, int> mapXOR;

        int prefixXOR = 0;

        for (auto val : arr)
        {
            // find the XOR value of current prefixXor
            prefixXOR ^= val;

            res = res + mapXOR[prefixXOR ^ k];

            if (prefixXOR == k)
            {
                res++;
            }

            mapXOR[prefixXOR]++;
        }

        return res;
    }
};