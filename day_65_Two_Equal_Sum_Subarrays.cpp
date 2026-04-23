// Link: https://www.geeksforgeeks.org/problems/split-an-array-into-two-equal-sum-subarrays/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canSplit(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        long long totalSum = 0;

        // Calculate the total sum of the array
        for (int x : arr)
        {
            totalSum += x;
        }

        // If the total sum is odd, we cannot split it into two equal parts
        if (totalSum % 2 != 0)
        {
            return false;
        }

        long long target = totalSum / 2;
        long long prefixSum = 0;

        // Iterate through the array and keep adding to the prefix sum
        for (int i = 0; i < n; i++)
        {
            prefixSum += arr[i];

            if (prefixSum == target)
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution ob;
    bool result = ob.canSplit(arr);

    cout << (result ? "Yes" : "No") << endl;

    return 0;
}

/*
Question: Given an array of integers, determine if it can be split into two subarrays such that the sum of the elements in both subarrays is equal.

Example 1:
Input:
n = 5
arr[] = [1, 2, 3, 4, 5]
Output: No
Explanation: The total sum of the array is 15, which is odd. Therefore, it cannot be split into two equal sum subarrays.

Example 2:
Input:
n = 6
arr[] = [1, 2, 3, 4, 5, 5]
Output: true
Explanation: We can divide the array into [1, 2, 3, 4] and [5, 5]. The sum of both the subarrays are 10.

Constraints:
1 <= n <= 10^5
1 <= arr[i] <= 10^9

=================================================================================================================================
Approach:
1. Calculate the total sum of the array.
2. If the total sum is odd, return false immediately since it cannot be split into two equal parts.
3. If the total sum is even, we need to check if there exists a prefix of the array that sums up to half of the total sum.
4. We can iterate through the array while maintaining a running prefix sum. If at any point the prefix sum equals half of the total sum, we can return true.

Time Complexity: O(n) for calculating the total sum and checking the prefix sums.
Space Complexity: O(1) since we are using only a few variables to store sums and the target.

Dry Run:
Input: arr = [1, 2, 3, 4, 5, 5]
- totalSum = 1 + 2 + 3 + 4 + 5 + 5 = 20
- totalSum is even, so we proceed.
- target = totalSum / 2 = 10
- prefixSum = 0
- i = 0: prefixSum = 1 (not equal to target)
- i = 1: prefixSum = 3 (not equal to target)
- i = 2: prefixSum = 6 (not equal to target)
- i = 3: prefixSum = 10 (equal to target) -> return true




*/