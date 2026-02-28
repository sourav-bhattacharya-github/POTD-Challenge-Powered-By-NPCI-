// Link: https://www.geeksforgeeks.org/problems/find-the-closest-pair-from-two-arrays4215/1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x)
    {
        // code here
        int n = arr1.size(), m = arr2.size();
        int i = 0, j = m - 1, minDiff = INT_MAX;
        int res1 = 0, res2 = 0;

        while (i < n && j >= 0)
        {
            int sum = arr1[i] + arr2[j];
            int diff = abs(sum - x);

            // Update best pair
            if (diff < minDiff)
            {
                minDiff = diff;
                res1 = arr1[i];
                res2 = arr2[j];
            }

            // Move the pointers
            if (sum > x)
                j--;
            else
                i++;
        }

        return {res1, res2};
    }
};

/*
Qestion: Given two sorted arrays arr1 and arr2 of size n and m respectively, and an integer x, find the pair from both arrays such that the sum of the pair is closest to x.

Example 1:
Input:
arr1 = [1, 4, 5, 7]
arr2 = [10, 20, 30, 40]
x = 32
Output: 1 30
Explanation: The pair (1, 30) gives the sum 31 which is closest to 32.

Example 2:
Input:
arr1 = [1, 4, 5, 7]
arr2 = [10, 20, 30, 40]
x = 50
Output: 7 40
Explanation: The pair (7, 40) gives the sum 47 which is closest to 50.

============================================================================================

Solution Approach: Optimal Approach — Two Pointers (Because Arrays are Sorted)

This is the key observation:
Arrays are already sorted.

So we use:
Pointer i at start of arr1
Pointer j at end of arr2

Why This Works:
If:
sum = arr1[i] + arr2[j]
If sum > x → decrease sum → move j--
If sum < x → increase sum → move i++

Because:
arr1 = [1,4,5,7]
arr2 = [10,20,30,40]
x = 32
arr1 increasing
arr2 increasing

Step-by-Step Dry Run:
i = 0, j = 3 → sum = 1 + 40 = 41 > 32 → move j to left
i = 0, j = 2 → sum = 1 + 30 = 31 < 32 → move i to right
i = 1, j = 2 → sum = 4 + 30 = 34 > 32 → move j to left
i = 1, j = 1 → sum = 4 + 20 = 24 < 32 → move i to right
i = 2, j = 1 → sum = 5 + 20 = 25 < 32 → move i to right
i = 3, j = 1 → sum = 7 + 20 = 27 < 32 → move i to right
i = 4, j = 1 → i out of bounds → stop

| Type  | Complexity |
| ----- | ---------- |
| Time  | O(n + m)   |
| Space | O(1)       |


*/