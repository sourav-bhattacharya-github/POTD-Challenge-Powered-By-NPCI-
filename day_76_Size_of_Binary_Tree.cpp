// Link: https://www.geeksforgeeks.org/problems/size-of-binary-tree/1

#include <bits/stdc++.h>
using namespace std;


// Definition for Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int getSize(Node* root) {
        // code here
        if(root == nullptr)
            return 0;
            
        return 1 + getSize(root->left) + getSize(root->right);
    }
};

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main(){
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string str, ch;
        getline(cin, str);
        Node* root = buildTree(str);
        Solution ob;
        cout << ob.getSize(root) << endl;
    }
    return 0;

}

/*
Question: Given a binary tree, find its size. The size of a binary tree is the total number of nodes in the tree.

Example 1:
Input:
       1
     /   \
    2     3
Output: 3
Explanation: The size of the binary tree is 3 as there are three nodes in the tree.

Example 2:
Input:
       10
     /    \
    20     30
   /  \
  40   60
Output: 5
Explanation: The size of the binary tree is 5 as there are five nodes in the tree

Constraints:
1 <= Number of nodes <= 10^5

==============================================================================================
Approach:
1. Base Case: If the current node is null, return 0.
2. Recursive Case: Return 1 (for the current node) + size of left subtree + size of right subtree.
3. The time complexity of this approach is O(n) where n is the number of nodes in the binary tree, as we visit each node exactly once.

Time Complexity: O(n)
Space Complexity: O(h) where h is the height of the binary tree, due to the recursive call stack.

Dry Run:
Consider the binary tree:
         10
      /    \
     20     30
    /  \
      40   60   

1. Start at the root node (10):
   - Call getSize(10)
2. At node 10:
   - Call getSize(20) for the left subtree
3. At node 20:
   - Call getSize(40) for the left subtree
4. At node 40:
   - Call getSize(NULL) for the left subtree, which returns 0
    - Call getSize(NULL) for the right subtree, which returns 0
    - Return 1 + 0 + 0 = 1 for node 40
5. Back at node 20:
   - Call getSize(60) for the right subtree
6. At node 60:
   - Call getSize(NULL) for the left subtree, which returns 0
    - Call getSize(NULL) for the right subtree, which returns 0
    - Return 1 + 0 + 0 = 1 for node 60
7. Back at node 20:
    - Return 1 + 1 (for node 40) + 1 (for node 60) = 3 for node 20
8. Back at node 10:
    - Call getSize(30) for the right subtree
9. At node 30:
    - Call getSize(NULL) for the left subtree, which returns 0
    - Call getSize(NULL) for the right subtree, which returns 0
    - Return 1 + 0 + 0 = 1 for node 30
10. Back at node 10:
    - Return 1 + 3 (for node 20) + 1 (for node 30) = 5 for node 10

*/