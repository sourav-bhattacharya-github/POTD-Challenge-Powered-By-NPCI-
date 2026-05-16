// Link: https://www.geeksforgeeks.org/problems/smallest-number-subset1220/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findSmallest(vector<int> &arr)
    {
        // code here.
        sort(arr.begin(), arr.end());

        long long reachable = 0;

        for (int num : arr)
        {
            if (num > reachable + 1)
            {
                return reachable + 1;
            }

            reachable += num;
        }

        return reachable + 1;
    }
};

int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.findSmallest(arr) << "\n";
    }

    return 0;
}

/*
Question: Given an array of positive integers, find the smallest positive integer value that cannot be represented as sum of elements of any subset of given set.

Example 1:
Input: arr[] = {1, 2, 3, 8}
Output: 7
Explanation: We can make numbers from 1 to 6 using elements of the array. But 7 cannot be made using elements of the array.

Example 2:
Input: arr[] = {1, 1, 1, 1}
Output: 5
Explanation: We can make numbers from 1 to 4 using elements of the array. But 5 cannot be made using elements of the array.

Example 3:
Input: arr[] = {1, 2, 5, 10, 20, 40}
Output: 4
Explanation: We can make numbers from 1 to 3 using elements of the array. But 4 cannot be made using elements of the array.

Constraints:
1 ≤ n ≤ 10^5
1 ≤ arr[i] ≤ 10^9

===========================================================================
Approach: Sorting + Greedy
1. Sort the array in non-decreasing order.
2. Initialize a variable reachable to 0, which will keep track of the largest number that can be formed using the elements seen so far.
3. Iterate through the sorted array:
    a. For each element num in the array, check if it is greater than reachable + 1. If it is, then we cannot form the number reachable + 1 using the elements seen so far, and we can return reachable + 1 as the answer.
    b. If num is less than or equal to reachable + 1, then we can update reachable by adding num to it, which means we can now form all numbers from 1 to reachable + num.
4. If we finish iterating through the array without finding any gaps, then the smallest positive integer that cannot be formed is reachable + 1.

Time Complexity: O(n log n) due to sorting, where n is the size of the input array.
Space Complexity: O(1) for the extra space used, as we are modifying the input array in place and using only a constant amount of additional space for variables.

Dry run:
Input: arr[] = {1, 2, 3, 8}
1. Sort the array: arr[] = {1, 2, 3, 8}
2. Initialize reachable = 0
3. Iterate through the sorted array:
    a. num = 1: 1 <= reachable + 1 (0 + 1), so update reachable = reachable + num = 0 + 1 = 1
    b. num = 2: 2 <= reachable + 1 (1 + 1), so update reachable = reachable + num = 1 + 2 = 3
    c. num = 3: 3 <= reachable + 1 (3 + 1), so update reachable = reachable + num = 3 + 3 = 6
    d. num = 8: 8 > reachable + 1 (6 + 1), so we cannot form the number reachable + 1 (7) using the elements seen so far, and we return reachable + 1 = 7 as the answer.





*/