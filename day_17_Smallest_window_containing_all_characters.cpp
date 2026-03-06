// Link: https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string &s, string &p)
    {
        // code here
        int n = s.size(), m = p.size();

        vector<int> hash(256, 0);

        // Store the frequence of the string p
        for (int i = 0; i < m; i++)
        {
            hash[p[i]]++;
        }

        int startIdx = -1, maxLen = INT_MAX;
        int left = 0, count = 0;

        for (int right = 0; right < n; right++)
        {

            // If the current charecter is need
            if (hash[s[right]] > 0)
            {
                count++;
            }

            // Decrease frequency of the current character
            hash[s[right]]--;

            // If all the characters are found
            while (count == m)
            {
                // Update the answer if the current window is smaller
                if (right - left + 1 < maxLen)
                {
                    maxLen = right - left + 1;
                    startIdx = left;
                }

                // Remove the leftmost character from the window
                hash[s[left]]++;

                // If the leftmost character is needed, decrease the count
                if (hash[s[left]] > 0)
                    count--;

                // Shrink the window from the left
                left++;
            }
        }

        // If no valid window is found, return an empty string
        if (startIdx == -1)
            return "";
        else
            return s.substr(startIdx, maxLen);
    }
};

/*
Question: Given two strings s and p, find the smallest window in s that contains all the characters of p.

Example 1:
Input: s = "timetopractice", p = "toc"
Output: "toprac"
Explanation: The smallest window in s that contains all the characters of p is "toprac".

Example 2:
Input: s = "zoomlazapzo", p = "oza"
Output: "apzo"
Explanation: The smallest window in s that contains all the characters of p is "apzo".

Example 3:
Input: s = "hello", p = "world"
Output: ""
Explanation: There is no window in s that contains all the characters of p, so the output is an empty string.

============================================================================================

Approach 1 — Brute Force
Steps:
- Generate all substrings of s
- Check if it contains all characters of p
- Update answer if the current window is smaller than the previously found window
Time Complexity: O(N^3) (N for generating substrings, N for checking each substring, and N for counting characters)
============================================================================================

Approach 2 — Sliding Window (Optimal)

Key Idea: Use a sliding window to find the smallest substring in s that contains all characters of p.

Steps:
- Use two pointers to maintain a sliding window
- Use a frequency array to count characters in the current window
- Expand the right pointer to include characters until all characters of p are found
- Once all characters are found, try to shrink the window from the left to find the smallest valid window

Time Complexity: O(N) (N for traversing the string s)
Space Complexity: O(1) (since the frequency array has a fixed size of 256 for ASCII characters)

| Type  | Complexity        |
| ----- | ----------------- |
| Time  |   O(n)            |
| Space |   O(256) ≈ O(1)   |

*/