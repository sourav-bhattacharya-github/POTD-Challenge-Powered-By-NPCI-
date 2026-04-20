// Link: https://www.geeksforgeeks.org/problems/dearrangement-of-balls0918/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDerangements(int n) {
        if (n == 1) return 0;
        if (n == 2) return 1;

        int prev2 = 0; // D(1)
        int prev1 = 1; // D(2)

        for (int i = 3; i <= n; i++) {
            int curr = (i - 1) * (prev1 + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

int main() {
    int n;
    cin >> n;
    Solution ob;
    cout << ob.countDerangements(n) << endl;
    return 0;
}

/*
Question: Given a positive integer n, count the number of derangements of n distinct items. A derangement is a permutation of the elements of a set such that no element appears in its original position.

Example 1:
Input: n = 3
Output: 2
Explanation: The derangements of 3 items are:
1. (2, 3, 1)
2. (3, 1, 2)


Example 2:
Input: n = 4
Output: 9
Explanation: The derangements of 4 items are:
1. (2, 1, 4, 3)
2. (2, 3, 4, 1)
3. (2, 4, 1, 3)
4. (3, 1, 4, 2)
5. (3, 4, 1, 2) 
6. (3, 4, 2, 1)
7. (4, 1, 2, 3)
8. (4, 2, 1, 3)
9. (4, 3, 1, 2)

Note: The answer can be large, so return the result modulo 10^9 + 7.
======================================================================================

Approach:
1. We can use dynamic programming to solve this problem efficiently.
2. We define a function D(n) that returns the number of derangements of n items.
3. The base cases are:
   - D(1) = 0 (there's only one item, and it cannot be deranged)
   - D(2) = 1 (the only derangement is swapping the two items)
4. For n > 2, we can derive the following recurrence relation:
   D(n) = (n - 1) * (D(n - 1) + D(n - 2))
5. We can use a loop to fill in the values of D(n) from 3 to n, while keeping track of the last two computed values to save space.

Time Complexity: O(n)
Space Complexity: O(1) (since we only store the last two values of D(n)).

Dry Run:
Input: n = 4
1. D(1) = 0, D(2) = 1, prev1 = 1, prev2 = 0
2. For i = 3: curr = (3 - 1) * (prev1 + prev2) = 2 * (1 + 0) = 2, update prev2 = 1, prev1 = 2
3. For i = 4: curr = (4 - 1) * (prev1 + prev2) = 3 * (2 + 1) = 9, update prev2 = 2, prev1 = 9
4. Return prev1 = 9, which is the number of derangements for n = 4.

If n = 3:
1. D(1) = 0, D(2) = 1, prev1 = 1, prev2 = 0
2. For i = 3: curr = (3 - 1) * (prev1 + prev2) = 2 * (1 + 0) = 2, update prev2 = 1, prev1 = 2
3. Return prev1 = 2, which is the number of derangements for n = 3.



*/