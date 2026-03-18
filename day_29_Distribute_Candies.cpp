// Link: https://www.geeksforgeeks.org/problems/distribute-candies-in-a-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

class Solution
{
public:
    int moves = 0;

    int dfs(Node *root)
    {
        if (root == NULL)
            return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        // Count moves
        moves += abs(left) + abs(right);

        return root->data + left + right - 1;
    }

    int distCandy(Node *root)
    {
        // code here
        dfs(root);

        return moves;
    }
};

int main()
{
    // Create tree: [5, 0, 0, N, N, 0, 0]
    //        5
    //       / \
    //      0   0
    //         / \
    //        0   0

    Node *root = new Node(5);
    root->left = new Node(0);
    root->right = new Node(0);
    root->right->left = new Node(0);
    root->right->right = new Node(0);

    Solution sol;
    int result = sol.distCandy(root);
    cout << "Minimum moves required: " << result << endl;

    return 0;
}

/*

Question: You are given the root of a binary tree with n nodes, where each node contains a certain number of candies, and the total number of candies across all nodes is n. In one move, you can select any two adjacent nodes and transfer one candy from one node to the other. The transfer can occur between a parent and child in either direction.

The task is to determine the minimum number of moves required to ensure that every node in the tree has exactly one candy.

Note: The testcases are framed such that it is always possible to achieve a configuration in which every node has exactly one candy, after some moves.


Examples 1:
Input: root = [5, 0, 0, N, N, 0, 0]

        5
       / \
      0   0
         / \
        0   0

Output: 6
Explanation:
Move 1 candy from root to left child
Move 1 candy from root to right child
Move 1 candy from right child to root->right->left node
Move 1 candy from root to right child
Move 1 candy from right child to root->right->right node
Move 1 candy from root to right child
so, total 6 moves required.



Example 2:
Input: root = [2, 0, 0, N, N, 3, 0]

        2
       / \
      0   0
         / \
        3   0

Output: 4
Explanation:
Move 1 candy from root to left child
Move 1 candy from root->right->left node to root->right node
Move 1 candy from root->right node to root->right->right node
Move 1 candy from root->right->left node to root->right node
so, total 4 moves required.
 ===================================================================================================

Key Insight-
Think in terms of extra or deficit candies at each node.

For each node:
balance = (candies at node) - 1
If balance > 0 → extra candies (needs to give)
If balance < 0 → needs candies

Approach:
1. Perform a post-order traversal of the tree.
2. For each node, calculate the balance of candies (candies at node - 1).
3. The number of moves required at each node is the absolute value of the balance (|balance|).

| Type  | Complexity           |
| ----- | -------------------- |
| Time  | O(n)                 |
| Space | O(h) recursion stack |

*/