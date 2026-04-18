// Link: https://www.geeksforgeeks.org/problems/anagram-palindrome4720/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFormPalindrome(string &s)
    {

        int freq[26] = {0};

        for (char ch : s)
        {
            freq[ch - 'a']++;
        }

        int oddCount = 0;

        for (int x : freq)
        {
            if (x % 2 != 0)
            {
                oddCount++;
            }
        }

        return oddCount <= 1;
    }
};

int main()
{
    Solution sol;
    string s;
    getline(cin, s);

    bool res = sol.canFormPalindrome(s);
    cout << (res ? "true" : "false") << endl;

    return 0;
}

/*
Question: Given a string s, determine if any anagram of s can be a palindrome.

Example 1:
Input: s = "aaabbbb"
Output: true
Explanation: An anagram of s is "bbaaaba", which is a palindrome.

Example 2:
Input: s = "cdefghmnopqrstuvw"
Output: false
Explanation: No anagram of s can be a palindrome.

Example 3:
Input: s = "cdcdcdcdeeeef"
Output: true
Explanation: An anagram of s is "dcdcdcdeeeefc", which is a palindrome.

==================================================================================================================
Approach:
1. Create an array freq of size 26 to count the frequency of each character in the string s.
2. Iterate through each character ch in the string s and increment the corresponding frequency in the freq array.
3. Initialize a variable oddCount to 0 to keep track of the number of characters that have an odd frequency.
4. Iterate through the freq array and for each frequency x, check if it is odd (x % 2 != 0). If it is odd, increment the oddCount.
5. Finally, return true if oddCount is less than or equal to 1, indicating that at most one character has an odd frequency, which is a necessary condition for an anagram of s to be a palindrome. Otherwise, return false.

    Time Complexity: O(n), where n is the length of the input string s, since we need to iterate through the string to count the frequencies and then iterate through the frequency array.
Space Complexity: O(1), since the frequency array has a fixed size of 26, regardless of the input string length.



Dry Run:
Input: s = "aaabbbb"
1. Initialize freq[26] = {0}.
2. Iterate through s:
   - 'a': freq[0] = 1
   - 'a': freq[0] = 2
   - 'a': freq[0] = 3
   - 'b': freq[1] = 1
   - 'b': freq[1] = 2
   - 'b': freq[1] = 3
   - 'b': freq[1] = 4
3. Initialize oddCount = 0.
4. Iterate through freq:
   - freq[0] = 3 (odd): oddCount = 1
   - freq[1] = 4 (even): oddCount = 1
5. Return true if oddCount <= 1, otherwise false.

Input: s = "cdefghmnopqrstuvw"
1. Initialize freq[26] = {0}.
2. Iterate through s:
   - 'c': freq[2] = 1
   - 'd': freq[3] = 1
   - 'e': freq[4] = 1
   - 'f': freq[5] = 1
   - 'g': freq[6] = 1
   - 'h': freq[7] = 1
   - 'm': freq[12] = 1
   - 'n': freq[13] = 1
   - 'o': freq[14] = 1
   - 'p': freq[15] = 1
   - 'q': freq[16] = 1
   - 'r': freq[17] = 1
   - 's': freq[18] = 1
   - 't': freq[19] = 1
   - 'u': freq[20] = 1
   - 'v': freq[21] = 1
   - 'w': freq[22] = 1
3. Initialize oddCount = 0.
4. Iterate through freq:
   - All frequencies are 1 (odd): oddCount = 17
5. Return true if oddCount <= 1, otherwise false.


*/