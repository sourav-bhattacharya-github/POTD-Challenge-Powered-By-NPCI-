// Link: https://www.geeksforgeeks.org/problems/number-of-bst-from-array/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countBSTs(vector<int> &arr)
    {
        // Code here
        int n = arr.size();

        vector<int> original = arr;

        sort(arr.begin(), arr.end());

        vector<long long> dp(n + 1, 0);
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            int L = i, R = n - i - 1;

            mp[arr[i]] = dp[L] * dp[R];
        }

        vector<int> ans;

        for (int x : original)
        {
            ans.push_back(mp[x]);
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {10, 20, 30};
    vector<int> result = sol.countBSTs(arr);

    for (int count : result)
    {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}

/*
Question: Given an array of unique integers, count the number of Binary Search Trees (BSTs) that can be formed with each element as the root. Return the counts in the same order as the input array.

Example 1:
Input: arr = [10, 20, 30]
Output: [2, 1, 2]
Explanation:
- For root 10: Left subtree can be empty (1 way) and right subtree can be formed with 20 and 30 (2 ways), so total = 1 * 2 = 2.
- For root 20: Left subtree can be formed with 10 (1 way) and right subtree can be formed with 30 (1 way), so total = 1 * 1 = 1.
- For root 30: Left subtree can be formed with 10 and 20 (2 ways) and right subtree can be empty (1 way), so total = 2 * 1 = 2.

Example 2:
Input: arr = [5, 15, 25]
Output: [2, 1, 2]
Explanation:
- For root 5: Left subtree can be empty (1 way) and right subtree can be formed with 15 and 25 (2 ways), so total = 1 * 2 = 2.
- For root 15: Left subtree can be formed with 5 (1 way) and right subtree can be formed with 25 (1 way), so total = 1 * 1 = 1.
- For root 25: Left subtree can be formed with 5 and 15 (2 ways) and right subtree can be empty (1 way), so total = 2 * 1 = 2.

Example 3:
Input: arr = [1, 2, 3, 4]
Output: [5, 2, 2, 5]
Explanation:
- For root 1: Left subtree can be empty (1 way) and right subtree can be formed with 2, 3, and 4 (5 ways), so total = 1 * 5 = 5.
- For root 2: Left subtree can be formed with 1 (1 way) and right subtree can be formed with 3 and 4 (2 ways), so total = 1 * 2 = 2.
- For root 3: Left subtree can be formed with 1 and 2 (2 ways) and right subtree can be formed with 4 (1 way), so total = 2 * 1 = 2.
- For root 4: Left subtree can be formed with 1, 2, and 3 (5 ways) and right subtree can be empty (1 way), so total = 5 * 1 = 5.

=====================================================================================================================

Approach:
1. We can use dynamic programming to count the number of BSTs that can be formed with a given number of nodes. The number of unique BSTs that can be formed with 'n' nodes is given by the nth Catalan number, which can be calculated using the formula:
   C(n) = (2n)! / ((n + 1)! * n!)
   Alternatively, we can use a dynamic programming approach to compute the number of BSTs for all numbers from 0 to n.
2. We will create a dp array where dp[i] will store the number of unique BSTs that can be formed with 'i' nodes.
3. We will fill the dp array using the following relation:
   dp[i] = sum(dp[j] * dp[i - j - 1]) for j from 0 to i-1
4. After filling the dp array, we will create a mapping of each element in the input array to the number of BSTs that can be formed with that element as the root. This can be calculated as:
   For each element arr[i], the number of BSTs with arr[i] as root will be dp[i] * dp[n - i - 1], where dp[i] is the number of BSTs that can be formed with the left subtree (elements less than arr[i]) and dp[n - i - 1] is the number of BSTs that can be formed with the right subtree (elements greater than arr[i]).
5. Finally, we will return the counts in the same order as the input array.

| Type  | Complexity |
| ----- | ---------- |
| Time  | O(n²)      |
| Space | O(n)       |

*/