// Link: https://www.geeksforgeeks.org/problems/longest-subarray-with-majority-greater-than-k/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        // Code here
        int n = arr.size();
        int prefixSum = 0, maxi = 0;

        // We can transform the problem into a zero sum problem by treating elements greater than k as +1 and elements less than or equal to k as -1. This way, we want to find the longest subarray with a positive prefix sum, which indicates that there are more elements greater than k than less than or equal to k in that subarray.
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            // Transform into zero sum problem
            if (arr[i] > k)
            {
                prefixSum += 1; // count(elements > k)  >  count(elements ≤ k) => prefixSum > 0
            }
            else
            {
                prefixSum -= 1; // count(elements > k)  >  count(elements ≤ k) => prefixSum > 0
            }

            if (prefixSum > 0)
            {
                maxi = max(maxi, i + 1); // If prefixSum > 0, it means from the start to the current index, we have more elements greater than k than less than or equal to k, so we can consider the whole subarray from the start to the current index.
            }
            else
            {
                if (mp.find(prefixSum - 1) != mp.end())
                {
                    maxi = max(maxi, i - mp[prefixSum - 1]); // If prefixSum <= 0, we need to find a previous prefixSum that is one less than the current prefixSum (prefixSum - 1) to ensure that the subarray between that index and the current index has more elements greater than k than less than or equal to k.
                }
            }
            if (mp.find(prefixSum) == mp.end()) // We only want to store the first occurrence of each prefixSum to maximize the length of the subarray.
                mp[prefixSum] = i;
        }

        return maxi;
    }
};
/*
Question: Given an array of integers and an integer K, find the length of the longest subarray which has majority of its elements greater than K.
i.e: count(elements > k)  >  count(elements ≤ k)

Example 1:
Input:
N = 5, K = 3
A[] = {1, 2, 3, 4, 5}
Output: 3
Explanation: The longest subarray with majority of its elements greater than 3 is from index 2 to 4.

Example 2:
Input:
N = 5, K = 3
A[] = {1, 2, 3, 4, 5}
Output: 3
Explanation: The longest subarray with majority of its elements greater than 3 is from index 2 to 4.
*/