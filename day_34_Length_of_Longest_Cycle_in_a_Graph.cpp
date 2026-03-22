// Link: https://www.geeksforgeeks.org/problems/length-of-longest-cycle-in-a-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCycle(int V, vector<vector<int>> &edges)
    {

        // convert to adjacency (only one outgoing)
        vector<int> adj(V, -1);

        for (auto &e : edges)
        {
            adj[e[0]] = e[1];
        }

        vector<int> visited(V, 0);
        int maxCycle = -1;

        for (int i = 0; i < V; i++)
        {

            if (visited[i])
                continue;

            unordered_map<int, int> time; // node → step
            int node = i;
            int step = 0;

            while (node != -1 && !visited[node])
            {

                visited[node] = 1;
                time[node] = step++;

                node = adj[node];

                // cycle found
                if (node != -1 && time.count(node))
                {
                    int cycleLen = step - time[node];
                    maxCycle = max(maxCycle, cycleLen);
                    break;
                }
            }
        }

        return maxCycle;
    }
};

int main()
{
    Solution sol;
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {3, 4}};

    int result = sol.longestCycle(V, edges);
    cout << "Length of longest cycle: " << result << endl;

    return 0;
}

/*
Question:
Given a directed graph with V vertices and edges, find the length of the longest cycle in the graph. If there is no cycle, return -1.

Example 1:
Input: V = 5, edges = [[0, 1], [1, 2], [2, 0], [3, 4]]
Output: 3
Explanation: The cycle is 0 → 1 → 2 → 0, which has a length of 3.

Example 2:
Input: V = 4, edges = [[0, 1], [1, 2], [2, 3]]
Output: -1
Explanation: There are no cycles in the graph.

Example 3:
Input: V = 6, edges = [[0, 1], [1, 2], [2, 0], [3, 4], [4, 5], [5, 3]]
Output: 3
Explanation: The cycles are 0 → 1 → 2 → 0 and 3 → 4 → 5 → 3, both of which have a length of 3.

Note:
- 1 <= V <= 10^5
- 0 <= edges.length <= 10^5
- edges[i].length == 2
- 0 <= edges[i][0], edges[i][1] < V
- edges[i][0] != edges[i][1]
- The graph may contain self-loops and multiple edges.

=====================================================================================================================
Approach:
1. Convert the edge list to an adjacency representation where each node points to its single outgoing edge
2. Use a visited array to keep track of visited nodes and an unordered_map to store the step at which each node was visited
3. For each unvisited node, traverse the graph following the outgoing edges until you encounter a visited node or reach a node with no outgoing edge
4. If a visited node is encountered and it exists in the unordered_map, calculate the cycle length and update the maximum cycle length found
5. Return the maximum cycle length found, or -1 if no cycle exists.

Time Complexity: O(V) since each node is visited at most once.
Space Complexity: O(V) for the visited array and the unordered_map.



*/