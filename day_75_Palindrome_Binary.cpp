// Link: https://www.geeksforgeeks.org/problems/palindrome-numbers0942/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isBinaryPalindrome(int n)
    {
        int left = 31;
        int right = 0;

        // find highest set bit
        while (((n >> left) & 1) == 0)
        {
            left--;
        }

        // compare bits
        while (left > right)
        {
            int l = (n >> left) & 1;
            int r = (n >> right) & 1;

            if (l != r)
                return false;

            left--;
            right++;
        }

        return true;
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        Solution ob;
        if (ob.isBinaryPalindrome(n))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }

    return 0;
}

/*
Question: Given a positive integer N, check if its binary representation is a palindrome or not.

Example 1:
Input: N = 9
Output: Yes
Explanation: The binary representation of 9 is 1001 which is a palindrome.

Example 2:
Input: N = 10
Output: No
Explanation: The binary representation of 10 is 1010 which is not a palindrome.

Example 3:
Input: N = 1
Output: Yes
Explanation: The binary representation of 1 is 1 which is a palindrome.

Constraints:
1 <= N <= 10^9

=============================================================================================================

Approach:
1. We will use two pointers, one starting from the leftmost bit and the other starting from the rightmost bit of the binary representation of N.
2. We will compare the bits at these two pointers. If they are not the same, then the binary representation is not a palindrome and we can return false.
3. If they are the same, we will move the left pointer one step to the right and the right pointer one step to the left and continue comparing until the pointers meet or cross each other.
4. If we successfully compare all the bits without finding a mismatch, then the binary representation is a palindrome and we can return true.

Time Complexity: O(log N) where N is the input number, because we are checking each bit of the number at most once.
Space Complexity: O(1) because we are using only a constant amount of extra space for the pointers and variables.

Dry Run:
Input: N = 9
1. The binary representation of 9 is 1001.
2. left = 31, right = 0
3. We find the highest set bit, which is at position 3 (0-indexed from the right).
4. Compare bits at left and right:
   - left bit (3rd bit) = 1, right bit (0th bit) = 1 -> they are the same, move pointers.
   - left = 2, right = 1
   - left bit (2nd bit) = 0, right bit (1st bit) = 0 -> they are the same, move pointers.
   - left = 1, right = 2
   - left bit (1st bit) = 0, right bit (2nd bit) = 0 -> they are the same, move pointers.
   - left = 0, right = 3
   - left bit (0th bit) = 1, right bit (3rd bit) = 1 -> they are the same, move pointers.
   - left = -1, right = 4
5. Since left < right, we stop and return true, which means the binary representation of 9 is a palindrome.

Input: N = 10
1. The binary representation of 10 is 1010.
2. left = 31, right = 0
3. We find the highest set bit, which is at position 3 (0-indexed from the right).
4. Compare bits at left and right:
   - left bit (3rd bit) = 1, right bit (0th bit) = 0 -> they are not the same, return false.
5. Since the bits are not the same, we stop and return false, which means the binary representation of 10 is not a palindrome.

*/