// Link: https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxWater(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        int ans = 0;

        // set two pointer at left and right
        int left = 0, right = n - 1;

        // set the left max building and right max building
        int leftMax = 0, rightMax = 0;

        while (left < right)
        {

            // cal the left max building
            leftMax = max(leftMax, arr[left]);

            // cal the right max building
            rightMax = max(rightMax, arr[right]);

            // which side the building is smaller
            if (leftMax < rightMax)
            {
                ans += leftMax - arr[left];
                left++;
            }
            else
            {
                ans += rightMax - arr[right];
                right--;
            }
        }

        return ans;
    }
};

/*
Question: Given an array of integers representing the height of buildings, determine how much rainwater can be trapped between the buildings after it rains.
Example 1:
Input: N = 6, arr[] = {3, 0, 0, 2, 0, 4}
Output: 10
Explanation: The structure formed by the buildings can trap 10 units of rainwater.

Example 2:
Input: N = 4, arr[] = {7, 4, 0, 9}
Output: 10
Explanation: The structure formed by the buildings can trap 10 units of rainwater.

============================================================================================

Solution Approach: Optimal Approach — Two Pointers
Initialize two pointers, left and right, at the start and end of the array, respectively.
Maintain two variables, leftMax and rightMax, to keep track of the maximum height of buildings encountered from the left and right sides.
While left is less than right:
- If the height at left is less than the height at right:
  - If the height at left is greater than leftMax, update leftMax.
  - Else, add the difference between leftMax and the height at left to the answer.
  - Move the left pointer to the right.
- Else:
    - If the height at right is greater than rightMax, update rightMax.
    - Else, add the difference between rightMax and the height at right to the answer.
    - Move the right pointer to the left.

Why This Works
The amount of water trapped at any position depends on the minimum of the maximum heights from the left and right sides. By using two pointers, we can efficiently calculate the trapped water without needing extra space for left and right max arrays.

Dry Run Example:
Input: arr = [3, 0, 0, 2, 0, 4]
- Start: left = 0, right = 5, leftMax = 0, rightMax = 0, ans = 0
- left = 0: arr[left] = 3, arr[right] = 4
  - leftMax = max(0, 3) = 3
  - ans += (3 - 3) = 0
  - left = 1
- left = 1: arr[left] = 0, arr[right] = 4
  - leftMax = max(3, 0) = 3
  - ans += (3 - 0) = 3
  - left = 2
- left = 2: arr[left] = 0, arr[right] = 4
  - leftMax = max(3, 0) = 3
    - ans += (3 - 0) = 3 + 3 = 6
    - left = 3
- left = 3: arr[left] = 2, arr[right] = 4
    - leftMax = max(3, 2) = 3
    - ans += (3 - 2) = 6 + 1 = 7
    - left = 4
- left = 4: arr[left] = 0, arr[right] = 4
    - leftMax = max(3, 0) = 3
    - ans += (3 - 0) = 7 + 3 = 10
    - left = 5
- left = 5: arr[left] = 4, arr[right] = 4
    - leftMax = max(3, 4) = 4
    - ans += (4 - 4) = 10 + 0 = 10
    - left = 6 (loop ends)
Final Output: 10



| Approach      | Time  | Space |
| ------------- | ----- | ----- |
| Brute         | O(n²) | O(1)  |
| Prefix        | O(n)  | O(n)  |
| Two Pointer   | O(n)  | O(1)  |


*/