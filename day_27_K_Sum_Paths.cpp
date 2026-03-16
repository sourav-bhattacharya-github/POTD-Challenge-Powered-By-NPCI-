// Link: https://www.geeksforgeeks.org/problems/k-sum-paths/1

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    int solve(Node *root, int k, long long currSum, unordered_map<long long, int> &mp)
    {
        if (root == NULL)
            return 0;
        currSum += root->data;

        int count = 0;

        if (mp.find(currSum - k) != mp.end())
            count += mp[currSum - k];

        mp[currSum]++;

        count += solve(root->left, k, currSum, mp);
        count += solve(root->right, k, currSum, mp);

        mp[currSum]--;

        return count;
    }
    int countAllPaths(Node *root, int k)
    {
        // code here
        unordered_map<long long, int> mp;
        mp[0] = 1;

        return solve(root, k, 0, mp);
    }
};

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(-3);
    root->left->left = new Node(3);
    root->left->right = new Node(2);
    root->right->right = new Node(11);
    root->left->left->left = new Node(3);
    root->left->left->right = new Node(-2);
    root->left->right->right = new Node(1);

    Solution sol;
    int k = 8;
    int result = sol.countAllPaths(root, k);

    cout << "Number of paths with sum " << k << ": " << result << endl;

    return 0;
}

/*
Question: Given a binary tree and a sum, count all paths that add up to the given sum. The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

Example 1:
Input:
       10
      /  \
     5   -3
    / \    \
   3   2    11
  / \   \
 3  -2   1
Output: 3
Explanation: The paths that sum to 8 are: 5 -> 3, 5 -> 2 -> 1, and -3 -> 11.

Example 2:
Input:
       1
      / \
     2   3
    / \
   4   5
Output: 2
Explanation: The paths that sum to 3 are: 1 -> 2 and 3.

Example 3:
Input:
       1
      / \
     2   3
    / \
   4   5
Output: 0
Explanation: There are no paths that sum to 5.
===============================================================================================================
Brute Force Approach:
For each node-
1. Start DFS
2. Track sum along the path

Time Complexity: O(N^2) in worst case (skewed tree)
Space Complexity: O(N) for recursion stack in worst case (skewed tree)

Optimal Approach:
1.Perform DFS traversal
2.Maintain currSum
3.Check if (currSum - k) exists in map
4.Add current sum to map
5.Recurse left & right
6.Remove sum when backtracking


Time Complexity: O(N) where N is the number of nodes in the binary tree. This is because we are visiting each node exactly once.
Space Complexity: O(N) where N is the number of nodes in the binary tree. This

*/