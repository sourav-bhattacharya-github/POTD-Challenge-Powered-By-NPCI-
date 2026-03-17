// Link: https://www.geeksforgeeks.org/problems/burning-tree/1

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
    // Function to mark parents of all nodes and return the target node
    Node *markParents(Node *root, unordered_map<Node *, Node *> &parent, int target)
    {
        queue<Node *> q;
        q.push(root);

        Node *targetNode = NULL;

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            if (curr->data == target)
                targetNode = curr;

            if (curr->left)
            {
                parent[curr->left] = curr;
                q.push(curr->left);
            }

            if (curr->right)
            {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }

        return targetNode;
    }

    int minTime(Node *root, int target)
    {
        // code here
        unordered_map<Node *, Node *> parent;

        // Mark parents and get target node
        Node *targetNode = markParents(root, parent, target);

        // BFS from target node
        unordered_map<Node *, bool> visited;
        queue<Node *> q; // Queue for BFS

        // Start BFS from target node
        q.push(targetNode);
        // Mark target node as visited
        visited[targetNode] = true;

        int time = 0; // Time taken to burn the tree

        // BFS traversal to burn the tree
        while (!q.empty())
        {
            int size = q.size();
            bool burned = false;

            // Process all nodes at the current level of BFS
            for (int i = 0; i < size; i++)
            {
                Node *curr = q.front();
                q.pop();

                // left child
                if (curr->left && !visited[curr->left])
                {
                    visited[curr->left] = true;
                    q.push(curr->left);
                    burned = true;
                }

                // right child
                if (curr->right && !visited[curr->right])
                {
                    visited[curr->right] = true;
                    q.push(curr->right);
                    burned = true;
                }

                // parent
                if (parent[curr] && !visited[parent[curr]])
                {
                    visited[parent[curr]] = true;
                    q.push(parent[curr]);
                    burned = true;
                }
            }

            if (burned)
                time++;
        }
        return time;
    }
};

/*
Question: Given a binary tree and a target node, find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned.

Example 1:
Input:
       1
     /   \
    2     3
   / \   / \
  4   5 6   7
Target = 4
Output: 2
Explanation: If we start burning from node 4, then in 1 second nodes 2 and 5 will get burned. After that in the next second, nodes 1 and 3 will get burned. Finally, in the third second, nodes 6 and 7 will get burned. So, the total time taken to burn the complete tree is 2 seconds.

Example 2:
Input:
       1
     /   \
    2     3
   / \   / \
  4   5 6   7
Target = 2
Output: 1
Explanation: If we start burning from node 2, then in 1 second nodes 1, 4 and 5 will get burned. After that in the next second, nodes 3, 6 and 7 will get burned. So, the total time taken to burn the complete tree is 1 second.

Example 3:
Input:
       1
     /   \
    2     3
   / \   / \
  4   5 6   7
Target = 1
Output: 2
Explanation: If we start burning from node 1, then in 1 second nodes 2 and 3 will get burned. After that in the next second, nodes 4, 5, 6 and 7 will get burned. So, the total time taken to burn the complete tree is 2 seconds.
===============================================================================================================
Approach:
1. Mark Parents: We first perform a level order traversal (BFS) to mark the parent of each node in a hash map. This allows us to easily access the parent of any node during the burning process.
2. BFS from Target: We then perform another BFS starting from the target node. We use a queue to keep track of the nodes that are currently burning and a visited map to avoid processing the same node multiple times.
3. Time Calculation: For each level of BFS, we check if any new nodes are burned. If yes, we increment the time counter. We continue this process until there are no more nodes to burn.

Time Complexity: O(N) where N is the number of nodes in the binary tree. This is because we are visiting each node at most twice (once for marking parents and once for burning).
Space Complexity: O(N) where N is the number of nodes in the binary tree. This is because we are using a hash map to store the parent of each node and a queue for BFS, both of which can grow up to O(N) in size in the worst case (skewed tree).



*/