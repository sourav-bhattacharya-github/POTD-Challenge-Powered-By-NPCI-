// Link: https://www.geeksforgeeks.org/problems/flip-bits0240/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxOnes(vector<int> &arr)
    {
        // code here
        int n = arr.size();

        int totalOnes = 0;

        // Count the total number of 1s in the original array
        for (int x : arr)
        {
            if (x == 1)
                totalOnes++;
        }

        // We will use a modified version of Kadane's algorithm to find the maximum sum subarray
        int currSum = 0, maxSum = 0;

        for (int i = 0; i < n; i++)
        {
            int val = (arr[i] == 0) ? 1 : -1;

            currSum = max(val, currSum + val);
            maxSum = max(maxSum, currSum);
        }

        return totalOnes + maxSum;
    }
};

int main()
{
    Solution sol;
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int res = sol.maxOnes(arr);
    cout << res << endl;

    return 0;
}

/*
Question: Given a binary array arr of size n, you can flip at most one subarray. Flipping a subarray means changing all 0s to 1s and all 1s to 0s in that subarray. Your task is to find the maximum number of 1s that can be obtained in the array after flipping at most one subarray.

Example 1:
Input: arr = [1, 0, 0, 1, 0]
Output: 4
Explanation: By flipping the subarray from index 1 to index 2, we can change the array to [1, 1, 1, 1, 0], which contains 4 ones.

Example 2:
Input: arr = [1, 1, 1]
Output: 3
Explanation: No matter which subarray we flip, we cannot increase the number of ones. The maximum number of ones remains 3.

Example 3:
Input: arr = [0, 0, 0]
Output: 3
Explanation: By flipping the entire array, we can change it to [1, 1, 1], which contains 3 ones.

==================================================================================================================
Approach:
1. First, count the total number of 1s in the original array and store it in a variable totalOnes.
2. We will use a modified version of Kadane's algorithm to find the maximum sum subarray, where we treat 0s as +1 (since flipping a 0 to 1 increases the count of 1s) and 1s as -1 (since flipping a 1 to 0 decreases the count of 1s).
3. Initialize two variables currSum and maxSum to 0. Iterate through the array, and for each element, calculate the value val as 1 if the element is 0, and -1 if the element is 1.
4. Update currSum as the maximum of val and currSum + val. This step ensures that we are always considering the best possible subarray to flip.
5. Update maxSum as the maximum of maxSum and currSum. This will give us the maximum increase in the number of 1s that we can achieve by flipping a subarray.
6. Finally, return the sum of totalOnes and maxSum, which represents the maximum number of 1s that can be obtained after flipping at most one subarray.

    Time Complexity: O(n), where n is the size of the input array, since we need to iterate through the array to count the total number of 1s and to find the maximum sum subarray.

    Space Complexity: O(1), since we are using only a constant amount of extra space to store the variables.


    Dry Run:
    Input: arr = [1, 0, 0, 1, 0]
    totalOnes = 2 (counting the 1s in the original array)
    Iteration 1: i = 0, val = -1 (since arr[0] is 1)
        currSum = max(-1, 0 + (-1)) = -1
        maxSum = max(0, -1) = 0
    Iteration 2: i = 1, val = 1 (since arr[1] is 0)
        currSum = max(1, -1 + 1) = 1
        maxSum = max(0, 1) = 1
    Iteration 3: i = 2, val = 1 (since arr[2] is 0)
        currSum = max(1, 1 + 1) = 2
        maxSum = max(1, 2) = 2
    Iteration 4: i = 3, val = -1 (since arr[3] is 1)
        currSum = max(-1, 2 + (-1)) = 1
        maxSum = max(2, 1) = 2
    Iteration 5: i = 4, val = 1 (since arr[4] is 0)
        currSum = max(1, 1 + 1) = 2
        maxSum = max(2, 2) = 2
    Final result = totalOnes + maxSum = 2 + 2 = 4



*/