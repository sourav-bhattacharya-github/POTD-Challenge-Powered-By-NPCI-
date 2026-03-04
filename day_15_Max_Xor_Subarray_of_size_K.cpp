// Link: https://www.geeksforgeeks.org/problems/max-xor-subarray-of-size-k/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubarrayXOR(vector<int> &arr, int k)
    {
        // code here
        int n = arr.size();

        if (k > n)
            return 0;

        int currXor = 0;

        // Computer XOR of first window
        for (int i = 0; i < k; i++)
        {
            currXor ^= arr[i];
        }

        int maxXor = currXor;

        // Slide the window
        for (int i = k; i < n; i++)
        {

            // Remove left element
            currXor ^= arr[i - k];

            // Add new element
            currXor ^= arr[i];

            maxXor = max(maxXor, currXor);
        }

        return maxXor;
    }
};

/*
Question: Given an array of integers and an integer K, find the maximum XOR of any subarray of size K.

Example 1:
Input: N = 5, K = 2, arr[] = {1, 2, 3, 4, 5}
Output: 7
Explanation: The subarray of size 2 with the maximum XOR is [3, 4], which has an XOR value of 7.

Example 2:
Input: N = 6, K = 3, arr[] = {1, 2, 3, 4, 5, 6}
Output: 7
Explanation: The subarray of size 3 with the maximum XOR is [1, 2, 3], which has an XOR value of 0. However, the subarray [4, 5, 6] has an XOR value of 7, which is the maximum.

============================================================================================

Approach 2 — Sliding Window XOR (Optimal)

Steps:
-Compute XOR of first k elements
-Slide the window
-Remove left element using XOR
-Add new right element

Because:
X ^ a ^ a = X

Dry Run:
Input: N = 5, K = 2, arr[] = {1, 2, 3, 4, 5}
- Compute XOR of first 2 elements: currXor = 1 ^ 2 = 3, maxXor = 3
- Slide the window:
  - Remove left element (1): currXor = 3 ^ 1 = 2
  - Add new right element (3): currXor = 2 ^ 3 = 1, maxXor = max(3, 1) = 3
    - Remove left element (2): currXor = 1 ^ 2 = 3
    - Add new right element (4): currXor = 3 ^ 4 = 7, maxXor = max(3, 7) = 7
    - Remove left element (3): currXor = 7 ^ 3 = 4
    - Add new right element (5): currXor = 4 ^ 5 = 1, maxXor = max(7, 1) = 7
- Final maxXor = 7



| Type  | Complexity |
| ----- | ---------- |
| Time  | O(n)       |
| Space | O(1)       |



*/