// Link: https://www.geeksforgeeks.org/problems/count-increasing-subarrays5301/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countIncreasingSubarrays(vector<int> &arr)
    {
        int n = arr.size();
        int count = 0;
        int len = 1;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[i - 1])
            {
                len++;
            }
            else
            {
                // count subarrays in the current segment by using the formula n*(n-1)/2 for the number of ways to choose 2 elements from len
                count += (len * (len - 1)) / 2;
                len = 1;
            }
        }

        // last segment
        count += (len * (len - 1)) / 2;

        return count;
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
    cout << sol.countIncreasingSubarrays(arr) << endl;
    return 0;
}

/*
Question: Count Increasing Subarrays
Given an array of integers, count the number of increasing subarrays. An increasing subarray is defined as a contiguous sequence of elements where each element is greater than the previous one.

Example:
Input: arr = [1, 2, 3, 4]
Output: 10
Explanation: The increasing subarrays are:
[1], [2], [3], [4], [1, 2], [2, 3], [3, 4], [1, 2, 3], [2, 3, 4], [1, 2, 3, 4]

Input: arr = [1, 1, 1]
Output: 3
Explanation: The increasing subarrays are:
[1], [1], [1]

Input: arr = [1, 2, 1, 3]
Output: 5
Explanation: The increasing subarrays are:
[1], [2], [1], [3], [2, 3]

Constraints:
1 <= arr.length <= 10^5
-10^9 <= arr[i] <= 10^9

Note: The subarrays should be contiguous, meaning that the elements must be adjacent to each other in the original array.

================================================================================================================
Approach:
1. Initialize a variable `count` to store the total count of increasing subarrays and a variable `len` to keep track of the length of the current increasing segment.
2. Iterate through the array starting from the second element:
   - If the current element is greater than the previous element, increment `len` by 1.
   - If the current element is not greater than the previous element, it means the increasing segment has ended. Calculate the number of increasing subarrays in this segment using the formula `len * (len - 1) / 2` and add it to `count`. Reset `len` to 1 for the next segment.
3. After the loop, there may be a remaining increasing segment that needs to be counted. Calculate the number of increasing subarrays for this last segment and add it to `count`.
4. Return the total count of increasing subarrays.

Time Complexity: O(n), where n is the length of the input array, since we traverse the array once.
Space Complexity: O(1), as we are using only a constant amount of extra space for the variables.

Dry Run:
Input: arr = [1, 2, 1, 3]
- Initialize count = 0, len = 1
- i = 1: arr[1] > arr[0] (2 > 1), len = 2
- i = 2: arr[2] > arr[1] (1 > 2) is false, count += (2 * 1) / 2 = 1, len = 1
- i = 3: arr[3] > arr[2] (3 > 1), len = 2
- End of loop, count += (2 * 1) / 2 = 1
- Total count = 1 (from first segment) + 1 (from second segment) + 3 (individual elements) = 5


*/