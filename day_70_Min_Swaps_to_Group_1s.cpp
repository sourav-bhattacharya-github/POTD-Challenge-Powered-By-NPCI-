// Link: https://www.geeksforgeeks.org/problems/minimum-swaps-required-to-group-all-1s-together2451/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwaps(vector<int> &arr)
    {
        // code here
        int ones = 0;

        for (int x : arr)
            ones += x;

        // If there are no 1s, then we don't need to swap anything
        if (ones == 0)
            return -1;

        int zeros = 0;

        for (int i = 0; i < ones; i++)
        {
            if (arr[i] == 0)
                zeros++;
        }

        int ans = zeros;
        int left = 0;

        for (int right = ones; right < arr.size(); right++)
        {
            if (arr[left] == 0)
                zeros--;
            left++;

            if (arr[right] == 0)
                zeros++;

            ans = min(ans, zeros);
        }

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Solution ob;
    int res = ob.minSwaps(arr);
    cout << res << endl;

    return 0;
}

/*
Question: Given a binary array arr of size n, find the minimum number of swaps required to group all 1s together in the array. If there are no 1s in the array, return -1.

Examples:

Input: arr = [1, 0, 1, 0, 1]
Output: 1
Explanation: We can swap the second 0 with the last 1 to group all 1s together, resulting in the array [1, 1, 1, 0, 0].

Input: arr = [0, 0, 0, 0]
Output: -1
Explanation: There are no 1s in the array, so we return -1.

Input: arr = [1, 1, 1, 1]
Output: 0
Explanation: All 1s are already grouped together, so we don't need to swap anything.


Constraints:
1 <= n <= 10^5
arr[i] is either 0 or 1.

==============================================================================================

Approach:
1. Count the total number of 1s in the array, let's call this count `ones`.
2. If `ones` is 0, return -1 since there are no 1s to group together.
3. Use a sliding window of size `ones` to count the number of 0s in the current window. The number of 0s in the window represents the number of swaps needed to group all 1s together in that window.
4. Initialize the answer with the number of 0s in the first window.
5. Slide the window across the array, updating the count of 0s and keeping track of the minimum number of swaps needed.
6. Return the minimum number of swaps found.

Time Complexity: O(n), where n is the size of the input array.
Space Complexity: O(1), since we are using a constant amount of extra space for counting.

Dry Run:
Input: arr = [1, 0, 1, 0, 1]
- Count of 1s (ones) = 3
- Initial window (first 3 elements): [1, 0, 1] -> zeros = 1, ans = 1
- Slide the window:
  - Move right pointer to index 3: [0, 1, 0] -> zeros = 2 (since we lose one 1 and gain one 0), ans = min(1, 2) = 1
  - Move right pointer to index 4: [1, 0, 1] -> zeros = 1 (since we lose one 0 and gain one 1), ans = min(1, 1) = 1
  - Final answer = 1


*/
