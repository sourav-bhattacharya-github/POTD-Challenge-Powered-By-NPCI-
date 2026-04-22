// Link: https://www.geeksforgeeks.org/problems/mean-of-range-in-array2123/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries)
    {
        // code here
        int n = arr.size();

        vector<long long> prefixSum(n);
        prefixSum[0] = arr[0];

        for (int i = 1; i < n; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        }

        vector<int> result;

        for (auto &q : queries)
        {
            int l = q[0], r = q[1];

            long long sum = (l == 0) ? prefixSum[r] : prefixSum[r] - prefixSum[l - 1];

            int len = r - l + 1;

            int mean = sum / len;

            result.push_back(mean);
        }

        return result;
    }
};

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<vector<int>> queries(q, vector<int>(2));
    for (int i = 0; i < q; i++)
    {
        cin >> queries[i][0] >> queries[i][1];
    }

    Solution ob;
    vector<int> result = ob.findMean(arr, queries);

    for (int mean : result)
    {
        cout << mean << " ";
    }
    cout << endl;

    return 0;
}

/*
Question: Given an array of integers and a list of queries, where each query consists of two integers representing the left and right indices of a range in the array, return a list of the mean (average) values for each range specified by the queries. The mean should be calculated as the sum of the elements in the range divided by the number of elements in that range, and the result should be an integer (floor of the mean if it's not an integer).

Example:
Input:
n = 5, q = 3
arr = [1, 2, 3, 4, 5]
queries = [[0, 2], [1, 3], [0, 4]]
Output:
2 3 3
Explanation:
For the first query [0, 2], the range is [1, 2, 3], and the mean is (1 + 2 + 3) / 3 = 2.
For the second query [1, 3], the range is [2, 3, 4], and the mean is (2 + 3 + 4) / 3 = 3.
For the third query [0, 4], the range is [1, 2, 3, 4, 5], and the mean is (1 + 2 + 3 + 4 + 5) / 5 = 3.

Note: The input format and output format are as follows:
- The first line contains two integers n and q, where n is the size of the array and q is the number of queries.
- The second line contains n space-separated integers representing the elements of the array.
- The next q lines each contain two space-separated integers representing the left and right indices of the range for each query.
Constraints:
1 <= n <= 10^5
1 <= q <= 10^5
1 <= arr[i] <= 10^9
0 <= left <= right < n

===============================================================================================================
Approach:
1. We can use a prefix sum array to efficiently calculate the sum of any range in O(1) time after O(n) preprocessing time.
2. We first create a prefix sum array where prefixSum[i] is the sum of the first i elements of the input array.
3. For each query, we can calculate the sum of the range [l, r] using the prefix sum array:
   - If l is 0, then the sum is simply prefixSum[r].
   - Otherwise, the sum is prefixSum[r] - prefixSum[l-1].
4. Finally, we calculate the mean by dividing the sum by the length of the range (r - l + 1) and store the result in the output list.
5. Return the list of mean values for all queries.

Time Complexity: O(n + q) where n is the size of the array and q is the number of queries.
Space Complexity: O(n) for the prefix sum array and O(q) for the result list.

Dry run:
Input:
n = 5, q = 3
arr = [1, 2, 3, 4, 5]
queries = [[0, 2], [1, 3], [0, 4]]
Output: 2 3 3
1. We first compute the prefix sum array:
   prefixSum[0] = 1
   prefixSum[1] = 1 + 2 = 3
   prefixSum[2] = 3 + 3 = 6
   prefixSum[3] = 6 + 4 = 10
   prefixSum[4] = 10 + 5 = 15
   So, prefixSum = [1, 3, 6, 10, 15]

2. For the first query [0, 2]:
   sum = prefixSum[2] = 6
    mean = 6 / (2 - 0 + 1) = 6 / 3 = 2
3. For the second query [1, 3]:
   sum = prefixSum[3] - prefixSum[0] = 10 - 1 = 9
   mean = 9 / (3 - 1 + 1) = 9 / 3 = 3
4. For the third query [0, 4]:
   sum = prefixSum[4] = 15
   mean = 15 / (4 - 0 + 1) = 15 / 5 = 3
5. The final output is [2, 3, 3], which matches the expected output.



*/