// Link: https://www.geeksforgeeks.org/problems/check-if-subtree/1

#include <bits/stdc++.h>
using namespace std;

// Definition for Node
struct Node
{
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
    // Function to check if two trees are identical
    bool isIdentical(Node *a, Node *b)
    {
        // If both trees are empty, they are identical
        if (a == nullptr && b == nullptr)
            return true;

        // If one of the trees is empty and the other is not, they are not identical
        if (a == nullptr || b == nullptr)
            return false;

        // Check if the data of the current nodes is the same and recursively check for left and right subtrees
        return (
            a->data == b->data &&
            isIdentical(a->left, b->left) &&
            isIdentical(a->right, b->right));
    }
    bool isSubTree(Node *root1, Node *root2)
    {
        // Base Cases
        if (root1 == nullptr)
            return false;
        // If both trees are identical, then return true
        if (root2 == nullptr)
            return false;

        // Check the tree with root as current node
        if (isIdentical(root1, root2))
            return true;

        // If the tree with root as current node doesn't match then
        // try left and right subtrees one by one
        return (
            isSubTree(root1->left, root2) ||
            isSubTree(root1->right, root2));
    }
};

Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return nullptr;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

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
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc--)
    {
        string str, ch;
        getline(cin, str);
        Node *rootA = buildTree(str);
        getline(cin, ch);
        Node *rootB = buildTree(ch);
        Solution ob;
        if (ob.isSubTree(rootA, rootB))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}

/*
Question: Given two binary trees, check if the first tree is a subtree of the second tree. A subtree of a tree T is a tree S consisting of a node in T and all of its descendants in T. The tree T could also be considered as a subtree of itself.

Example 1:
Input:
      10
     /  \
    20   30
   /  \
  40   60

         20
        /  \
     40   60
Output: Yes
Explanation: S is a subtree of T as S is present in T.

Example 2:
Input:
         10
      /    \
     20     30
    /  \
      40   60

         20
        /  \
     40   90
Output: No
Explanation: S is not a subtree of T as S is not present in T.

Constraints:
1 ≤ n ≤ 10^3
1 ≤ value of nodes ≤ 10^4

=============================================================================================
🧠 Core Idea

Tree S is a subtree of T if:

👉 There exists some node in T where:

Subtree rooted there == S

So we need 2 things:

Traverse every node of T
Check if trees are identical from that node
⚙️ Main Logic

For every node in T:

If current node value matches root of S
check if both trees are identical
Else:
search in left subtree
search in right subtree
🔥 Important Helper Function

We need:

isIdentical(a, b)

Checks:

same structure
same values
🌳 Recursive Formula

Subtree check:
isSubtree(T,S)=isIdentical(T,S)∨isSubtree(T.left,S)∨isSubtree(T.right,S)

Dry Run:
T:         10
          /    \
         20     30
        /  \
      40   60

S:         20
          /  \
       40   90
1. Start at root of T (10):
- 10 != 20, so check left and right subtrees
2. Check left subtree of 10 (20):
- 20 == 20, so check if trees are identical
3. Check if trees rooted at 20 are identical:
- 20 == 20, check left and right subtrees
4. Check left subtree of 20 (40):
- 40 == 40, check left and right subtrees
5. Check left subtree of 40 (null):
- Both null, return true
6. Check right subtree of 40 (null):
- Both null, return true
7. Left subtree of 20 is identical
8. Check right subtree of 20 (60):
- 60 != 90, check left and right subtrees
9. Check left subtree of 60 (null):
- Both null, return true
10. Check right subtree of 60 (null):
- Both null, return true
11. Right subtree of 20 is not identical
12. Check right subtree of 10 (30):
- 30 != 20, check left and right subtrees
13. Check left subtree of 30 (null):
- Both null, return true
14. Check right subtree of 30 (null):
- Both null, return true
15. Right subtree of 10 is not identical
16. Final result: No, S is not a subtree of T.



*/