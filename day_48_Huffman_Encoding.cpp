// Link: https://www.geeksforgeeks.org/problems/huffman-encoding3345/1

#include <bits/stdc++.h>
using namespace std;

// A tree node for Huffman encoding
class Node
{
public:
    int freq;
    char ch;
    Node *left;
    Node *right;

    Node(int f, char c)
    {
        freq = f;
        ch = c;
        left = right = NULL;
    }
};

// Min Heap Comparator
struct cmp
{
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

class Solution
{
public:
    // Preorder traversal to generate Huffman codes for each character in the tree and store them in the ans vector with the corresponding path (0 for left and 1 for right).
    void preorder(Node *root, string temp, vector<string> &ans)
    {
        if (!root)
            return;

        if (!root->left && !root->right)
        {
            ans.push_back(temp);
            return;
        }

        preorder(root->left, temp + "0", ans);
        preorder(root->right, temp + "1", ans);
    }

    vector<string> huffmanCodes(string &s, vector<int> f)
    {
        int n = s.size();

        priority_queue<Node *, vector<Node *>, cmp> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push(new Node(f[i], s[i]));
        }

        while (pq.size() > 1)
        {
            Node *left = pq.top();
            pq.pop();
            Node *right = pq.top();
            pq.pop();

            Node *newNode = new Node(left->freq + right->freq, '$');
            newNode->left = left;
            newNode->right = right;

            pq.push(newNode);
        }

        Node *root = pq.top();

        vector<string> ans;
        preorder(root, "", ans);

        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "abc";
    vector<int> f = {5, 9, 12};
    vector<string> codes = sol.huffmanCodes(s, f);

    for (const string &code : codes)
    {
        cout << code << endl;
    }

    return 0;
}

/*
Question: Given a string s and an array of frequencies f, generate the Huffman codes for each character in the string based on their corresponding frequencies.

Example:
Input: s = "abc", f = [5, 9, 12]
Output: 00, 01, 10
Explanation: The Huffman codes for characters 'a', 'b', and 'c' are generated based on their frequencies. The character with the highest frequency gets the shortest code.


Note: The output may vary based on the implementation of the priority queue and the order of characters with the same frequency.
==============================================================================================================

Approach:
1. Create a min-heap (priority queue) to store the nodes of the Huffman tree based on their frequencies.
2. Insert all characters and their frequencies into the min-heap as individual nodes.
3. While there is more than one node in the min-heap:
    a. Extract the two nodes with the smallest frequencies.
    b. Create a new internal node with these two nodes as children and the frequency equal to the sum of their frequencies.
    c. Insert the new internal node back into the min-heap.
4. The remaining node in the min-heap will be the root of the Huffman tree.
5. Perform a preorder traversal of the Huffman tree to generate the Huffman codes for each character, where left edges represent '0' and right edges represent '1'.

Note: The time complexity of this approach is O(n log n) due to the operations on the priority queue, where n is the number of characters. The space complexity is O(n) for storing the Huffman codes and the tree nodes.


*/