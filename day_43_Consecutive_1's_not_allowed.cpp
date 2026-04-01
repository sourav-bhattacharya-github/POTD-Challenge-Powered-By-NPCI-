// Link: https://www.geeksforgeeks.org/problems/consecutive-1s-not-allowed1912/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countStrings(int n)
    {
        if (n == 1)
            return 2;

        int prev2 = 2; // n=1 → "0", "1"
        int prev1 = 3; // n=2 → "00", "01", "10"

        for (int i = 3; i <= n; i++)
        {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

int main()
{
    Solution sol;
    int n = 5;
    int result = sol.countStrings(n);
    cout << result << endl; // Output: Number of binary strings of length n without consecutive 1's
    return 0;
}

/*
Question: Given an integer n, count the number of binary strings of length n that do not contain consecutive 1's.

Example 1:
Input: n = 3
Output: 5
Explanation: The valid binary strings of length 3 are "000", "001", "010", "100", and "101".


Example 2:
Input: n = 4
Output: 8
Explanation: The valid binary strings of length 4 are "0000", "0001", "0010", "0100", "0101", "1000", "1001", and "1010".

Example 3:
Input: n = 5
Output: 13
Explanation: The valid binary strings of length 5 are "00000", "00001", "00010", "00100", "00101", "01000", "01001", "01010", "10000", "10001", "10010", "10100", and "10101".

Note: The answer can be large, so return it modulo 10^9 + 7.

======================================================================================================
Approach: We can use dynamic programming to solve this problem. We can define two states:
1. dp[i][0]: The number of valid binary strings of length i that end with '0'.
2. dp[i][1]: The number of valid binary strings of length i that end with '1'.
The transitions are as follows:
- To end with '0', we can append '0' to any valid string of length i-1 (both those that end with '0' and '1').
- To end with '1', we can only append '1' to valid strings of length i-1 that end with '0' (to avoid consecutive '1's).
The base cases are:
- dp[1][0] = 1 (the string "0")
- dp[1][1] = 1 (the string "1")
The final answer will be the sum of dp[n][0] and dp[n][1], which gives us the total number of valid binary strings of length n. We can optimize space by only keeping track of the last two states instead of the entire dp array.

Time Complexity: O(n), where n is the length of the binary string.
Space Complexity: O(1) due to the use of only a constant amount of extra space for the variables.

Dry Run:
Input: n = 5
- Start with base cases:
  - dp[1][0] = 1 (the string "0")
  - dp[1][1] = 1 (the string "1")
- For i = 2:
  - dp[2][0] = dp[1][0] + dp[1][1] = 1 + 1 = 2 (the strings "00", "10")
  - dp[2][1] = dp[1][0] = 1 (the string "01")
- For i = 3:
  - dp[3][0] = dp[2][0] + dp[2][1] = 2 + 1 = 3 (the strings "000", "100", "010")
  - dp[3][1] = dp[2][0] = 2 (the strings "001", "101")
- For i = 4:
  - dp[4][0] = dp[3][0] + dp[3][1] = 3 + 2 = 5 (the strings "0000", "1000", "0100", "0010", "1010")
  - dp[4][1] = dp[3][0] = 3 (the strings "0001", "1001", "0101")
- For i = 5:
    - dp[5][0] = dp[4][0] + dp[4][1] = 5 + 3 = 8 (the strings "00000", "10000", "01000", "00100", "10100", "00010", "10010", "01010")
    - dp[5][1] = dp[4][0] = 5 (the strings "00001", "10001", "01001", "00101", "10101")
- The total number of valid binary strings of length 5 is dp[5][0] + dp[5][1] = 8 + 5 = 13.


*/