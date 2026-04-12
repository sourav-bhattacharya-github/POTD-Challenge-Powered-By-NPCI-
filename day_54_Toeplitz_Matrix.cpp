// Link: https://www.geeksforgeeks.org/problems/toeplitz-matrix/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {

                // check if the current element is equal to the top-left diagonal element of the previous row and previous column
                if (mat[i][j] != mat[i - 1][j - 1])
                {
                    return false;
                }
            }
        }

        // if all elements satisfy the condition, then it's a Toeplitz matrix
        return true;
    }
};

int main()
{
    Solution sol;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    cout << (sol.isToeplitzMatrix(mat) ? "True" : "False") << endl;
    return 0;
}

/*
Question: Toeplitz Matrix
A matrix is called a Toeplitz matrix if every diagonal from top-left to bottom-right has the same elements.

Example:
Input: mat = [[1,2,3,4],
              [5,1,2,3],
              [9,5,1,2]]
Output: True
Explanation: In the above grid, the diagonals are:
"9", "5, 5", "1, 1, 1", "2, 2, 2", "3, 3", "4".
In each diagonal all elements are the same, so the answer is True.

Input: mat = [[1,2],
              [2,2]]
Output: False
Explanation: The diagonal "1, 2" has different elements.

Input: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: False
Explanation: The diagonal "1, 5, 9" has different elements.

Input: mat = [[1,2,3,4],
              [5,1,2,3],
              [9,5,1,2],
              [8,9,5,1]]
Output: True
Explanation: In the above grid, the diagonals are:
"8", "9, 9", "5, 5, 5", "1, 1, 1, 1", "2, 2, 2", "3, 3", "4".
In each diagonal all elements are the same, so the answer is True.

Constraints:
m == mat.length
n == mat[i].length
1 <= m, n <= 20
0 <= mat[i][j] <= 99

Note: The problem can be solved in O(m*n) time complexity by checking each element with its top-left diagonal neighbor.

==========================================================================================================
Approach:
1. Iterate through the matrix starting from the second row and second column.
2. For each element, compare it with the top-left diagonal element (i.e., mat[i-1][j-1]).
3. If any element does not match its top-left diagonal neighbor, return false.
4. If all elements satisfy the condition, return true at the end.

Time Complexity: O(m*n), where m is the number of rows and n is the number of columns in the matrix.
Space Complexity: O(1), as we are using only a constant amount of extra space.

Dry Run:
Input: mat = [[1,2,3,4],
              [5,1,2,3],
              [9,5,1,2]]
- i = 1, j = 1: mat[1][1] (1) == mat[0][0] (1) -> True
- i = 1, j = 2: mat[1][2] (2) == mat[0][1] (2) -> True
- i = 1, j = 3: mat[1][3] (3) == mat[0][2] (3) -> True
- i = 2, j = 1: mat[2][1] (5) == mat[1][0] (5) -> True
- i = 2, j = 2: mat[2][2] (1) == mat[1][1] (1) -> True
- i = 2, j = 3: mat[2][3] (2) == mat[1][2] (2) -> True
All elements satisfy the condition, so return True.



*/