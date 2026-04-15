// Question Link: https://www.geeksforgeeks.org/problems/urlify-a-given-string--141625/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string URLify(string &s)
    {
        // code here
        int n = s.size();

        string res = "";

        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ')
            {
                res += "%20";
            }
            else
            {
                res += s[i];
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    string s;
    getline(cin, s);

    string res = sol.URLify(s);
    cout << res << endl;

    return 0;
}

/*
Question: Given a string s, replace all the spaces in the string with "%20" and return the resulting string.

Example 1:
Input: s = "geeks for geeks"
Output: "geeks%20for%20geeks"
Explanation: All the spaces are replaced with "%20" in the string.

Example 2:
Input: s = "   hello world   "
Output: "%20%20%20hello%20world%20%20%20"
Explanation: All the spaces are replaced with "%20" in the string.

Constraints:
1 <= s.length <= 10^5
s consists of English letters and spaces.
==================================================================================================================
Approach:
1. Initialize an empty string res to store the resulting string.
2. Iterate through each character in the input string s:
   a. If the character is a space, append "%20" to res.
   b. Otherwise, append the character itself to res.
3. Return the resulting string res after processing all characters in s.

Time Complexity: O(n), where n is the length of the input string s, since we need to iterate through all characters in the string once.

Space Complexity: O(n), where n is the length of the input string s, since in the worst case (when all characters are spaces), the resulting string res will have a length of 3n (each space is replaced by three characters "%20").

Dry Run:
Input: s = "geeks for geeks"
- Initialize res = ""
- Iterate through each character in s:
  - 'g' -> res = "g"
  - 'e' -> res = "ge"
  - 'e' -> res = "gee"
  - 'k' -> res = "geek"
  - 's' -> res = "geeks"
  - ' ' -> res = "geeks%20"
  - 'f' -> res = "geeks%20f"
  - 'o' -> res = "geeks%20fo"
  - 'r' -> res = "geeks%20for"
  - ' ' -> res = "geeks%20for%20"
  - 'g' -> res = "geeks%20for%20g"
  - 'e' -> res = "geeks%20for%20ge"
  - 'e' -> res = "geeks%20for%20gee"
  - 'k' -> res = "geeks%20for%20geek"
  - 's' -> res = "geeks%20for%20geeks"
- Return res = "geeks%20for%20geeks"


*/