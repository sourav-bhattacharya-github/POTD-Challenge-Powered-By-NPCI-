// Link:https://www.geeksforgeeks.org/problems/sum-of-subarray-minimum/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumSubMins(vector<int> &arr)
    {
        // code here
        int n = arr.size();

        vector<int> left(n), right(n);
        stack<int> st;

        // Previous smaller element
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            if (st.empty())
                left[i] = i + 1;
            else
                left[i] = i - st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // next smaller elemnt
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            if (st.empty())
                right[i] = n - i;
            else
                right[i] = st.top() - i;

            st.push(i);
        }

        long long sum = 0;

        for (int i = 0; i < n; i++)
            sum += (long long)arr[i] * left[i] * right[i];

        return sum;
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.sumSubMins(arr) << endl;
    }

    return 0;
}

/*
QUESTION: Given an array of integers, find the sum of minimum elements of all subarrays.

Example 1:
Input: arr = [3,1,2,4]
Output: 17
Explanation: The subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. The minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1. Sum is 17.

Example 2:
Input: arr = [11,81,94,43,3]
Output: 444
Explanation: The subarrays are [11], [81], [94], [43], [3], [11,81], [81,94], [94,43], [43,3], [11,81,94], [81,94,43], [94,43,3], [11,81,94,43], [81,94,43,3], [11,81,94,43,3]. The minimums are 11, 81, 94, 43, 3, 11, 81, 43, 3, 11, 43, 3, 11, 3. Sum is 444.
====================================================================================================================
Brute Force Approach:
1. Generate all possible subarrays of the given array.
2. For each subarray, find the minimum element and add it to the sum.
Time Complexity: O(n^3) due to three nested loops for generating subarrays and finding minimums.
====================================================================================================================
Optimal Approach:
1. Use a stack to keep track of the indices of the elements in the array.
2. For each element, find the previous smaller element and the next smaller element using the stack
3. Calculate the contribution of each element to the sum using the formula: arr[i] * left[i] * right[i], where left[i] is the distance to the previous smaller element and right[i] is the distance to the next smaller element.
Time Complexity: O(n) due to a single pass through the array to find previous and next smaller elements, and another pass to calculate the sum.

Dry Run:
Input: arr = [3,1,2,4]
1. For element 3:
   - Previous smaller: None (left[0] = 1)
   - Next smaller: 1 (right[0] = 2)
   - Contribution: 3 * 1 * 2 = 6
2. For element 1:
   - Previous smaller: None (left[1] = 2)
   - Next smaller: None (right[1] = 4)
   - Contribution: 1 * 2 * 4 = 8
3. For element 2:
   - Previous smaller: 1 (left[2] = 1)
   - Next smaller: None (right[2] = 2)
   - Contribution: 2 * 1 * 2 = 4
4. For element 4:
   - Previous smaller: 2 (left[3] = 1)
   - Next smaller: None (right[3] = 1)
   - Contribution: 4 * 1 * 1 = 4
Total Sum = 6 + 8 + 4 + 4 = 22


*/