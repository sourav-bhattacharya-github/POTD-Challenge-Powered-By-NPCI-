// Link: https://www.geeksforgeeks.org/problems/painting-the-fence3727/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countWays(int n, int k)
    {
        if (n == 1)
            return k; // n=1 → k ways to paint the single post
        if (n == 2)
            return k * k; // n=2 → k ways to paint the first post and k ways to paint the second post

        int prev2 = k;     // n=1
        int prev1 = k * k; // n=2

        for (int i = 3; i <= n; i++)
        {
            int curr = (prev1 + prev2) * (k - 1);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

int main()
{
    Solution sol;
    int n = 3; // Number of posts
    int k = 2; // Number of colors
    int result = sol.countWays(n, k);
    cout << result << endl; // Output: Number of ways to paint the fence
    return 0;
}

/*
Question: You have a fence with n posts, and you want to paint each post with one of the k colors. You must ensure that no more than two adjacent posts have the same color. How many ways can you paint the fence?

Example 1:
Input: n = 3, k = 2
Output: 6
Explanation: The valid ways to paint the fence are:
1. "Red", "Red", "Green"
2. "Red", "Green", "Red"
3. "Red", "Green", "Green"
4. "Green", "Red", "Red"
5. "Green", "Red", "Green"
6. "Green", "Green", "Red"

Example 2:
Input: n = 4, k = 2
Output: 10
Explanation: The valid ways to paint the fence are:
1. "Red", "Red", "Green", "Red"
2. "Red", "Red", "Green", "Green"
3. "Red", "Green", "Red", "Red"
4. "Red", "Green", "Red", "Green"
5. "Red", "Green", "Green", "Red"
6. "Green", "Red", "Red", "Red"
7. "Green", "Red", "Red", "Green"
8. "Green", "Red", "Green", "Red"
9. "Green", "Green", "Red", "Red"
10. "Green", "Green", "Red", "Green"

Note: The answer can be large, so return it modulo 10^9 + 7.
======================================================================================================

Approach: We can use dynamic programming to solve this problem. We can define two states:
1. dp[i][0]: The number of ways to paint the fence of length i where
    the last two posts are of different colors.
2. dp[i][1]: The number of ways to paint the fence of length i where
    the last two posts are of the same color.
The transitions are as follows:
- To have the last two posts of different colors, we can append a different color to any valid painting of length i-1 (both those that end with the same color and different colors).
- To have the last two posts of the same color, we can only append the same color to valid paintings of length i-1 that end with different colors (to avoid three adjacent posts of the same color).

The final answer will be the sum of both states for length n, i.e., dp[n][0] + dp[n][1].

Time Complexity: O(n), where n is the number of posts.
Space Complexity: O(1), since we are only keeping track of the last two states instead of the entire dp array.

Dry Run:
Input: n = 3, k = 2
- Start with base cases:
  dp[1][0] = 0 (no two adjacent posts can be the same)
  dp[1][1] = k (all posts can be the same color)
  dp[2][0] = k * (k - 1) (first post can be any color, second post must be different)
  dp[2][1] = k (both posts can be the same color)
- For i = 3:
  dp[3][0] = (dp[2][0] + dp[2][1]) * (k - 1) = (k * (k - 1) + k) * (k - 1)
  dp[3][1] = dp[2][0] = k * (k - 1)
- The total number of ways to paint the fence of length 3 is dp[3][0] + dp[3][1] = (k * (k - 1) + k) * (k - 1) + k * (k - 1) = 6 for k = 2.




*/