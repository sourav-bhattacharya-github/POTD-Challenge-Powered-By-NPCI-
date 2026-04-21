// Link: https://www.geeksforgeeks.org/problems/two-water-jug-problem3402/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }

    int solve(int fromCap, int toCap, int d)
    {
        int from = 0, to = 0;
        int step = 0;

        while (from != d && to != d)
        {
            if (from == 0)
            {
                from = fromCap;
                step++;
            }
            else if (to == toCap)
            {
                to = 0;
                step++;
            }
            else
            {
                int pour = min(from, toCap - to);
                to += pour;
                from -= pour;
                step++;
            }
        }

        return step;
    }

    int minSteps(int m, int n, int d)
    {
        // Code here
        if (d > max(m, n) || d % gcd(m, n) != 0)
            return -1;

        return min(solve(m, n, d), solve(n, m, d));
    }
};

int main()
{
    int m, n, d;
    cin >> m >> n >> d;
    Solution ob;
    cout << ob.minSteps(m, n, d) << endl;
    return 0;
}

/*
Question: Given two jugs with capacities m and n litres, and an infinite amount of water supply, determine the minimum number of steps required to measure exactly d litres using these two jugs. The allowed operations are:

1. Fill any of the jugs completely with water.
2. Empty any of the jugs.
3. Pour water from one jug to the other until either the first jug is empty or the second jug is full.

Example 1:
Input: m = 3, n = 5, d = 4
Output: 6
Explanation:
1. Fill the 5-litre jug (5, 0)
2. Pour water from the 5-litre jug to the 3-litre jug (2, 3)
3. Empty the 3-litre jug (2, 0)
4. Pour water from the 5-litre jug to the 3-litre jug (0, 2)
5. Fill the 5-litre jug (5, 2)
6. Pour water from the 5-litre jug to the 3-litre jug (4, 3)
7. Now we have exactly 4 litres in the 5-litre jug.

Example 2:
Input: m = 2, n = 6, d = 5
Output: -1
Explanation: It is impossible to measure exactly 5 litres using the given jugs.

Note: The answer can be large, so return the result modulo 10^9 + 7.
======================================================================================
Approach:
1. The problem can be solved using the concept of the greatest common divisor (GCD). If d is greater than the maximum of m and n, or if d is not a multiple of the GCD of m and n, then it is impossible to measure d litres, and we return -1.
2. If it is possible to measure d litres, we can use a helper function to simulate the process of filling, emptying, and pouring water between the jugs. We will simulate the process twice: once starting with the first jug and once starting with the second jug, and take the minimum number of steps from both simulations.
3. The helper function will keep track of the current amount of water in both jugs and count the steps taken until we measure exactly d litres in either jug.
4. Finally, we return the minimum number of steps required to measure d litres.

Time Complexity: O(m + n) for the simulation, and O(log(min(m, n))) for calculating GCD, resulting in an overall efficient solution.
Space Complexity: O(1) since we are using only a constant amount of space to store the current state of the jugs and the step count.

Dry run:
Input: m = 3, n = 5, d = 4
1. Check if d > max(m, n) or d % gcd(m, n) != 0. Here, gcd(3, 5) = 1, and d = 4 is less than max(3, 5) and is a multiple of 1, so we proceed.
2. Simulate starting with the first jug (3-litre):
    - Fill the 5-litre jug: (0, 5), steps = 1
    - Pour from 5-litre to 3-litre: (2, 3), steps = 2
    - Empty the 3-litre jug: (2, 0), steps = 3
    - Pour from 5-litre to 3-litre: (0, 2), steps = 4
    - Fill the 5-litre jug: (5, 2), steps = 5
    - Pour from 5-litre to 3-litre: (4, 3), steps = 6 (we have d litres in the first jug)
3. Simulate starting with the second jug (5-litre):
    - Fill the 3-litre jug: (3, 0), steps = 1
    - Pour from 3-litre to 5-litre: (0, 3), steps = 2
    - Fill the 3-litre jug: (3, 3), steps = 3
    - Pour from 3-litre to 5-litre: (1, 5), steps = 4
    - Empty the 5-litre jug: (1, 0), steps = 5
    - Pour from 3-litre to 5-litre: (0, 1), steps = 6
    - Fill the 3-litre jug: (3, 1), steps = 7
    - Pour from 3-litre to 5-litre: (0, 4), steps = 8 (we have d litres in the second jug)
4. The minimum steps from both simulations is 6, so we return 6 as the answer.

Input: m = 2, n = 6, d = 5
1. Check if d > max(m, n) or d % gcd(m, n)
    Here, gcd(2, 6) = 2, and d = 5 is greater than max(2, 6) and is not a multiple of 2, so we return -1 as it is impossible to measure exactly 5 litres with the given jugs.
2. The output is -1, indicating that it is not possible to measure 5 litres with the given jugs.
*/