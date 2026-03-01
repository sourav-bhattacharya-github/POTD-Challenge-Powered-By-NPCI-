// like: https://www.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void pushZerosToEnd(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        int j = 0; // Position for next non-zero element

        for (int i = 0; i < n; i++)
        {
            // if current element is non-zero
            if (arr[i] != 0)
            {
                // Swap it with element at index j
                swap(arr[i], arr[j]);

                // Move j forward
                j++;
            }
        }
    }
};

/*
Question: Given an array of size N, move all the zeroes to the end of it while maintaining the relative order of the non-zero elements.

Example 1:
Input: N = 5, arr[] = {0, 2, 0, 3, 6}
Output: 2 3 6 0 0
Explanation: All the zeroes are moved to the end and the order of non-zero elements is maintained.

Example 2:
Input: N = 10, arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
Output: 1 0 0 0 0 0 0 0 0 0
Explanation: All the zeroes are moved to the end and the order of non-zero elements is maintained.

============================================================================================
Solution Approach: Optimal Approach — Two Pointers

Maintain a pointer j that tracks:
- The position where the next non-zero element should be placed.
Iterate through the array with another pointer i:
- If arr[i] is non-zero, swap it with arr[j] and increment j.
This way, all non-zero elements are moved to the front while zeroes are moved to the end, maintaining the relative order of non-zero elements.

Why This Works
j always points to first zero position
Non-zero elements get shifted left
Zeros automatically move to right

Dry Run Example:
Input: arr = [0, 2, 0, 3, 6]
- Start: j = 0
- i = 0: arr[i] = 0 (zero, do nothing)
- i = 1: arr[i] = 2 (non-zero, swap with arr[j])
  - arr becomes [2, 0, 0, 3, 6], j = 1
- i = 2: arr[i] = 0 (zero, do nothing)
- i = 3: arr[i] = 3 (non-zero, swap with arr[j])
  - arr becomes [2, 3, 0, 0, 6], j = 2
- i = 4: arr[i] = 6 (non-zero, swap with arr[j])
  - arr becomes [2, 3, 6, 0, 0],
    j = 3
Final Output: [2, 3, 6, 0, 0]


| Type  | Complexity |
| ----- | ---------- |
| Time  | O(n)       |
| Space | O(1)       |

*/