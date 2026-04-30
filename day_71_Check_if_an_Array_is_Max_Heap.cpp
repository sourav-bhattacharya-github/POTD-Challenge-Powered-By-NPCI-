// link: https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isMaxHeap(vector<int> &arr)
    {
        // code here
        int n = arr.size();

        for (int i = 0; i <= (n - 2) / 2; i++)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && arr[i] < arr[left])
                return false;

            if (right < n && arr[i] < arr[right])
                return false;
        }

        return true;
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
    bool res = ob.isMaxHeap(arr);
    cout << res << endl;

    return 0;
}

/*
QUestion: Given an array of integers, determine whether it represents a Max-Heap or not. A Max-Heap is a complete binary tree in which the value of each node is greater than or equal to the values of its children.

Example 1:
Input:
N = 6
A[] = {90, 15, 10, 7, 12, 2}
Output: 1
Explanation: The given array represents the following binary tree:
         90
       /    \
     15      10
    /  \    /
   7   12  2
Since every parent node is greater than its children, the array represents a Max-Heap.

Example 2:
Input:
N = 6
A[] = {9, 15, 10, 7, 12, 11}
Output: 0
Explanation: The given array represents the following binary tree:
         9
       /    \
     15      10
    /  \    /
   7   12  11
Since the parent node (9) is smaller than its child node (15), the array does not represent a Max-Heap.

Constraints:
1 <= N <= 10^5

===============================================================================================

Approach:
1. We can iterate through the array and for each element at index i, we can check its left and right children (if they exist) to ensure that the parent node is greater than or equal to its children.
2. The left child of a node at index i can be found at index 2*i
3. The right child of a node at index i can be found at index 2*i + 1
4. If we find any parent node that is smaller than its child, we can immediately conclude that the array does not represent a Max-Heap and return false.
5. If we finish checking all nodes without finding any violations, we can return true, indicating that the array represents a Max-Heap.

Time Complexity: O(N) where N is the number of elements in the array, since we need to check each node at most once.
Space Complexity: O(1) since we are using only a constant amount of extra space.

Dry Run:
Input: arr = {90, 15, 10, 7, 12, 2}
- i = 0: left = 1 (15), right = 2 (10) -> 90 >= 15 and 90 >= 10 (valid)
- i = 1: left = 3 (7), right = 4 (12) -> 15 >= 7 and 15 >= 12 (valid)
- i = 2: left = 5 (2), right = 6 (does not exist) -> 10 >= 2 (valid)
Since all nodes satisfy the Max-Heap property, we return true (1).


*/