// Link:https://www.geeksforgeeks.org/problems/dice-throw5349/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function using Bottom-Up DP with space optimization
    int solveTab(int d, int faces, int x)
    {

        // prev[target] = number of ways to get 'target'
        // using previous number of dice
        vector<int> prev(x + 1, 0);

        // curr[target] = number of ways to get 'target'
        // using current number of dice
        vector<int> curr(x + 1, 0);

        // Base Case:
        // If we have 0 dice and want sum = 0
        // there is exactly 1 way (do nothing)
        prev[0] = 1;

        // Iterate over number of dice
        for (int dice = 1; dice <= d; dice++)
        {

            // For every possible target sum
            for (int target = 1; target <= x; target++)
            {

                int ans = 0;

                // Try every possible face value
                for (int i = 1; i <= faces; i++)
                {

                    // Check if remaining sum is valid
                    if (target - i >= 0)
                        ans = ans + prev[target - i];
                }

                // Store ways for this target with current dice
                curr[target] = ans;
            }

            // Move current results to prev for next iteration
            prev = curr;
        }

        // Final answer: number of ways to get sum x using d dice
        return prev[x];
    }

    int noOfWays(int m, int n, int x)
    {
        // m = faces
        // n = number of dice
        return solveTab(n, m, x);
    }
};

/*
Question: Given m faces, n dice and a total x. Find the number of ways to get the sum x with n dice and m faces.

Example 1:
Input: m = 4, n = 2, x = 1
Output: 0
Explanation: With 2 dice and 4 faces, we can get minimum sum of 2 (1+1) and maximum sum of 8 (4+4). So, it is not possible to get sum 1.

Example 2:
Input: m = 6, n = 3, x = 8
Output: 21
Explanation: With 3 dice and 6 faces, we can get minimum sum of 3 (1+1+1) and maximum sum of 18 (6+6+6). So, it is possible to get sum 8 in 21 ways.

=====================================================================================================================

Approach 1: Recursion
Time Complexity: O(m^n)
Space Complexity: O(n)

Approach 2: Memoization
Time Complexity: O(n*x*m)
Space Complexity: O(n*x) + O(n) for recursion stack

Approach 3: Tabulation
Time Complexity: O(n*x*m)
Space Complexity: O(n*x)
Approach 4: Tabulation with Space Optimization
Time Complexity: O(n*x*m)
Space Complexity: O(x)

Steps for Tabulation with Space Optimization:
1. Create two 1D arrays, prev and curr, of size x+1 to store the number of ways to achieve each target sum with the previous and current number of dice, respectively.
2. Initialize prev[0] = 1, since there is one way to achieve a sum of 0 with 0 dice (by doing nothing).
3. Iterate over the number of dice from 1 to n.
4. For each number of dice, iterate over possible target sums from 1 to x.
5. For each target sum, calculate the number of ways to achieve that sum by trying all possible face values (from 1 to m) and summing the results from the previous array (prev[target - face]).
6. After processing all target sums for the current number of dice, copy the current results to the previous array for the next iteration.



*/