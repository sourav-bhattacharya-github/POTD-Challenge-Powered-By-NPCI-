// Link: https://www.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool areIsomorphic(string &s1, string &s2)
    {
        // code here
        vector<int> m1(26, -1), m2(26, -1);

        for (int i = 0; i < s1.size(); i++)
        {
            int ch1 = s1[i] - 'a';
            int ch2 = s2[i] - 'a';

            // new character
            if (m1[ch1] == -1 && m2[ch2] == -1)
            {
                m1[ch1] = ch2;
                m2[ch2] = ch1;
            }
            // Check the existing charters
            else if (m1[ch1] != ch2 || m2[ch2] != ch1)
            {
                return false;
            }
        }

        return true;
    }
};

/*
Question: Given two strings s1 and s2, determine if they are isomorphic. Two strings are isomorphic if the characters in s1 can be replaced to get s2. All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

Example 1:
Input: s1 = "egg", s2 = "add"
Output: true
Explanation: 'e' can be replaced with 'a' and 'g' can be replaced with 'd'.

Example 2:
Input: s1 = "foo", s2 = "bar"
Output: false
Explanation: 'o' cannot be replaced with two different characters.
Example 3:
Input: s1 = "paper", s2 = "title"
Output: true
Explanation: 'p' can be replaced with 't', 'a' can be replaced with 'i', 'e' can be replaced with 'l', and 'r' can be replaced with 'e'.

Short notes:
1. We can use two maps (or arrays) to keep track of the character mappings from s1 to s2 and from s2 to s1. This way, we can ensure that the mapping is consistent in both directions.
2. We iterate through both strings simultaneously, checking the mappings for each character. If we encounter a new character, we create the mapping. If we encounter an existing character, we check if the mapping is consistent. If any inconsistency is found, we return false.
3. If we successfully iterate through both strings without finding any inconsistencies, we return true, indicating that the strings are isomorphic.

*/