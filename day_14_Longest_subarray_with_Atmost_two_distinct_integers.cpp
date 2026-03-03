// Link: https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalElements(vector<int> &arr)
    {
        // code here
        unordered_map<int, int> freq;

        int left = 0, maxLen = 0;

        for (int right = 0; right < arr.size(); right++)
        {

            // Add current element
            freq[arr[right]]++;

            // If the distinct element more then 2, shrink window
            while (freq.size() > 2)
            {
                freq[arr[left]]--;

                if (freq[arr[left]] == 0)
                    freq.erase(arr[left]);

                left++;
            }

            // Update the max length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

/*
Question: Given an array of integers representing the types of fruits in a row of trees, determine the length of the longest subarray that contains at most two distinct types of fruits. Each type of fruit is represented by a unique integer in the array.

Example 1:
Input: N = 6, arr[] = {1, 2, 1, 3, 4, 2}
Output: 3
Explanation: The longest subarray with at most two distinct types of fruits is [1, 2, 1], which has a length of 3.

Example 2:
Input: N = 5, arr[] = {1, 2, 3, 2, 2}
Output: 4
Explanation: The longest subarray with at most two distinct types of fruits is [2, 3, 2, 2], which has a length of 4.

Example 3:
Input: N = 7, arr[] = {1, 2, 3, 4, 5, 6, 7}
Output: 2
Explanation: The longest subarray with at most two distinct types of fruits is [1, 2], [2, 3], [3, 4], [4, 5], [5, 6], or [6, 7], each of which has a length of 2.

============================================================================================

Optimal Approach — Sliding Window + HashMap:
1. Initialize two pointers, left and right, to represent the current window of the subarray
2. Use a hash map to keep track of the frequency of each type of fruit in the current window
3. Expand the right pointer to include more fruits until there are more than two distinct types in the window
4. If there are more than two distinct types, move the left pointer to shrink the window until there are at most two distinct types again
5. Update the maximum length of the valid subarray found during the process

Dry Run:
Input: arr[] = {1, 2, 1, 3, 4, 2}
- Start with left = 0, right = 0, freq = {}, maxLen = 0
- right = 0: freq = {1: 1}, maxLen = 1
- right = 1: freq = {1: 1, 2: 1}, maxLen = 2
- right = 2: freq = {1: 2, 2: 1}, maxLen = 3
- right = 3: freq = {1: 2, 2: 1, 3: 1} (more than 2 distinct types)
  - Move left to shrink window: left = 1, freq = {1: 1, 2: 1, 3: 1}
  - Move left again: left = 2, freq = {1: 0, 2: 1, 3: 1} (remove type 1)
    - Now freq = {2: 1, 3: 1}, maxLen = 3
- right = 4: freq = {2: 1, 3: 1, 4: 1} (more than 2 distinct types)
  - Move left to shrink window: left = 3, freq = {2: 1, 3: 0, 4: 1} (remove type 3)
    - Now freq = {2: 1, 4: 1}, maxLen = 3
- right = 5: freq = {2: 2, 4: 1}, maxLen = 3
- Final output: 3



*/