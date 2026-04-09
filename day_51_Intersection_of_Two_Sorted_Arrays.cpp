// Link: https://www.geeksforgeeks.org/problems/intersection-of-two-sorted-arrays-with-duplicate-elements/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &a, vector<int> &b)
    {
        // code here
        int n = a.size(), m = b.size();
        int i = 0, j = 0;

        vector<int> res;

        while (i < n && j < m)
        {
            if (a[i] == b[j])
            {
                if (res.empty() || res.back() != a[i])
                {
                    res.push_back(a[i]);
                }
                i++;
                j++;
            }

            else if (a[i] < b[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> a = {1, 2, 2, 3, 4};
    vector<int> b = {2, 2, 3, 5};

    vector<int> result = sol.intersection(a, b);
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl; // Output: 2 3
    return 0;
}

/*
Question: Given two sorted arrays, find the intersection of these two arrays. The intersection should include only unique elements that are present in both arrays.

Example:
Input:
a = [1, 2, 2, 3, 4]
b = [2, 2, 3, 5]
Output:
[2, 3]
Explanation: The unique elements that are present in both arrays are 2 and 3.

Note: The input arrays may contain duplicate elements, but the output should only include unique elements that are present in both arrays.

Constraints:
1 <= n, m <= 10^5
-10^9 <= a[i], b[i] <= 10^9
Expected Time Complexity: O(n + m)
Expected Auxiliary Space: O(1) (excluding the space for the output array)

====================================================================================================
Approach:
1. Initialize two pointers, i and j, to the beginning of arrays a and b respectively
2. Create an empty vector res to store the intersection of the two arrays.
3. While both pointers are within the bounds of their respective arrays:
    a. If a[i] is equal to b[j], check if res is empty or if the last element in res is not equal to a[i]. If true, add a[i] to res. Then increment both i and j.
    b. If a[i] is less than b[j], increment i to move to the next element in array a.
    c. If a[i] is greater than b[j], increment j to move to the next element in array b.

4. Return the vector res containing the unique intersection of the two arrays.

Time Complexity: O(n + m) - We traverse both arrays once.
Space Complexity: O(1) - We use only a constant amount of extra space for the output array, excluding the space for the output vector res.

Dry run:
Input:
a = [1, 2, 2, 3, 4]
b = [2, 2, 3, 5]

- Initialize i = 0, j = 0, res = []
- a[0] = 1, b[0] = 2 -> a[0] < b[0], increment i -> i = 1
- a[1] = 2, b[0] = 2 -> a[1] == b[0], res is empty, add 2 to res -> res = [2], increment i and j -> i = 2, j = 1
- a[2] = 2, b[1] = 2 -> a[2] == b[1], res is not empty and res.back() == 2, do not add to res, increment i and j -> i = 3, j = 2
- a[3] = 3, b[2] = 3 -> a[3] == b[2], res is not empty and res.back() != 3, add 3 to res -> res = [2, 3], increment i and j -> i = 4, j = 3
- a[4] = 4, b[3] = 5 -> a[4] < b[3], increment i -> i = 5
- i is now out of bounds, exit loop
- Return res = [2, 3]




*/