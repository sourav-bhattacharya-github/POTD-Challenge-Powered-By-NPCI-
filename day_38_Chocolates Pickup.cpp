// Link: https://www.geeksforgeeks.org/problems/chocolates-pickup/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxChocolate(vector<vector<int>> &grid)
    {
        // code here
        int n = grid.size(), m = grid[0].size();

        // 3D DP array: dp[i][j1][j2] = max chocolates collected starting from row i with Alice at column j1 and Bob at column j2
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

        // Base case: last row
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                if (j1 == j2) // If both are in the same cell, count chocolates only once
                    dp[n - 1][j1][j2] = grid[n - 1][j1];
                else // If they are in different cells, count chocolates from both cells
                    dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
                ;
            }
        }

        // Fill the DP table from bottom to top
        for (int i = n - 2; i >= 0; i--)
        {

            // Alice's column
            for (int j1 = 0; j1 < m; j1++)
            {

                // Bob's column
                for (int j2 = 0; j2 < m; j2++)
                {

                    int maxi = 0;

                    // Explore all 9 possible moves for Alice and Bob (stay, move left, move right)
                    for (int dj1 = -1; dj1 <= 1; dj1++)
                    {

                        // Calculate new positions for Alice and Bob after the move
                        for (int dj2 = -1; dj2 <= 1; dj2++)
                        {

                            int nj1 = j1 + dj1; // New column for Alice
                            int nj2 = j2 + dj2; // New column for Bob

                            // Check if the new positions are within the grid boundaries
                            if (nj1 >= 0 && nj1 < m && nj2 >= 0 && nj2 < m)
                            {
                                int val = dp[i + 1][nj1][nj2]; // Chocolates collected from the next row based on the new positions

                                // Add chocolates from the current row based on Alice's and Bob's positions
                                if (j1 == j2)
                                    val += grid[i][j1];

                                // If Alice and Bob are in different columns, count chocolates from both cells
                                else
                                    val += grid[i][j1] + grid[i][j2];

                                maxi = max(maxi, val);
                            }
                        }
                    }

                    // Store the maximum chocolates collected for the current state in the DP table
                    dp[i][j1][j2] = maxi;
                }
            }
        }

        // The answer is the maximum chocolates collected starting from the top row with Alice at column 0 and Bob at column m-1
        return dp[0][0][m - 1];
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}};

    int result = sol.maxChocolate(grid);
    cout << result << endl; // Output: Maximum chocolates collected

    return 0;
}

/*
Question: Alice and Bob are playing a game where they have to collect chocolates from a grid. The grid has n rows and m columns, and each cell contains a certain number of chocolates. Alice starts at the top-left corner of the grid (0, 0) and Bob starts at the top-right corner of the grid (0, m-1). They can only move downwards to the next row, and they can move to the same column or one column to the left or right. The game ends when they reach the bottom row of the grid. The goal is to maximize the total number of chocolates collected by both Alice and Bob.

Example 1:
Input:
grid = [[3, 1, 1],
        [2, 5, 1],
        [1, 5, 5],
        [2, 1, 1]]
Output: 24
Explanation: The optimal path for Alice and Bob is as follows:
- Alice: 0,0 → 1,0 → 2,0 → 3,0 (collects 3 + 2 + 1 + 2 = 8 chocolates)
- Bob: 0,2 → 1,2 → 2,2 → 3,2 (collects 1 + 1 + 5 + 1 = 8 chocolates)
Total chocolates collected = 8 (Alice) + 8 (Bob) = 16

Example 2:
Input:
grid = [[1, 0, 0],
        [0, 0, 0],
        [0, 0, 1]]
Output: 2
Explanation: The optimal path for Alice and Bob is as follows:
- Alice: 0,0 → 1,0 → 2,0 (collects 1 + 0 + 0 = 1 chocolate)
- Bob: 0,2 → 1,2 → 2,2 (collects 0 + 0 + 1 = 1 chocolate)
Total chocolates collected = 1 (Alice) + 1 (Bob) = 2

Constraints:
1 <= n, m <= 70
1 <= grid[i][j] <= 100

=====================================================================================================================
Approach:
1. Define a 3D DP array: dp[i][j1][j2]
    - i: current row
    - j1: current column of Alice
    - j2: current column of Bob
    - dp[i][j1][j2]: maximum chocolates collected starting from row i with Alice at column j1 and Bob at column j2

2. Base Case:
- For the last row (i = n-1), calculate dp[n-1][j1][j2] based on the chocolates in the last row. If Alice and Bob are in the same cell, count chocolates only once; otherwise, count chocolates from both cells.

3. Fill the DP table from bottom to top:
- For each row i from n-2 to 0:
    - For each possible column j1 for Alice and j2 for Bob:
        - Explore all 9 possible moves for Alice and Bob (stay, move left, move right):
            - Calculate new positions for Alice and Bob after the move
            - Check if the new positions are within the grid boundaries
            - Update dp[i][j1][j2] with the maximum chocolates collected based on the next row's DP values and the current row's chocolates.
4. The answer will be in dp[0][0][m-1], which represents the maximum chocolates collected starting from the top row with Alice at column 0 and Bob at column m-1.
5. Return the result.

Time Complexity: O(n * m^2 * 9) = O(n * m^2) Because we are iterating through n rows, m columns for Alice, m columns for Bob, and 9 possible moves for each state.

Space Complexity: O(n * m^2) Because we are using a 3D DP array to store the results for each state.

*/