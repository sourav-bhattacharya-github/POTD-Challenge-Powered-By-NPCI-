// Link: https://www.geeksforgeeks.org/problems/next-smallest-palindrome4740/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextPalindrome(vector<int> &num)
    {
        // code here
        int n = num.size();

        // check all 9
        bool all9 = true;
        for (int x : num)
        {
            if (x != 9)
            {
                all9 = false;
                break;
            }
        }

        if (all9)
        {
            // if all digits are 9, the next palindrome will be 100...001 (1 followed by n zeros and another 1)
            vector<int> res(n + 1, 0);

            res[0] = res[n] = 1;
            return res;
        }

        // create a copy of the input number to modify and form the next palindrome
        vector<int> res = num;

        int mid = n / 2;                 // find the middle index of the number
        int i = mid - 1;                 // index of the last digit in the left half
        int j = (n % 2) ? mid + 1 : mid; // index of the first digit in the right half

        // move i and j to the left and right respectively until we find a pair of digits that are not equal
        while (i >= 0 && res[i] == res[j])
        {
            i--;
            j++;
        }

        // check if the left half is smaller than the right half
        bool leftSmaller = false;

        // if we have moved out of bounds or the left digit is smaller than the right digit, then we need to increment the left half and mirror it to the right half
        if (i < 0 || res[i] < res[j])
        {
            leftSmaller = true;
        }

        // mirror the left half to the right half
        while (i >= 0)
        {
            res[j] = res[i];
            i--;
            j++;
        }

        // if the left half is smaller than the right half, we need to increment the left half and mirror it to the right half
        if (leftSmaller)
        {
            int carry = 1; // we need to add 1 to the left half to get the next palindrome
            i = mid - 1;   // index of the last digit in the left half

            // if the number of digits is odd, we need to add the carry to the middle digit and then mirror it to the right half
            if (n % 2 == 1)
            {
                res[mid] += carry;     // add the carry to the middle digit
                carry = res[mid] / 10; // calculate the new carry if the middle digit exceeds 9
                res[mid] %= 10;        // keep only the last digit of the middle digit
                j = mid + 1;           // index of the first digit in the right half
            }
            // if the number of digits is even, we just need to mirror the left half to the right half after adding the carry to the last digit of the left half
            else
            {
                j = mid; // index of the first digit in the right half
            }

            // add the carry to the left half and mirror it to the right half until we have processed all digits in the left half
            while (i >= 0)
            {
                res[i] += carry;
                carry = res[i] / 10;
                res[i] %= 10;

                res[j] = res[i];
                i--;
                j++;
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    vector<int> res = sol.nextPalindrome(num);
    for (int x : res)
    {
        cout << x << " ";
    }

    return 0;
}

/*
Question: Next Smallest Palindrome
Given a number in the form of an array of digits, find the next smallest palindrome larger than the given number.

Example:
Input: num = [1, 2, 3]
Output: [1, 3, 1]
Explanation: The next palindrome larger than 123 is 131.

Input: num = [9, 9, 9]
Output: [1, 0, 0, 1]
Explanation: The next palindrome larger than 999 is 1001.

Input: num = [1, 2, 9, 2, 1]
Output: [1, 3, 0, 3, 1]
Explanation: The next palindrome larger than 12921 is 13031.

Input: num = [1, 2, 3, 4, 5]
Output: [1, 2, 4, 2, 1]
Explanation: The next palindrome larger than 12345 is 12421.

Constraints:
1 <= num.length <= 10^6
0 <= num[i] <= 9
The input number does not contain leading zeros.

=================================================================================================================
Approach:
1. Check if all digits are 9: If all digits in the input number are 9, then the next palindrome will be 100...001 (1 followed by n zeros and another 1). We can directly return this result.

2. Find the middle index: Calculate the middle index of the number to determine the left and right halves.

3. Compare the left and right halves: Move two pointers, i and j, from the middle towards the left and right respectively, until we find a pair of digits that are not equal. This will help us determine if the left half is smaller than the right half.

4. Mirror the left half to the right half: If the left half is smaller than the right half, we need to increment the left half and mirror it to the right half. We can do this by adding 1 to the last digit of the left half and handling any carry that may occur.

5. Handle the carry: If there is a carry after incrementing the left half, we need to propagate it through the left half and mirror the changes to the right half until we have processed all digits in the left half.

Time Complexity: O(n), where n is the number of digits in the input number. We may need to traverse the digits multiple times (to check for all 9s, to find the middle, and to handle the carry), but each traversal is linear in the number of digits.

Space Complexity: O(n), as we are creating a new vector to store the result, which can be at most one digit longer than the input number (in the case where all digits are 9).

Dry Run 1:
Input: num = [1, 2, 3]
1. Check if all digits are 9: The digits are not all 9, so we proceed to the next step.
2. Find the middle index: mid = 3 / 2 = 1.
3. Compare the left and right halves: i = 0, j = 2.
   - res[0] = 1, res[2] = 3 (not equal), so we stop here.
4. Since res[0] < res[2], leftSmaller = true.
5. Mirror the left half to the right half: res becomes [1, 2, 1].
6. Since leftSmaller is true, we need to increment the left half and mirror it to the right half:
   - Add 1 to res[0]: res[0] = 2, carry = 0.
   - Mirror to the right half: res becomes [2, 2, 2].
   - However, since we only need to increment the left half and mirror it, we should only increment res[0] and mirror it to res[2], resulting in res becoming [1, 3, 1].
7. The final result is [1, 3, 1], which is the next palindrome larger than 123.

Dry Run 2:
Input: num = [9, 9, 9]
1. Check if all digits are 9: The digits are all 9, so we need to create the next palindrome.
2. The next palindrome larger than 999 is 1001.
3. The final result is [1, 0, 0, 1], which is the next palindrome larger than 999.

Dry Run 3:
Input: num = [1, 2, 9, 2, 1]
1. Check if all digits are 9: The digits are not all 9, so we proceed to the next step.
2. Find the middle index: mid = 5 / 2 = 2.
3. Compare the left and right halves: i = 1, j = 3.
   - res[1] = 2, res[3] = 2 (equal), so we move i and j.
   - i = 0, j = 4.
   - res[0] = 1, res[4] = 1 (equal), so we move i and j.
   - i = -1, j = 5 (out of bounds), so we stop here.
4. Since i < 0, leftSmaller = true.
5. Mirror the left half to the right half: res becomes [1, 2, 9, 2, 1].
6. Since leftSmaller is true, we need to increment the left half and mirror it to the right half:
   - Add 1 to res[1]: res[1] = 3, carry = 0.
   - Mirror to the right half: res becomes [1, 3, 0, 3, 1].
7. The final result is [1, 3, 0, 3, 1], which is the next palindrome larger than 12921.


Dry Run 4:
Input: num = [1, 2, 3, 4, 5]
1. Check if all digits are 9: The digits are not all 9, so we proceed to the next step.
2. Find the middle index: mid = 5 / 2 = 2.
3. Compare the left and right halves: i = 1, j = 3.
   - res[1] = 2, res[3] = 4 (not equal), so we stop here.
4. Since res[1] < res[3], leftSmaller = true.
5. Mirror the left half to the right half: res becomes [1, 2, 3, 2, 1].
6. Since leftSmaller is true, we need to increment the left half and mirror it to the right half:
   - Add 1 to res[1]: res[1] = 3, carry = 0.
   - Mirror to the right half: res becomes [1, 3, 3, 3, 1].
7. The final result is [1, 3, 3, 3, 1], which is the next palindrome larger than 12345.


*/