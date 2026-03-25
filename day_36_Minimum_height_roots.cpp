// Link: https://www.geeksforgeeks.org/problems/minimum-height-roots/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minHeightRoot(int V, vector<vector<int>> &edges)
    {
        // Code here
        if (V == 1)
            return {0};

        vector<vector<int>> adj(V);
        vector<int> degree(V, 0);

        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }

        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            if (degree[i] == 1)
                q.push(i);
        }

        int remaining = V;

        while (remaining > 2)
        {
            int size = q.size();
            remaining -= size;

            for (int i = 0; i < size; i++)
            {
                int node = q.front();
                q.pop();

                for (auto nei : adj[node])
                {
                    degree[nei]--;
                    if (degree[nei] == 1)
                        q.push(nei);
                }
            }
        }

        vector<int> result;

        while (!q.empty())
        {
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }
};

int main()
{
    Solution sol;
    int V = 4;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}};
    vector<int> result = sol.minHeightRoot(V, edges);

    for (int node : result)
    {
        cout << node << " ";
    }
    cout << endl; // Output: 1 (the minimum height root)

    return 0;
}

/*
Question: Given a tree with N nodes, find the minimum height roots of the tree. A tree is an undirected graph in which any two vertices are connected by exactly one path. The height of a tree is the number of edges on the longest path from the root to a leaf.


Example 1:
Input:
N = 4
edges = {{0, 1}, {1, 2}, {1, 3}}
Output: 1
Explanation: The tree looks like this:
    0
    |
    1
   / \
  2   3
The minimum height root is 1, as the height of the tree when rooted at 1 is 1, which is the minimum possible height.


Example 2:
Input:
N = 6
edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}}
Output: 0
Explanation: The tree looks like this:
    0
   / \
  1   2
 / \   \
3   4   5
The minimum height root is 0, as the height of the tree when rooted at 0 is 2, which is the minimum possible height.

Constraints:
1 <= N <= 10^5

===============================================================================================
Approach:
1. Build the adjacency list and degree array for the tree.
2. Use a queue to perform a level order traversal (BFS) starting from the leaf nodes (nodes with degree 1).
3. Remove the leaf nodes and update the degree of their neighbors.
4. Continue this process until there are at most 2 nodes remaining in the queue, which will be the minimum height roots of the tree.

Dry Run:
For the input:
N = 4
edges = {{0, 1}, {1, 2}, {1, 3}}
- Build adjacency list:
  adj[0] = {1}
  adj[1] = {0, 2, 3}
  adj[2] = {1}
  adj[3] = {1}

- Build degree array:
  degree[0] = 1
  degree[1] = 3
  degree[2] = 1
  degree[3] = 1

- Initialize queue with leaf nodes (degree 1):
  q = {0, 2, 3}
- Process queue:
  - Remove 0: degree[1] becomes 2
  - Remove 2: degree[1] becomes 1 (add 1 to queue)
  - Remove 3: degree[1] becomes 0 (already in queue)
- Remaining nodes in queue: {1}
Output: 1 (the minimum height root)

Time Complexity: O(N) for building the graph and performing BFS.
Space Complexity: O(N) for the adjacency list and degree array.


*/