// Link: https://www.geeksforgeeks.org/problems/longest-span-with-same-sum-in-two-binary-arrays5142/1'

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        unordered_map<int, int> m;
        int sum = 0, maxlen = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i] - b[i];
            if (sum == 0)
                maxlen = i + 1;
            else if (m.find(sum) != m.end())
                maxlen = max(maxlen, i - m[sum]);
            else
                m[sum] = i;
        }
        cout << maxlen << endl;
    }
}

/*
Question: Given two binary arrays of same size, find the length of longest common span (i.e., subarray which has same sum in both arrays) with same sum.

Example 1:
Input:
N = 6
A[] = {0, 1, 0, 0, 0, 0}
B[] = {1, 0, 1, 0, 0, 1}
Output: 4
Explanation: The longest span with same sum is from index 1 to 4.

Example 2:
Input:
N = 6
A[] = {0, 1, 0, 1, 1, 1}
B[] = {1, 1, 1, 0, 1, 0}
Output: 3
Explanation: The longest span with same sum is from index 0 to 2.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestCommonSpan() which takes the two arrays A and B and their size N as input parameters and returns the length of longest common span with same sum.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 105

*/