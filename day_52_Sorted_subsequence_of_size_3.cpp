// Link: https://www.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> find3Numbers(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> leftMin(n), rightMax(n);

        // Build leftMin
        leftMin[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            leftMin[i] = min(leftMin[i - 1], arr[i]);
        }

        // Build rightMax
        rightMax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            rightMax[i] = max(rightMax[i + 1], arr[i]);
        }

        // Find subsequence
        for (int j = 1; j < n - 1; j++)
        {
            if (leftMin[j - 1] < arr[j] && arr[j] < rightMax[j + 1])
            {
                return {leftMin[j - 1], arr[j], rightMax[j + 1]};
            }
        }

        return {};
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> result = sol.find3Numbers(arr);

    if (!result.empty())
    {
        cout << "Sorted subsequence of size 3: ";
        for (int num : result)
        {
            cout << num << " ";
        }
        cout << endl; // Output: 1 2 3
    }
    else
    {
        cout << "No sorted subsequence of size 3 found." << endl;
    }

    return 0;
}

/*
Question: Given an array of integers, find a sorted subsequence of size 3 in the array. If there are multiple such subsequences, return the one with the smallest middle element. If no such subsequence exists, return an empty array.

Example 1:
Input: arr = [1, 2, 3, 4, 5]
Output: [1, 2, 3]

Example 2:
Input: arr = [5, 4, 3, 2, 1]
Output: []

Example 3:
Input: arr = [1, 5, 2, 4, 3]
Output: [1, 2, 3]

Constraints:
1 <= arr.length <= 10^5
-10^9 <= arr[i] <= 10^9

Note: The subsequence should be strictly increasing, meaning that the elements must be in increasing order and not equal to each other.
=================================================================================================================
Approach:
1. Create two auxiliary arrays, `leftMin` and `rightMax`, of the same size as the input array.
2. Fill `leftMin` such that `leftMin[i]` contains the minimum element from the start of the array to index `i`.
3. Fill `rightMax` such that `rightMax[i]` contains the maximum element from index `i` to the end of the array.
4. Iterate through the array from index 1 to n-2 and check if there exists an element `arr[j]` such that `leftMin[j-1] < arr[j] < rightMax[j+1]`. If such an element is found, return the triplet `[leftMin[j-1], arr[j], rightMax[j+1]]`.
5. If no such triplet is found after the loop, return an empty array.

Time Complexity: O(n) - We traverse the array a few times to fill the auxiliary arrays and to find the triplet. Space Complexity: O(n) - We use two additional arrays of the same size as the input array.

Dry Run:
Input: arr = [1, 5, 2, 4, 3]
- Initialize leftMin and rightMax:
  leftMin = [1, 1, 1, 1, 1]
  rightMax = [5, 5, 4, 4, 3]
- Fill leftMin:
  leftMin[1] = min(leftMin[0], arr[1]) = min(1, 5) = 1
  leftMin[2] = min(leftMin[1], arr[2]) = min(1, 2) = 1
  leftMin[3] = min(leftMin[2], arr[3]) = min(1, 4) = 1
  leftMin[4] = min(leftMin[3], arr[4]) = min(1, 3) = 1
- Fill rightMax:
  rightMax[3] = max(rightMax[4], arr[3]) = max(3, 4) = 4
  rightMax[2] = max(rightMax[3], arr[2]) = max(4, 2) = 4
  rightMax[1] = max(rightMax[2], arr[1]) = max(4, 5) = 5
  rightMax[0] = max(rightMax[1], arr[0]) = max(5, 1) = 5
- Check for triplet:
  j = 1: leftMin[0] < arr[1] < rightMax[2] -> 1 < 5 < 4 (False)
  j = 2: leftMin[1] < arr[2] < rightMax[3] -> 1 < 2 < 4 (True) -> Return [1, 2, 4]
- The output is [1, 2, 4], which is a valid sorted subsequence of size 3. However, we need to check if there is a smaller middle element.
- j = 3: leftMin[2] < arr[3] < rightMax[4] -> 1 < 4 < 3 (False)
- No smaller middle element found, return [1, 2, 4].



*/