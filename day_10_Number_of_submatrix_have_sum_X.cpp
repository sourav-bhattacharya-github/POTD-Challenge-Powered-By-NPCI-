// Link: https://www.geeksforgeeks.org/problems/number-of-submatrix-have-sum-k/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSquare(vector<vector<int>> &mat, int x)
    {
        // code here
        int n = mat.size(), m = mat[0].size();

        // Step 1: Create prefix sum matrix
        vector<vector<int>> prefix(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                prefix[i][j] = mat[i][j];

                // Add top
                if (i > 0)
                    prefix[i][j] += prefix[i - 1][j];
                // Add left
                if (j > 0)
                    prefix[i][j] += prefix[i][j - 1];
                // Subtract overlap
                if (i > 0 && j > 0)
                    prefix[i][j] -= prefix[i - 1][j - 1];
            }
        }

        int count = 0;

        // Step 2 : Try all square sizes
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < m; c++)
            {
                // Mixmun possible size form this position
                for (int size = 1;
                     r + size - 1 < n && c + size - 1 < m; size++)
                {
                    int br = r + size - 1;
                    int bc = c + size - 1;
                    int sum = prefix[br][bc];

                    if (r > 0)
                        sum -= prefix[r - 1][bc];

                    if (c > 0)
                        sum -= prefix[br][c - 1];

                    if (r > 0 && c > 0)
                        sum += prefix[r - 1][c - 1];

                    if (sum == x)
                        count++;
                }
            }
        }
        return count;
    }
};

/*
Question: Given a 2D matrix of integers and an integer X, find the number of square submatrices that have a sum equal to X.

Example 1:
Input:
mat = [[1, 2, 3],
       [4, 5, 6],
       [7, 8, 9]]
X = 12
Output: 1
Explanation: The only square submatrix with sum equal to 12 is [[5, 6], [8, 9]].

Example 2:
Input:
mat = [[1, 1, 1],
       [1, 1, 1],
       [1, 1, 1]]
X = 4
Output: 4
Explanation: The square submatrices with sum equal to 4 are:
[[1, 1], [1, 1]] (top-left corner)
[[1, 1], [1, 1]] (top-right corner)
[[1, 1], [1, 1]] (bottom-left corner)
[[1, 1], [1, 1]] (bottom-right corner)

Your Task:
Step 1: Build Prefix Sum Matrix

Let: prefix[i][j] = sum of all elements in the submatrix from (0, 0) to (i, j)

Store sum of submatrix from: (0,0) → (i,j)

prefix[i][j] =
mat[i][j]
+ prefix[i-1][j]
+ prefix[i][j-1]
- prefix[i-1][j-1]

Step 2: Get Any Square Sum in O(1)

For square of size k
Top-left = (r,c)
Bottom-right = (r+k-1, c+k-1)

sum = prefix[r+k-1][c+k-1]
- prefix[r-1][c+k-1]
- prefix[r+k-1][c-1]
+ prefix[r-1][c-1]

Step 3: Try All Square Sizes

For each cell:
Try square sizes
Compute sum in O(1)
If sum == x → count++


| Step          | Complexity           |
| ------------- | -------------------- |
| Build prefix  | O(nm)                |
| Check squares | O(nm * min(n,m))     |
| Total         | **O(nm * min(n,m))** |


Time  = O(nm * min(n,m))
Space = O(nm)
*/