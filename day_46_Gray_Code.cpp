// Link: https://www.geeksforgeeks.org/problems/gray-code-1611215248/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> grayCode(int n)
    {
        vector<string> result;

        for (int i = 0; i < (1 << n); i++)
        { // Total 2^n codes

            int gray = i ^ (i >> 1); // Generate the Gray code for the current number

            string binary = "";
            for (int j = n - 1; j >= 0; j--)
            { // Convert the Gray code to its binary representation

                if (gray & (1 << j)) // Check if the j-th bit is set in the Gray code
                {
                    binary += '1'; // If the bit is set, append '1' to the binary string
                }
                else
                {
                    binary += '0'; // If the bit is not set, append '0' to the binary string
                }
            }

            result.push_back(binary); // Add the binary string representation of the Gray code to the result vector
        }

        return result;
    }
};

int main()
{
    Solution sol;
    int n = 2;
    vector<string> result = sol.grayCode(n);
    for (const string &code : result)
    {
        cout << code << " ";
    }
    cout << endl; // Output: 00 01 11 10
    return 0;
}

/*
Question: Given a non-negative integer n, generate the sequence of Gray codes for n bits. The Gray code is a binary numeral system where two successive values differ in only one bit.

Example:
Input: n = 2
Output: ["00", "01", "11", "10"]
Explanation: The sequence of Gray codes for n = 2 is as follows:
00 (0 in decimal)
01 (1 in decimal)
11 (3 in decimal)
10 (2 in decimal)
The order of the codes is such that each code differs from the previous one by only one bit. For n = 2, the sequence is ["00", "01", "11", "10"].
===============================================================================================================
Approach:
1. The Gray code can be generated using the formula: Gray(i) = i ^ (i >> 1), where i is the integer representation of the code.
2. We can iterate from 0 to 2^n - 1, compute the Gray code for each integer, and convert it to its binary string representation.
3. The resulting binary strings can be stored in a vector and returned as the final output.

Time Complexity: O(n * 2^n) - We generate 2^n codes, and each code is converted to a binary string of length n.\
Space Complexity: O(n * 2^n) - We store 2^n codes, and each code is a binary string of length n.

Dry Run:
For n = 2:
i = 0: Gray(0) = 0 ^ (0 >> 1) = 0 -> "00"
i = 1: Gray(1) = 1 ^ (1 >> 1) = 1 ^ 0 = 1 -> "01"
i = 2: Gray(2) = 2 ^ (2 >> 1) = 2 ^ 1 = 3 -> "11"
i = 3: Gray(3) = 3 ^ (3 >> 1) = 3 ^ 1 = 2 -> "10"
The final output is ["00", "01", "11", "10"].


*/