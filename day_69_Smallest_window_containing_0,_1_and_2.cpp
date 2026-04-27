// Link: https://www.geeksforgeeks.org/problems/smallest-window-containing-0-1-and-2--170637/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestSubstring(string s)
    {
        // code here
        int n = s.size();

        vector<int> freq(3, 0);

        int left = 0;
        int ans = INT_MAX;

        for (int right = 0; right < n; right++)
        {
            freq[s[right] - '0']++;

            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0)
            {
                ans = min(ans, right - left + 1);

                freq[s[left] - '0']--;
                left++;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

int mian()
{
    string s;
    cin >> s;

    Solution ob;
    int res = ob.smallestSubstring(s);
    cout << res << endl;

    return 0;
}

/*
Question: Given a string s consisting of characters '0', '1', and '2', find the length of the smallest substring that contains at least one occurrence of each character. If no such substring exists, return -1.

Examples:
Input: s = "012"
Output: 3
Explanation: The entire string "012" contains all three characters '0', '1', and '2', so the length of the smallest substring is 3.

Input: s = "001122"
Output: 4
Explanation: The substring "0112" contains all three characters '0', '1', and '2', so the length of the smallest substring is 4.

Input: s = "000111"
Output: -1
Explanation: There is no substring that contains all three characters '0', '1', and '2', so the output is -1.

Constraints:
1 <= s.length <= 10^5
s consists of characters '0', '1', and '2' only.

=================================================================================================
Approach:
1. We can use a sliding window approach to find the smallest substring that contains all three characters '0', '1', and '2'.
2. We maintain a frequency array to count the occurrences of '0', '1', and '2' in the current window.
3. We expand the right pointer to include characters until we have at least one occurrence of each character.
4. Once we have a valid window, we try to shrink it from the left to find the smallest valid window.

Time Complexity: O(n), where n is the length of the string, since each character is processed at most twice (once when expanding the right pointer and once when shrinking the left pointer).
Space Complexity: O(1), since we are using a fixed-size frequency array of size 3 to count the occurrences of '0', '1', and '2'.

Dry Run:
Input: s = "001122"
- Initialize freq = [0, 0, 0], left = 0, ans = INT_MAX
- right = 0: freq = [1, 0, 0] (window: "0")
- right = 1: freq = [2, 0, 0] (window: "00")
- right = 2: freq = [2, 1, 0] (window: "001")
- right = 3: freq = [2, 1, 1] (window: "0011")
-right = 4: freq = [2, 1, 2] (window: "00112") - valid window, ans = 5
- Shrink from left: freq = [1, 1, 2] (window: "0112") - valid window, ans = 4
- Shrink from left: freq = [0, 1, 2] (window: "112") - not valid, stop shrinking
- right = 5: freq = [0, 2, 2] (window: "001122") - not valid, continue
- Final answer: 4 (the substring "0112")



*/