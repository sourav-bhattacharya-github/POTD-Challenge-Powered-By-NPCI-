// Link: https://www.geeksforgeeks.org/problems/print-diagonally4331/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> antiDiagonalPattern(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> result;

        // Traverse from first row
        for (int col = 0; col < n; col++) {
            int i = 0, j = col;

            while (i < n && j >= 0) {
                result.push_back(mat[i][j]);
                i++;
                j--;
            }
        }

        // Traverse from last column (excluding first row)
        for (int row = 1; row < n; row++) {
            int i = row, j = n - 1;

            while (i < n && j >= 0) {
                result.push_back(mat[i][j]);
                i++;
                j--;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> result = sol.antiDiagonalPattern(mat);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl; // Output: 1 2 4 3 5 7 6 8 9
    return 0;
}


/*
Question: Given a square matrix of size n x n, print the elements of the matrix in an anti-diagonal pattern. The anti-diagonal pattern starts from the top-left corner and moves towards the bottom-right corner, printing elements along the anti-diagonals.

Example:
Input:
1 2 3
4 5 6   
7 8 9

Output:
1 2 4 3 5 7 6 8 9

Explanation:
The anti-diagonal pattern for the given matrix is:
1
2 4
3 5 7   
6 8
9
The elements are printed in the order of their anti-diagonal traversal, starting from the top-left corner and moving towards the bottom-right corner.

=============================================================================================================== 
Approach:
1. We can traverse the matrix in two phases:
   - First, we traverse from the first row to the last column, starting from each column of the first row.
   - Then, we traverse from the second row to the last row, starting from the last column of each row.
2. For each starting point, we move diagonally downwards to the left until we go out of bounds, collecting the elements along the way.
3. Finally, we return the collected elements in the order they were traversed.

Time Complexity: O(n^2) - We visit each element of the matrix once.
Space Complexity: O(n^2) - We store the result in a vector that can hold

Dry run:
Input:
1 2 3
4 5 6
7 8 9

1. Start from the first row:
   - col = 0: i = 0, j = 0 → result = [1]
   - col = 1: i = 0, j = 1 → result = [1, 2]
              i = 1, j = 0 → result = [1, 2, 4]
   - col = 2: i = 0, j = 2 → result = [1, 2, 4, 3]
              i = 1, j = 1 → result = [1, 2, 4, 3, 5]
              i = 2, j = 0 → result = [1, 2, 4, 3, 5, 7]
   - col = 3: i = 0, j = 3 → result = [1, 2, 4, 3, 5, 7, 6]
              i = 1, j = 2 → result = [1, 2, 4, 3, 5, 7, 6, 8]
              i = 2, j = 1 → result = [1, 2, 4, 3, 5, 7, 6, 8, 9]
2. Start from the second row:
   - row = 1: i = 1, j = 2 → result = [1, 2, 4, 3, 5, 7, 6, 8, 9] (already added)
   - row = 2: i = 2, j = 2 → result = [1, 2, 4, 3, 5, 7, 6, 8, 9] (already added)
3. Final result: [1, 2, 4, 3, 5, 7, 6, 8, 9]



*/