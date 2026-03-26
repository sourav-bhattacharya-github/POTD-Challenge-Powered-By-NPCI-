// Link: https://www.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPaths(int V, vector<vector<int>> &edges)
    {
        // code here
        const long long INF = 1e18; // Use long long to avoid overflow
        const int MOD = 1e9 + 7;    // Modulo for large numbers

        vector<vector<pair<int, int>>> adj(V); // Adjacency list with (neighbor, weight)

        for (auto &r : edges)
        {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        vector<long long> dist(V, INF); // Distance array initialized to infinity
        vector<int> ways(V, 0);         // Ways array initialized to 0

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq; // Min-heap for Dijkstra

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while (!pq.empty())
        {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) // If we have already found a shorter path to node, skip
                continue;

            for (auto &[adjNode, wt] : adj[node]) // Explore neighbors
            {
                if (d + wt < dist[adjNode])
                {
                    dist[adjNode] = d + wt;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                }
                else if (d + wt == dist[adjNode]) // Found another shortest path
                {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[V - 1]; // Return the number of ways to reach the destination vertex (V-1)
    }
};

int main()
{
    Solution sol;
    int V = 7;
    vector<vector<int>> edges = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};

    int result = sol.countPaths(V, edges);
    cout << result << endl; // Output: Number of ways to arrive at destination

    return 0;
}

/*
Question: You are given a directed weighted graph with V vertices and E edges. Find the number of ways to reach the destination vertex from the source vertex in the shortest path.

Example 1:
Input:
V = 7
E = 10
edges = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}}
Output: 4
Explanation: The graph looks like this:
0 --2--> 1 --3--> 2
|         |         |
5         3         1
|         |         |
4         3         5
|         |         |
6 --7--> 3 --1--> 5
|         |
2         3
The shortest path from vertex 0 to vertex 5 is of length 7, and there are 4 different paths that achieve this length:
1. 0 -> 1 -> 2 -> 5
2. 0 -> 1 -> 3 -> 5
3. 0 -> 6 -> 3 -> 5
4. 0 -> 6 -> 5

Example 2:
Input:
V = 3
E = 3
edges = {{0, 1, 1}, {1, 2, 1}, {0, 2, 2}}
Output: 2
Explanation: The graph looks like this:
0 --1--> 1 --1--> 2
|         |
2         1
|         |
2         2
The shortest path from vertex 0 to vertex 2 is of length 2, and there are 2 different paths that achieve this length:
1. 0 -> 1 -> 2
2. 0 -> 2


Constraints:
1 <= V <= 10^5
1 <= E <= 10^5
1 <= edges[i][0], edges[i][1] < V
1 <= edges[i][2] <= 10^6
=================================================================================================

🔍 Problem Analysis
Given:
Undirected weighted graph
Each edge has time (weight)
Task:
From node 0 -> node V-1

Find:
Shortest time
Number of ways to reach with that shortest time

🚨 Hidden Challenge:
Not just shortest path ❌
Count how many shortest paths exist

🧠 2. Thought Process
Normal Dijkstra gives:
shortest distance
But here we also need:
👉 number of ways to reach each node

💡 Idea:
Maintain 2 arrays:
dist[i] → shortest time to reach i
ways[i] → number of ways to reach i


🧠 Transition Logic:

When exploring u → v:

Case 1: Found shorter path
if dist[u] + wt < dist[v]:
    dist[v] = dist[u] + wt
    ways[v] = ways[u]
Case 2: Found another shortest path
if dist[u] + wt == dist[v]:
    ways[v] += ways[u]

⚡ 3. Approach
🚀 Optimal: Dijkstra + Path Counting
Use min heap (priority queue)
Track shortest distances
Update number of ways

Dry run on example:
Start: dist[0]=0, ways[0]=1
Explore neighbors of 0:
- 0 → 1 (time 2): dist[1]=2, ways[1]=1
- 0 → 4 (time 5): dist[4]=5, ways[4]=1
Next: Explore 1:
- 1 → 2 (time 3): dist[2]=5, ways[2]=1
- 1 → 3 (time 3): dist[3]=5, ways[3]=1
Next: Explore 4:
- 4 → 6 (time 2): dist[6]=7, ways[6]=1
Next: Explore 2:
- 2 → 5 (time 1): dist[5]=6, ways[5]=1
Next: Explore 3:
- 3 → 5 (time 1): dist[5]=6, ways[5]=2 (found another shortest path)
Next: Explore 6:
- 6 → 3 (time 3): dist[3]=5 (no update)
- 6 → 5 (time 1): dist[5]=6 (no update)
End: dist[5]=6, ways[5]=4

🌍 7. Real-Life Use Case
This is used in:
🚗 GPS Navigation (multiple shortest routes)
🌐 Network routing (load balancing)
📦 Logistics (optimal delivery paths)
🎮 Game pathfinding (AI movement)

💣 Common Mistakes:
❌ Only finding shortest path, not counting ways
❌ Forgetting modulo
❌ Using int instead of long long (overflow)

📝 9. Revision Notes (🔥 SAVE)
Dijkstra + Ways Array

dist[i] = shortest distance
ways[i] = number of shortest paths

If shorter path → replace
If equal path → add ways

Answer = ways[n-1]

| Part     | Complexity       |
| -------- | ---------------- |
| Dijkstra | O((V + E) log V) |
| Space    | O(V + E)         |

*/