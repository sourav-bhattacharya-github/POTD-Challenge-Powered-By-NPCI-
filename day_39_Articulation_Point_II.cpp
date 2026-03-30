// Link: https://www.geeksforgeeks.org/problems/articulation-point2616/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int timer = 0;

    void dfs(int node, int parent, vector<int> &vis,
             vector<int> &tin, vector<int> &low,
             vector<vector<int>> &adj, vector<int> &mark)
    {

        vis[node] = 1;
        tin[node] = low[node] = timer++;
        int child = 0;

        for (auto neigh : adj[node])
        {

            if (neigh == parent)
                continue;

            if (!vis[neigh])
            {
                dfs(neigh, node, vis, tin, low, adj, mark);

                // update low
                low[node] = min(low[node], low[neigh]);

                // articulation condition (non-root)
                if (low[neigh] >= tin[node] && parent != -1)
                {
                    mark[node] = 1;
                }

                child++;
            }
            else
            {
                // back edge
                low[node] = min(low[node], tin[neigh]);
            }
        }

        // root condition
        if (parent == -1 && child > 1)
        {
            mark[node] = 1;
        }
    }

    vector<int> articulationPoints(int V, vector<vector<int>> &edges)
    {

        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(V, 0), tin(V), low(V), mark(V, 0);

        // Step 2: DFS for all components
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1, vis, tin, low, adj, mark);
            }
        }

        // Step 3: Collect answer
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (mark[i])
                ans.push_back(i);
        }

        if (ans.empty())
            return {-1};
        return ans;
    }
};

int main()
{
    Solution sol;
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {3, 4}};

    vector<int> result = sol.articulationPoints(V, edges);
    for (int ap : result)
    {
        cout << ap << " "; // Output: Articulation points
    }
    cout << endl;

    return 0;
}

/*
Question: Articulation Point II
Given an undirected graph with V vertices and E edges, find all the articulation points in the graph. An articulation point is a vertex that, when removed along with its associated edges, increases the number of connected components in the graph.

Example 1:
Input:
V = 5, E = 5
edges = [[0, 1], [0, 2], [1, 2], [1, 3], [3, 4]]
Output: 1 3
Explanation: The articulation points in the graph are 1 and 3. Removing vertex 1 disconnects vertex 3 and 4 from the rest of the graph, and removing vertex 3 disconnects vertex 4 from the rest of the graph.


Example 2:
Input:
V = 4, E = 3
edges = [[0, 1], [1, 2], [2, 3]]
Output: 1 2
Explanation: The articulation points in the graph are 1 and 2. Removing vertex 1 disconnects vertex 0 from the rest of the graph, and removing vertex 2 disconnects vertex 3 from the rest of the graph.

Example 3:
Input:
V = 3, E = 3
edges = [[0, 1], [1, 2], [2, 0]]
Output: -1
Explanation: The graph is a triangle, and there are no articulation points. Removing any vertex does not disconnect the graph.

Note: The output should be in sorted order. If there are no articulation points, return a list containing only -1.

=============================================================================================
Approach:
1. We will use Depth First Search (DFS) to find articulation points in the graph.
2. We will maintain three arrays:
    - `tin[]`: To store the time of first visit for each vertex.
    - `low[]`: To store the lowest reachable time from a vertex.
    - `mark[]`: To mark whether a vertex is an articulation point or not.
3. We will perform DFS for each unvisited vertex and update the `tin` and `low` values accordingly.
4. After the DFS, we will collect all the vertices marked as articulation points and return them
in sorted order. If there are no articulation points, we will return a list containing only -1.

Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph.
Space Complexity: O(V) for the adjacency list and the arrays used in DFS.

*/