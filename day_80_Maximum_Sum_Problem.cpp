// Link: https://www.geeksforgeeks.org/problem-of-the-day

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<long long, long long> dp;

    long long solve(long long n)
    {

        // Base case
        if (n == 0)
            return 0;

        // Already computed
        if (dp.count(n))
            return dp[n];

        long long breakValue =
            solve(n / 2) +
            solve(n / 3) +
            solve(n / 4);

        // Take maximum
        return dp[n] =
                   max(n, breakValue);
    }

    long long maxSum(long long n)
    {

        return solve(n);
    }
};

int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        long long n;
        cin >> n;

        Solution ob;
        cout << ob.maxSum(n) << "\n";
    }

    return 0;
}

/*
Question: Given a number n, find the maximum sum of numbers that can be obtained by breaking the number into parts. The parts are obtained by dividing the number by 2, 3 and 4. The process is repeated for the obtained parts until we get 0 or 1.

Example 1:
Input: n = 12
Output: 13
Explanation: We can break 12 into 6, 4 and 3. Now we can break 6 into 3, 2 and 1. We can break 4 into 2, 1 and 1. We can break 3 into 1, 1 and 0. So the sum is 3 + 2 + 1 + 2 + 1 + 1 + 1 + 1 = 13.

Example 2:
Input: n = 2
Output: 2
Explanation: We can break 2 into 1, 0 and 0. So the sum is 1 + 0 + 0 = 1. But we can also take the number itself which is 2. So the maximum sum is 2.

Constraints:
1 ≤ n ≤ 10^9

===========================================================================================

Approach:
1. We can use a recursive approach to solve this problem. We will define a function `solve(n)` that will return the maximum sum that can be obtained by breaking the number `n` into parts.
2. The base case for the recursion will be when `n` is 0 or 1, in which case we will return `n` itself.
3. For any other value of `n`, we will break it into three parts: `n/2`, `n/3` and `n/4`. We will then recursively call the `solve` function for each of these parts and sum up the results.
4. We will also compare the sum obtained by breaking the number with the number itself and return the maximum of the two.
5. To optimize the solution, we can use memoization to store the results of previously computed values of `n` in a hash map. This will avoid redundant calculations and improve the performance of the solution.

Time Complexity: O(log n) due to the recursive calls and memoization.
Space Complexity: O(log n) due to the recursive call stack and the hash map used for memoization.

Dry Run:
Input: n = 12
1. We call `solve(12)`.
2. Since `n` is not 0 or 1, we break it into parts: `6`, `4` and `3`.
3. We call `solve(6)`.
4. Since `n` is not 0 or 1, we break it into parts: `3`, `2` and `1`.
5. We call `solve(3)`.
6. Since `n` is not 0 or 1, we break it into parts: `1`, `1` and `0`.
7. We call `solve(1)`, which returns `1`.
8. We call `solve(1)`, which returns `1`.
9. We call `solve(0)`, which returns `0`.
10. The sum for `n = 3` is `1 + 1 + 0 = 2`. We compare it with `3` and return `3`.
11. We call `solve(2)`.
12. Since `n` is not 0 or 1, we break it into parts: `1`, `0` and `0`.
13. We call `solve(1)`, which returns `1`.
14. We call `solve(0)`, which returns `0`.
15. We call `solve(0)`, which returns `0`.
16. The sum for `n = 2` is `1 + 0 + 0 = 1`. We compare it with `2` and return `2`.
17. We call `solve(1)`, which returns `1`.
18. The sum for `n = 6` is `3 + 2 + 1 = 6`. We compare it with `6` and return `6`.
19. We call `solve(4)`.
20. Since `n` is not 0 or 1, we break it into parts: `2`, `1` and `1`.
21. We call `solve(2)`, which returns `2`.
22. We call `solve(1)`, which returns `1`.
23. We call `solve(1)`, which returns `1`.
24. The sum for `n = 4` is `2 + 1 + 1 = 4`. We compare it with `4` and return `4`.
25. We call `solve(3)`, which returns `3`.
26. The sum for `n = 12` is `6 + 4 + 3 = 13`. We compare it with `12` and return `13` as the final answer.


Tree Diagram:
                12
              /  |  \
             6   4   3
           / | \   /|\
          3  2 1 2 1 1
         /|\ /|\ /|\
        1 1 0 1 0 0


*/