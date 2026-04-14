// Linl: https://www.geeksforgeeks.org/problems/remove-spaces0128/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeSpaces(string &s)
    {
        // code here
        int n = s.size();
        int j = 0;

        for (int i = 0; i < n; i++)
        {

            if (s[i] != ' ')
            {
                s[j++] = s[i];
            }
        }

        return s.substr(0, j);
    }
};

int main()
{
    Solution sol;
    string s;
    getline(cin, s);

    string res = sol.removeSpaces(s);
    cout << res << endl;

    return 0;
}

/*
Question: Given a string s, remove all the spaces from the string and return the resulting string.

Example 1:
Input: s = "geeks for geeks"
Output: "geeksforgeeks"
Explanation: All the spaces are removed from the string.


Example 2:
Input: s = "   hello world   "
Output: "helloworld"
Explanation: All the spaces are removed from the string.

Constraints:
1 <= s.length <= 10^5
s consists of English letters and spaces.

==================================================================================================================
Approach:
1. Initialize a variable j to keep track of the position in the string where we will write the next non-space character.
2. Iterate through the string using a loop. For each character, check if it is a space or not.
3. If the character is not a space, write it to the position indicated by j and increment j.
4. After the loop, the first j characters of the string will contain the non-space characters. We can return a substring of s from index 0 to j to get the final result.

Time Complexity: O(n), where n is the length of the input string. We need to iterate through the string once to remove the spaces.
Space Complexity: O(1), as we are modifying the string in place and not using any additional data structures that grow with the input size.

Dry Run:
Input: s = "geeks for geeks"
1. Initialize j = 0.
2. Iterate through the string:
- i = 0, s[i] = 'g' (not a space), s[j] = 'g', j = 1.
- i = 1, s[i] = 'e' (not a space), s[j] = 'e', j = 2.
- i = 2, s[i] = 'e' (not a space), s[j] = 'e', j = 3.
- i = 3, s[i] = 'k' (not a space), s[j] = 'k', j = 4.
- i = 4, s[i] = 's' (not a space), s[j] = 's', j = 5.
- i = 5, s[i] = ' ' (space), skip.
- i = 6, s[i] = 'f' (not a space), s[j] = 'f', j = 6.
- i = 7, s[i] = 'o' (not a space), s[j] = 'o', j = 7.
- i = 8, s[i] = 'r' (not a space), s[j] = 'r', j = 8.
- i = 9, s[i] = ' ' (space), skip.
- i = 10, s[i] = 'g' (not a space), s[j] = 'g', j = 9.
- i = 11, s[i] = 'e' (not a space), s[j] = 'e', j = 10.
- i = 12, s[i] = 'e' (not a space), s[j] = 'e', j = 11.
- i = 13, s[i] = 'k' (not a space), s[j] = 'k', j = 12.
- i = 14, s[i] = 's' (not a space), s[j] = 's', j = 13.
3. After the loop, j = 13, and the first 13 characters of s are "geeksforgeeks". We return s.substr(0, 13) which is "geeksforgeeks".





*/