// Link: https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

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
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    vector<vector<int>> verticalOrder(Node *root)
    {
        // code here
        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        map<int, vector<int>> mp;

        queue<pair<Node *, int>> q;

        q.push({root, 0});

        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();

            Node *node = temp.first;
            int hd = temp.second;

            mp[hd].push_back(node->data);

            if (node->left)
                q.push({node->left, hd - 1});

            if (node->right)
                q.push({node->right, hd + 1});
        }

        for (auto it : mp)
            ans.push_back(it.second);

        return ans;
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<vector<int>> result = sol.verticalOrder(root);

    for (const auto &vec : result)
    {
        for (int val : vec)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
Question: Given a binary tree, print the vertical order traversal of it. For each vertical line, print nodes in top to bottom order.

Example 1:
Input:
       1
     /   \
    2     3
   / \   / \
  4   5 6   7
Output:
4
2 5 6
1
3
7

Example 2:
Input:
       1
     /   \
    2     3
   / \   / \
  4   5 6   7
       \     \
        8     9
Output:
4
2 5 6
1 8
3 9
7

Example 3:
Input:
       1
     /   \
    2     3
   / \   / \
  4   5 6   7
       \     \
        8     9
Output:
4
2 5 6
1 8
3 9
7

==========================================================================================================
Approach:
1. We can use a map to store the vertical order traversal of the binary tree. The key of the map will be the horizontal distance (hd) from the root node, and the value will be a vector of integers representing the nodes at that horizontal distance.
2. We can perform a level order traversal of the binary tree using a queue. For each node, we will calculate its horizontal distance from the root node and store it in the map.
3. We will start with the root node at horizontal distance 0. For the left child of a node, we will decrease the horizontal distance by 1, and for the right child, we will increase the horizontal distance by 1.
4. After the level order traversal is complete, we will iterate through the map and add the vectors of nodes to the final answer vector.

Time Complexity: O(N log N) where N is the number of nodes in the binary tree. This is because we are using a map to store the nodes based on their horizontal distance, and inserting into a map takes O(log N) time.
Space Complexity: O(N) where N is the number of nodes in the binary tree. This is because we are storing all the nodes in the map and the final answer vector.


*/