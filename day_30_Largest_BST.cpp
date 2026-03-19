// Link: https://www.geeksforgeeks.org/problems/largest-bst/1

#include <bits/stdc++.h>
using namespace std;


// Tree node structure  used in the program
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    
    int maxSize = 0; // To keep track of the largest BST size found so far
    

    // Structure to hold information about the subtree being processed 
    struct Info {
        int mini;
        int maxi;
        int size;
        bool isBST;
    };
    
    // Helper function to solve the problem recursively 
    Info solve(Node* root){
        // Base case: An empty tree is a BST of size 0
        if(root == NULL){
            return {INT_MAX, INT_MIN, 0, true};
        }
        
        // Recursively solve for left and right subtrees 
        Info left = solve(root->left);
        Info right = solve(root->right);
        
        Info curr; // To hold information about the current subtree
        

        // Calculate the size, minimum, and maximum values for the current subtree
        curr.size = left.size + right.size + 1;
        curr.mini = min(root->data, left.mini);
        curr.maxi = max(root->data, right.maxi);
        
        // Check BST
        if(left.isBST && right.isBST &&
            root->data > left.maxi &&
            root->data < right.mini){
                curr.isBST = true;
                
                maxSize = max(maxSize, curr.size); // Update the largest BST size found so far
        }
        else{
            curr.isBST = false;
        }
        
        return curr;
    }

    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        // Your code here
        solve(root);
        return maxSize;
    }
};


int main() {
    // Create a sample tree
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(7);

    Solution sol;
    cout << "Size of the largest BST is: " << sol.largestBst(root) << endl;

    return 0;
}

/*
Question: Given a binary tree, find the size of the largest subtree which is also a Binary Search Tree (BST).

Example 1:
Input:
       10
      /  \
     5   15
    / \    \
   1   8    7
Output: 3
Explanation: The largest BST subtree is:
       5
      / \
     1   8  

Example 2:
Input:
       5
      / \
     2   4
    / \
   1   3
Output: 2
Explanation: The largest BST subtree is:
       2
      / \
     1   3

Example 3:
Input:
       1
      / \
     2   3
Output: 1
Explanation: The largest BST subtree is any of the leaf nodes (1, 2, or 3) which are all BSTs of size 1.

==========================================================================================================
Approach:
1. We will use a recursive approach to solve the problem. We will define a helper function `solve` that will return information about the subtree being processed, including its minimum and maximum values, size, and whether it is a BST.
2. For each node, we will recursively check its left and right subtrees to gather information about them.
3. We will then determine if the current subtree rooted at the node is a BST by checking if the left subtree is a BST, the right subtree is a BST, and the current node's value is greater than the maximum value in the left subtree and less than the minimum value in the right subtree.
4. If the current subtree is a BST, we will update the maximum size of the BST found so far.
5. Finally, we will return the size of the largest BST found in the tree.

Definition of the Info structure:
- `mini`: The minimum value in the subtree.
- `maxi`: The maximum value in the subtree.
- `size`: The size of the subtree.
- `isBST`: A boolean indicating whether the subtree is a BST or not.

Dry Run:
Consider the following tree:
       10
      /  \
     5   15
    / \    \
   1   8    7
1. Start at the root (10):
   - Left subtree (5):  
        - Left subtree (1): is a BST of size 1, mini = 1, maxi = 1
        - Right subtree (8): is a BST of size 1, mini = 8, maxi = 8
        - Current node (5) is a BST with size 3, mini = 1, maxi = 8
    - Right subtree (15):
        - Left subtree (NULL): is a BST of size 0, mini = INT_MAX, maxi = INT_MIN
        - Right subtree (7): is a BST of size 1, mini = 7, maxi = 7
        - Current node (15) is not a BST because 15 > 7
2. The largest BST found is of size 3 (subtree rooted at 5).




| Type  | Complexity     |
| ----- | -------------- |
| Time  | O(n)           |
| Space | O(h) recursion |

*/