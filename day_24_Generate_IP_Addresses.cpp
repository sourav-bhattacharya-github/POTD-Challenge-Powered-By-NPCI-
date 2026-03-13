// Link: https://www.geeksforgeeks.org/problems/generate-ip-addresses/1
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Helper function to check if a segment of the IP address is valid (0-255 and no leading zeros).
    bool isValid(string s)
    {
        // A segment is invalid if it has more than one character and starts with '0' (leading zero), or if its integer value is greater than 255.
        if (s.size() > 1 && s[0] == '0')
        {
            return false;
        }

        // Convert the segment string to an integer and check if it falls within the valid range for an IP address segment (0-255).
        int num = stoi(s);

        // If the number is between 0 and 255 (inclusive), it's a valid segment.
        if (num >= 0 && num <= 255)
            return true;

        return false;
    }

    // Backtracking function to generate all possible combinations of 4 segments and check if they are valid IP address segments (0-255 and no leading zeros).
    void solve(string &s, int idx, int parts, string curr, vector<string> &ans)
    {

        // Base case: If we have 4 parts and we have consumed all characters in the string, we found a valid IP address.
        if (parts == 4 && idx == s.size())
        {
            curr.pop_back();     // Remove the trailing dot
            ans.push_back(curr); // Add the valid IP address to the answer list
            return;
        }

        // If we have 4 parts but haven't consumed all characters, or if we have consumed all characters but don't have 4 parts, it's not a valid IP address.
        if (parts == 4)
            return;

        // Try segments of length 1 to 3 characters (since the maximum value for an IP segment is 255, which has 3 digits).
        for (int len = 1; len <= 3; len++)
        {

            // If the segment length exceeds the remaining characters in the string, break out of the loop.
            if (idx + len > s.size())
                break;

            // Extract the segment from the string based on the current index and segment length.
            string segment = s.substr(idx, len);

            // Check if the segment is valid (not greater than 255 and no leading zeros). If it is valid, recursively call the solve function to generate the next segment.
            if (isValid(segment))
                solve(s, idx + len, parts + 1, curr + segment + ".", ans);
        }
    }

    vector<string> generateIp(string &s)
    {

        vector<string> ans;

        solve(s, 0, 0, "", ans);

        return ans;
    }
};

/*
Question: Given a string containing only digits, restore it by returning all possible valid IP address combinations. A valid IP address consists of exactly four integers (each integer is between 0 and 255) separated by single dots and cannot have leading zeros.

Example 1:
Input: s = "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
Explanation: These are the only valid IP address combinations that can be formed from the given string.


Example 2:
Input: s = "0000"
Output: ["0.0.0.0"]

Example 3:
Input: s = "1111"
Output: ["1.1.1.1"]

Example 4:
Input: s = “25505011535”
Output: []
Explanation: We cannot generate a valid IP address with this string.
======================================================================================================

Approach:
1. Use a backtracking approach to generate all possible combinations of 4 segments from the input string.
2. For each segment, check if it is valid (i.e., it is between 0 and 255 and does not have leading zeros).
3. If a valid combination of 4 segments is found, add it to the answer list.

Time Complexity: O(1) - Since the number of valid IP addresses that can be formed from a string of digits is limited (at most 2^4 = 16 combinations), the time complexity is constant.

Space Complexity: O(1) - The space used for storing the valid IP addresses is also limited, and the recursion stack will at most go 4 levels deep (for the 4 segments of the IP address), so the space complexity is also constant.



*/