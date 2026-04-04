// Link: https://www.geeksforgeeks.org/problems/target-sum-1626326450/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTargetSumWays(vector<int> &arr, int target)
    {
        int totalSum = 0;
        for (int x : arr)
            totalSum += x;

        if ((totalSum + target) % 2 != 0 || totalSum < abs(target))
            return 0;

        int sum = (totalSum + target) / 2;

        vector<int> dp(sum + 1, 0);
        dp[0] = 1;

        for (int num : arr)
        {
            for (int j = sum; j >= num; j--)
            {
                dp[j] += dp[j - num];
            }
        }

        return dp[sum];
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 1, 1, 1, 1};
    int target = 3;
    cout << sol.findTargetSumWays(arr, target) << endl; // Output: 5
    return 0;
}

/*
Question: Given an array of integers and a target sum, find the number of ways to assign '+' and '-' signs to the integers such that their sum equals the target.

Example:
Input: arr = [1, 1, 1, 1, 1], target = 3
Output: 5
Explanation: There are 5 ways to assign signs to make the sum equal to 3:
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Note: The answer is guaranteed to fit in a 32-bit integer.

=============================================================================================================
Approach:
1. Calculate the total sum of the array elements.
2. Check if (totalSum + target) is odd or if totalSum is less than the absolute value of target. If either condition is true, return 0, as it's impossible to achieve the target.
3. Calculate the new target sum as (totalSum + target) / 2.
4. Use a dynamic programming approach to count the number of subsets of the array that sum up to the new target sum.
5. Initialize a dp array where dp[i] represents the number of ways to achieve the sum i using the elements of the array.
6. Iterate through each number in the array and update the dp array accordingly.
7. Finally, return dp[sum] which will give the number of ways to achieve the target sum.

Time Complexity: O(n * sum), where n is the number of elements in the array and sum is the new target sum.
Space Complexity: O(sum), where sum is the new target sum.

Dry Run:
For arr = [1, 1, 1, 1, 1] and target = 3:
1. totalSum = 5
2. (totalSum + target) = 8, which is even, and totalSum is greater than abs(target), so we proceed.
3. sum = (totalSum + target) / 2 = 4
4. Initialize dp array: dp = [1, 0, 0, 0, 0]
5. For each number in arr:
   - For num = 1:
     - Update dp: dp[1] += dp[0] => dp[1] = 1
     - Update dp: dp[2] += dp[1] => dp[2] = 1
     - Update dp: dp[3] += dp[2] => dp[3] = 1
     - Update dp: dp[4] += dp[3] => dp[4] = 1
   - Repeat for each of the remaining 1's, updating the dp array accordingly.
After processing all elements, dp[4] will be 5, which is the number of ways to achieve the target sum of 3.



*/