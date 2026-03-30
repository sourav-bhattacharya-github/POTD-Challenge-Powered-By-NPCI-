// LinK: https://www.geeksforgeeks.org/problems/minimum-cost-to-connect-all-houses-in-a-city/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(vector<vector<int>> &houses)
    {
        int n = houses.size();

        vector<int> minDist(n, INT_MAX);
        vector<bool> visited(n, false);

        minDist[0] = 0;
        int totalCost = 0;

        for (int i = 0; i < n; i++)
        {
            int u = -1;

            // pick minimum distance node
            for (int j = 0; j < n; j++)
            {
                if (!visited[j] && (u == -1 || minDist[j] < minDist[u]))
                {
                    u = j;
                }
            }

            visited[u] = true;
            totalCost += minDist[u];

            // update distances
            for (int v = 0; v < n; v++)
            {
                if (!visited[v])
                {
                    int cost = abs(houses[u][0] - houses[v][0]) +
                               abs(houses[u][1] - houses[v][1]);

                    minDist[v] = min(minDist[v], cost);
                }
            }
        }

        return totalCost;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> houses = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};

    int result = sol.minCost(houses);
    cout << result << endl; // Output: Minimum cost to connect all houses

    return 0;
}

/*
Question: Given a list of coordinates representing the locations of houses in a city, find the minimum cost to connect all the houses with roads. The cost to connect two houses is defined as the Manhattan distance between their coordinates.

Example 1:
Input: houses = [[0, 0], [2, 2], [3, 10], [5, 2], [7, 0]]
Output: 20
Explanation: The minimum cost to connect all the houses is 20, which can be achieved by connecting the houses in the following way:
- Connect house 0 to house 1 (cost = 4)
- Connect house 1 to house 3 (cost = 2)
- Connect house 3 to house 4 (cost = 2)
- Connect house 1 to house 2 (cost = 12)
Total cost = 4 + 2 + 2 + 12 = 20

Example 2:
Input: houses = [[1, 1], [3, 4], [6, 1]]
Output: 10
Explanation: The minimum cost to connect all the houses is 10, which can be achieved by connecting the houses in the following way:
- Connect house 0 to house 1 (cost = 5)
- Connect house 1 to house 2 (cost = 5)
Total cost = 5 + 5 = 10

Constraints:
1 <= houses.length <= 1000
1 <= houses[i].length == 2
0 <= houses[i][j] <= 10^6

===================================================================================================================
Approach:
1. Use Prim's algorithm to find the Minimum Spanning Tree (MST) of the
    graph formed by the houses, where the weight of the edge between two houses is the Manhattan distance between their coordinates.
2. Initialize a min-heap to store the edges based on their weights and a visited array to keep track of the houses that have been connected.
3. Start from the first house and add all its edges to the min-heap.
4. While the min-heap is not empty, pop the edge with the smallest weight. If the destination house of that edge has not been visited, add it to the MST and add all its edges to the min-heap.
5. Keep track of the total cost of the edges added to the MST, which will be the minimum cost to connect all the houses.

Time Complexity: O(n^2 log n) due to the use of a min-heap and the fact that we are checking all pairs of houses to calculate distances.
Space Complexity: O(n) for the visited array and min-heap.

Dry Run:
Input: houses = [[0, 0], [2, 2], [3, 10], [5, 2], [7, 0]]
- Start with house 0, add edges to min-heap: (0,1)=
4, (0,2)=13, (0,3)=7, (0,4)=7
- Pop (0,1)=4, add house 1 to MST, totalCost=4
- Add edges from house 1: (1,2)=12, (1,3)=2, (1,4)=5
- Pop (1,3)=2, add house 3 to MST, totalCost=6
- Add edges from house 3: (3,4)=2
- Pop (3,4)=2, add house 4 to MST, totalCost=8
- Add edges from house 4: (4,2)=10
- Pop (1,2)=12, add house 2 to MST, totalCost=20
Output: 20



*/