// Link: https://www.geeksforgeeks.org/problems/implement-atoi/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string &s)
    {
        // code here
        int i = 0, n = s.size();

        while (i < n && s[i] == ' ')
            i++;

        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        long long result = 0;

        while (i < n && isdigit(s[i]))
        {
            int digit = s[i] - '0';

            if (result > INT_MAX / 10 ||
                (result == INT_MAX / 10 && digit > 7))
            {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return (int)(sign * result);
    }
};

int main()
{
    Solution sol;
    string s;
    getline(cin, s);

    int res = sol.myAtoi(s);
    cout << res << endl;

    return 0;
}

/*
Question: Implement the function myAtoi which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi is as follows:
1. Read in and ignore any leading whitespace.
2. Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
3. Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
4. Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
5. If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -2^31 should be clamped to -2^31, and integers greater than 2^31 - 1 should be clamped to 2^31 - 1.
6. Return the integer as the final result.

Example 1:
Input: s = "42"
Output: 42
Explanation: The underlined characters are what is read in, the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
Step 2: "42" (no characters read because there is neither a '-' nor '+')
Step 3: "42" (characters read in are "42") The parsed integer is 42, which is in the range [-231, 231 - 1], so we return 42.

Example 2:
Input: s = "   -42"
Output: -42
Explanation: The underlined characters are what is read in, the caret is the current reader position
Step 1: "   -42" (leading whitespace characters read in are "   ")
Step 2: "   -42" (character read in is '-' because the next non whitespace character is '-')
Step 3: "   -42" (characters read in are "42") The parsed integer is -42, which is in the range [-231, 231 - 1], so we return -42.

Example 3:
Input: s = "4193 with words"
Output: 4193
Explanation: The underlined characters are what is read in, the caret is the current reader position
Step 1: "4193 with words" (no characters read because there is no leading whitespace)
Step 2: "4193 with words" (no characters read because there is neither a '-' nor '+')
Step 3: "4193 with words" (characters read in are "4193") The parsed integer is 4193, which is in the range [-231, 231 - 1], so we return 4193.

Example 4:
Input: s = "words and 987"
Output: 0
Explanation: The underlined characters are what is read in, the caret is the current reader position
Step 1: "words and 987" (no characters read because there is no leading whitespace)
Step 2: "words and 987" (no characters read because there is neither a '-' nor '+')
Step 3: "words and 987" (no characters read because there is no leading digit) The parsed integer is 0, which is in the range [-231, 231 - 1], so we return 0.

==================================================================================================================
Approach:
1. Initialize an index i to 0 and determine the length n of the input string s.
2. Skip any leading whitespace characters by incrementing i until a non-whitespace character is encountered or the end of the string is reached.
3. Check if the next character is a sign indicator ('+' or '-'). If it is, set the sign variable accordingly and increment i to move past the sign character.
4. Initialize a variable result to 0 to store the parsed integer value.
5. Iterate through the characters of the string starting from index i:
   a. If the current character is a digit, convert it to an integer and update the result by multiplying the existing result by 10 and adding the new digit.
   b. Before updating the result, check for potential overflow by comparing the current result with INT_MAX / 10 and the new digit with 7 (the last digit of INT_MAX). If an overflow is detected, return INT_MAX or INT_MIN based on the sign.
   c. If a non-digit character is encountered, break out of the loop as we have finished parsing the number.
6. Return the final result multiplied by the sign to account for negative numbers if necessary.

Time Complexity: O(n), where n is the length of the input string s, as we may need to traverse the entire string in the worst case.
Space Complexity: O(1), as we are using a constant amount of space to store variables and the result.

Dry Run:
Input: s = "   -42"
- Initialize i = 0, n = 7
- Skip leading whitespace: i becomes 3 (pointing to '-')
- Check for sign: s[3] is '-', so sign = -1 and i becomes 4
- Initialize result = 0
- Iterate through characters starting from index 4:
  - s[4] is '4' (a digit), convert to integer 4, update result = 0 * 10 + 4 = 4
  - s[5] is '2' (a digit), convert to integer 2, update result = 4 * 10 + 2 = 42
    - s[6] is the end of the string, break out of the loop
- Return sign * result = -1 * 42 = -42



*/