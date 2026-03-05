// Link: https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        vector<int> freq(26, 0);
        int distinct = 0;
        int left = 0, maxLen = -1;
        
        for(int right = 0; right < s.size(); right++){
            int idx = s[right] - 'a';
            
            if(freq[idx] == 0)
                distinct++;
                
            freq[idx]++;
            
            // Shrink window if distinct > k
            while(distinct > k){
                int leftIdx = s[left] - 'a';
                freq[leftIdx]--;
                
                if(freq[leftIdx] == 0)
                    distinct--;
                
                left++;
            }
            
            // Update answers when exactly k distinct 
            if(distinct == k){
                maxLen = max(maxLen, right - left + 1);
            }
        }
        return maxLen;
    }
};

/*
Question: Given a string s and an integer k, find the length of the longest substring that contains exactly k distinct characters. 
If there is no such substring, return -1.

Example 1:
Input: s = "abcba", k = 2
Output: 3
Explanation: The longest substring with exactly 2 distinct characters is "bcb", which has a length of 3.

Example 2:
Input: s = "aa", k = 1
Output: 2
Explanation: The longest substring with exactly 1 distinct character is "aa", which has a length of 2.

Example 3:
Input: s = "abc", k = 4
Output: -1
Explanation: There is no substring with exactly 4 distinct characters, so the output is -1.

Example 4:
Input: s = "aabaaab", k = 2
Output: 7
Explanation: The entire string "aabaaab" has exactly 2 unique characters 'a' and 'b', making it the longest valid substring.

============================================================================================
Approach 1 — Brute Force
Steps:
- Generate all substrings
- Check if it has k distinct characters
- Update answer
Time Complexity: O(N^3) (N^2 for generating substrings and O(N) for checking distinct characters)
============================================================================================
Approach 2 — Sliding Window (Optimal)
Steps:
- Use two pointers to maintain a sliding window
- Use a frequency array to count characters in the current window
- Expand the right pointer and update frequency
- If distinct characters exceed k, shrink the window from the left  
- Update the maximum length when exactly k distinct characters are present
Time Complexity: O(N)
Space Complexity: O(26) ≈ O(1) for the frequency array (assuming only lowercase letters)


🚀 Algorithm (Sliding Window)
-Expand right
-Increase frequency of character
-If frequency becomes 1 → new distinct character
-If distinct > k → shrink from left
-If distinct == k → update max length

| Type  | Complexity       |
| ----- | ---------------- |
| Time  | **O(n)**         |
| Space | **O(26) ≈ O(1)** |




*/