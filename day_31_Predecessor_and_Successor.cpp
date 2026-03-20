// Link: https://www.geeksforgeeks.org/problems/predecessor-and-successor/1

#include <bits/stdc++.h>
using namespace std;

// BST Node
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    vector<Node *> findPreSuc(Node *root, int key)
    {
        // code here
        Node *pre = NULL;
        Node *suc = NULL;
        Node *curr = root;

        while (curr != NULL)
        {
            if (curr->data < key)
            {
                pre = curr; // possible predecessor
                curr = curr->right;
            }
            else if (curr->data > key)
            {
                suc = curr; // possible successor
                curr = curr->left;
            }
            else
            {
                // find predecessor
                if (curr->left)
                {
                    Node *temp = curr->left;

                    while (temp->right)
                        temp = temp->right;

                    pre = temp;
                }
                // find successor
                if (curr->right)
                {
                    Node *temp = curr->right;

                    while (temp->left)
                        temp = temp->left;

                    suc = temp;
                }

                break;
            }
        }

        return {pre, suc};
    }
};

int main()
{
    // Create a sample tree
    Node *root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->right = new Node(40);

    Solution sol;
    int key = 15;
    vector<Node *> result = sol.findPreSuc(root, key);

    cout << "Predecessor: " << (result[0] ? result[0]->data : -1) << endl;
    cout << "Successor: " << (result[1] ? result[1]->data : -1) << endl;

    return 0;
}

/*
Question: Given a Binary Search Tree and a key, find the predecessor and successor of the given key in the BST. If either predecessor or successor is not found, return NULL for that.

Example 1:
Input:
       20
      /  \
     10   30
    / \    \
   5   15   40
Key = 15
Output: Predecessor: 10, Successor: 20
Explanation: The predecessor of 15 is 10 and the successor is 20.

Example 2:
Input:
       20
      /  \
     10   30
    / \    \
   5   15   40
Key = 10
Output: Predecessor: 5, Successor: 15
Explanation: The predecessor of 10 is 5 and the successor is 15.

Example 3:
Input:
         20
        /  \
      10   30
     / \    \
    5   15   40
Key = 25
Output: Predecessor: 20, Successor: 30
Explanation: The predecessor of 25 is 20 and the successor is 30.
=============================================================================

Algorithm:
1. Initialize two pointers, pre and suc, to NULL.
2. Start traversing the BST from the root node.
3. If the current node's data is less than the key, update pre to the current node and move to the right child.
4. If the current node's data is greater than the key, update suc to the current node and move to the left child.
5. If the current node's data is equal to the key, find the predecessor and successor
    - For the predecessor, if the left child exists, move to the left child and keep moving to the right until you reach the rightmost node. This will be the predecessor.
    - For the successor, if the right child exists, move to the right child and keep moving to the left until you reach the leftmost node. This will be the successor.
6. Return the predecessor and successor as a vector of Node pointers.

| Type  | Complexity |
| ----- | ---------- |
| Time  | O(h)       |
| Space | O(1)       |



*/