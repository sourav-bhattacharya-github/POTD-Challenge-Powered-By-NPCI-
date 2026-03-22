// Link: https://www.geeksforgeeks.org/problems/rotten-oranges2536/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRot(vector<vector<int>> &mat)
    {

        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        // Step 1: Push all rotten oranges
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (mat[i][j] == 2)
                    q.push({i, j});

                if (mat[i][j] == 1)
                    fresh++;
            }
        }

        // If no fresh oranges
        if (fresh == 0)
            return 0;

        int time = 0;

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        // Step 2: BFS
        while (!q.empty())
        {

            int size = q.size();
            bool rotten = false;

            for (int i = 0; i < size; i++)
            {

                auto [x, y] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++)
                {

                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx >= 0 && ny >= 0 && nx < n && ny < m && mat[nx][ny] == 1)
                    {

                        mat[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                        rotten = true;
                    }
                }
            }

            if (rotten)
                time++;
        }

        // Step 3: Check remaining fresh
        if (fresh > 0)
            return -1;

        return time;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> mat = {
        {2, 1, 0, 2, 1},
        {1, 0, 1, 2, 1},
        {1, 0, 0, 2, 1}};

    int result = sol.orangesRot(mat);
    cout << "Minimum time to rot all oranges: " << result << endl;

    return 0;
}

/*
Question:
Given a matrix of integers where each cell can have three possible values:
- 0: Empty cell
- 1: Fresh orange
- 2: Rotten orange
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example 1:
Input: mat = [[2,1,0,2,1],[1,0,1,2,1],[1,0,0,2,1]]
Output: 2
Explanation:
Minute 0: [[2,1,0,2,1],[1,0,1,2,1],[1,0,0,2,1]]
Minute 1: [[2,2,0,2,2],[2,0,2,2,2],[2,0,0,2,2]]
Minute 2: [[2,2,0,2,2],[2,0,2,2,2],[2,0,0,2,2]]

Example 2:
Input: mat = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:
Input: mat = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

Example 4:
Input: mat = [[0]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

=====================================================================================================================

Note:
- 1 <= mat.length <= 10
- 1 <= mat[0].length <= 10
- mat[i][j] is 0, 1, or 2.

Algorithm:
1. Initialize a queue to store the positions of rotten oranges and a counter for fresh oranges.
2. Traverse the matrix to populate the queue with the initial positions of rotten oranges and count the fresh oranges.
3. If there are no fresh oranges, return 0.
4. Perform a breadth-first search (BFS) from the rotten oranges:
   - For each rotten orange, check its 4-directional neighbors.
   - If a neighbor is a fresh orange, rot it (change to 2), add its position to the queue, and decrement the fresh orange counter.
   - Keep track of the time taken for each level of BFS.
5. After the BFS, if there are still fresh oranges left, return -1. Otherwise, return the time taken.


Time Complexity: O(n*m) where n is the number of rows and m is the number of columns in the matrix.
Space Complexity: O(n*m) for the queue in the worst case when all oranges are rotten.
*/