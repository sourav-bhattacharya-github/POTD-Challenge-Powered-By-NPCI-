// Link: https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPartitions(vector<int> &arr, int diff)
    {
        int n = arr.size();
        int totalSum = 0;

        for (int x : arr)
            totalSum += x;

        if ((totalSum + diff) % 2 != 0)
            return 0;

        int target = (totalSum + diff) / 2;

        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int num : arr)
        {
            for (int j = target; j >= num; j--)
            {
                dp[j] += dp[j - num];
            }
        }

        return dp[target];
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 1, 2, 3};
    int diff = 1;

    int result = sol.countPartitions(arr, diff);
    cout << result << endl; // Output: Number of partitions with the given difference

    return 0;
}

/*
Question: Given an array of integers and a difference value, count the number of ways to partition the array into two subsets such that the absolute difference between the sums of the subsets is equal to the given difference.

Example 1:
Input: arr = [1, 1, 2, 3], diff = 1
Output: 3
Explanation: The three partitions are:
- Subset 1: {1, 2}, Subset 2: {1, 3} (Difference = 1)
- Subset 1: {1, 3}, Subset 2: {1, 2} (Difference = 1)
- Subset 1: {2, 3}, Subset 2: {1, 1} (Difference = 1)

Example 2:
Input: arr = [1, 2, 3, 4], diff = 2
Output: 2
Explanation: The two partitions are:
- Subset 1: {1, 4}, Subset 2: {2, 3} (Difference = 2)
- Subset 1: {2, 4}, Subset 2: {1, 3} (Difference = 2)

Example 3:
Input: arr = [1, 2, 3], diff = 4
Output: 0
Explanation: There are no partitions that can achieve a difference of 4.


Constraints:
1 <= arr.length <= 100
1 <= arr[i] <= 100


===================================================================================================================
Approach:
1. Calculate the total sum of the array elements.
2. Check if (totalSum + diff) is even. If not, return 0, as it's impossible to partition the array into two subsets with the given difference.
3. Calculate the target sum for one of the subsets as (totalSum + diff) / 2.
4. Use a dynamic programming approach to count the number of subsets that sum up to the target
5. Initialize a DP array where dp[j] represents the number of ways to achieve a sum of j using the elements of the array.
6. Iterate through each number in the array and update the DP array accordingly.
7. The final answer will be in dp[target], which gives the number of subsets that sum up to the target, and thus the number of partitions with the given difference.


Time Complexity: O(n * target), where n is the number of elements in the array and target is the calculated target sum.
Space Complexity: O(target) for the DP array.



Dry Run:
Input: arr = [1, 1, 2, 3], diff = 1
1. totalSum = 1 + 1 + 2 + 3 = 7
2. (totalSum + diff) = 7 + 1 = 8, which is even, so we proceed.
3. target = (totalSum + diff) / 2 = 8 / 2 = 4
4. Initialize dp array: dp = [1, 0, 0, 0, 0] (dp[0] = 1 because there's one way to achieve a sum of 0 - by choosing no elements)
5. Process each number in arr:
    - For num = 1:
      - Update dp: dp[4] += dp[3] (0), dp[3] += dp[2] (0), dp[2] += dp[1] (0), dp[1] += dp[0] (1)
      - dp = [1, 1, 0, 0, 0]
    - For num = 1:
      - Update dp: dp[4] += dp[3] (0), dp[3] += dp[2] (0), dp[2] += dp[1] (1), dp[1] += dp[0] (1)
      - dp = [1, 2, 1, 0, 0]
    - For num = 2:
      - Update dp: dp[4] += dp[2] (1), dp[3] += dp[1] (2), dp[2] += dp[0] (1)
      - dp = [1, 2, 2, 2, 1]
    - For num = 3:
      - Update dp: dp[4] += dp[1] (2), dp[3] += dp[0] (1)
      - Final dp = [1, 2, 2, 3, 3]
6. The result is dp[target] = dp[4] = 3, which means there are 3 ways to partition the array with the given difference.


*/