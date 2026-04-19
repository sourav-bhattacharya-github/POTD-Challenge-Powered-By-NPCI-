// Link: https://www.geeksforgeeks.org/problems/check-if-a-number-is-power-of-another-number5442/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPower(int x, int y)
    {
        // code here
        if (y == 1)
            return true; // x^ 0 = 1
        if (x == 1)
            return y == 1;

        // Divide logic
        while (y % x == 0)
        {
            y /= x;
        }

        return y == 1;

        /*
        //* Multiple logic
        long long power = x;

        while(power <= y){
            if(power == y)
                return true;

            power *= x;
        }
        return false;
        */
    }
};

int main()
{
    int x, y;
    cin >> x >> y;
    Solution ob;
    cout << ob.isPower(x, y) << endl;
    return 0;
}

/*
Question: Given two positive integers x and y, check if y is a power of x. A number y is a power of x if there exists an integer n such that x^n = y.

Example 1:
Input: x = 2, y = 8
Output: 1
Explanation: 2^3 = 8, so 8 is a power of 2.

Example 2:
Input: x = 1, y = 8
Output: 0
Explanation: Any power of 1 is 1, so 8 is not a power of 1.

Example 3:
Input: x = 10, y = 1000
Output: 1
Explanation: 10^3 = 1000.

Constraints:
1 <= x, y <= 10^9

==================================================================================================================
Approach:
1. Handle base cases:
   - If y is 1, return true because x^0 = 1 for any x.
   - If x is 1, return true only if y is 1 (already handled), otherwise return false.
2. Use a loop to repeatedly divide y by x as long as y is divisible by x.
3. After the loop, if y has been reduced to 1, it means y was a perfect power of x.
4. Alternatively, you can start with power = x and keep multiplying by x until you reach or exceed y.

Time Complexity: O(log_x(y)), as we divide y by x in each iteration.
Space Complexity: O(1), as we use no extra space.

Dry Run:
Input: x = 3, y = 9
1. y != 1 and x != 1.
2. 9 % 3 == 0, so y = 9 / 3 = 3.
3. 3 % 3 == 0, so y = 3 / 3 = 1.
4. y == 1, return true.

*/
