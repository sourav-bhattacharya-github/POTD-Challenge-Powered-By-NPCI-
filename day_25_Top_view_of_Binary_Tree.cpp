// Link: https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

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
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    vector<int> topView(Node *root)
    {
        // code here
        vector<int> ans;

        if (root == NULL)
            return ans;

        map<int, int> mp; // Map to store the first node's data at each horizontal distance (hd) from the root. The key is the horizontal distance, and the value is the node's data.

        queue<pair<Node *, int>> q; // Queue for level order traversal of the binary tree. Each element is a pair of a node and its corresponding horizontal distance (hd) from the root.

        // Start the level order traversal from the root node with a horizontal distance of 0.
        q.push({root, 0});

        while (!q.empty())
        {
            // Get the front element of the queue, which contains the current node and its horizontal distance (hd) from the root.
            auto temp = q.front();
            q.pop(); // Remove the front element from the queue.

            // Extract the node and its horizontal distance from the pair.
            Node *node = temp.first;
            int hd = temp.second; // Horizontal distance from the root.

            // If the horizontal distance (hd) is not already present in the map, it means this is the first node encountered at this horizontal distance, so we add it to the map.
            if (mp.find(hd) == mp.end())
            {
                mp[hd] = node->data;
            }

            // If the current node has a left child, we add it to the queue with a horizontal distance of hd - 1 (one step to the left).
            if (node->left)
            {
                q.push({node->left, hd - 1});
            }

            // If the current node has a right child, we add it to the queue with a horizontal distance of hd + 1 (one step to the right).
            if (node->right)
            {
                q.push({node->right, hd + 1});
            }
        }

        // After the level order traversal is complete, we iterate through the map (which is sorted by horizontal distance) and add the node's data to the answer vector.
        for (auto it : mp)
            ans.push_back(it.second);

        return ans;
    }
};

int main()
{
    // Create a sample binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution sol;
    vector<int> result = sol.topView(root);

    cout << "Top view of the binary tree: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}

/*
Question: Given a binary tree, return the top view of the binary tree. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top. The nodes should be returned in order from left to right.

Example 1:
Input:
       1
     /   \
    2     3
   / \     \
  4   5     6
Output: 4 2 1 3 6
Explanation: The nodes visible from the top view are 4, 2, 1, 3, and 6.

Example 2:
Input:
       1
     /   \
    2     3
   / \   / \
  4   5 6   7
Output: 4 2 1 3 7
Explanation: The nodes visible from the top view are 4, 2, 1, 3, and 7.

Example 3:
Input:
       1
     /   \
    2     3
   / \   / \
  4   5 6   7
       \
        8
Output: 4 2 1 3 7
Explanation: The nodes visible from the top view are 4, 2, 1, 3, and 7. The node with value 8 is not visible from the top view because it is blocked by the node with value 5.

Example 4:
Input:
       1
     /   \
    2     3
   / \   / \
  4   5 6   7
       \
        8
         \
          9
Output: 4 2 1 3 7
Explanation: The nodes visible from the top view are 4, 2, 1, 3, and 7. The nodes with values 8 and 9 are not visible from the top view because they are blocked by the node with value 5.
======================================================================================================
Approach:
1. We can use a level order traversal (BFS) of the binary tree to determine the nodes visible from the top view. We will maintain a map to store the first node's data at each horizontal distance (hd) from the root. The key of the map will be the horizontal distance, and the value will be the node's data.
2. We will also use a queue to perform the level order traversal. Each element in the queue will be a pair of a node and its corresponding horizontal distance from the root.
3. We will start the traversal from the root node with a horizontal distance of 0. For each node, if its horizontal distance is not already present in the map, we will add it to the map. This ensures that only the first node encountered at each horizontal distance is recorded.
4. After the traversal is complete, we will iterate through the map (which is sorted by horizontal distance) and add the node's data to the answer vector, which will be returned as the top view of the binary tree.

Time Complexity: O(N log N) due to the map insertion and traversal, where N is the number of nodes in the binary tree.
Space Complexity: O(N) for the queue and the map, where N is the number of nodes in the binary tree.

*/