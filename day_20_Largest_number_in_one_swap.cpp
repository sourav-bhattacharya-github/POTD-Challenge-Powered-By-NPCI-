// Link: https://www.geeksforgeeks.org/problems/largest-number-in-one-swap1520/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestSwap(string &s)
    {
        int n = s.size();

        for (int i = 0; i < n; i++)
        {

            char maxChar = s[i];
            int pos = -1;

            // find the largest character on right side
            for (int j = i + 1; j < n; j++)
            {
                if (s[j] >= maxChar)
                {
                    maxChar = s[j];
                    pos = j;
                }
            }

            // swap if larger character found
            if (pos != -1 && maxChar > s[i])
            {
                swap(s[i], s[pos]);
                break;
            }
        }

        return s;
    }
};

/*
Question: Given a string representing a number, find the largest number that can be formed by swapping at most two digits.

Example 1:
Input: s = "2736"
Output: "7236"
Explanation: Swap the digit '2' with the digit '7' to get the largest number.

Example 2:
Input: s = "9973"
Output: "9973"
Explanation: No swap can increase the number, so we return the original number.

====================================================================================================================
Brute Force Approach:
1. Generate all possible combinations of two digits in the string and swap them.
2. Keep track of the maximum number obtained from these swaps.
Time Complexity: O(n^2) due to two nested loops for generating combinations of digits.
====================================================================================================================
Optimal Approach:
1. Iterate through the string from left to right and for each digit, find the largest digit on its right side.
2. If a larger digit is found, swap it with the current digit and break the loop
Time Complexity: O(n) due to a single pass through the string and a nested loop to find the largest digit on the right side.


*/