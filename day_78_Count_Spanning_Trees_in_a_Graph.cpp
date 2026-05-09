// Link: https://www.geeksforgeeks.org/problems/total-number-of-spanning-trees-in-a-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double determinant(vector<vector<double>> &mat, int n)
    {

        double det = 1;

        for (int i = 0; i < n; i++)
        {

            int pivot = i;

            for (int j = i; j < n; j++)
            {

                if (abs(mat[j][i]) > abs(mat[pivot][i]))
                    pivot = j;
            }

            if (mat[pivot][i] == 0)
                return 0;

            if (i != pivot)
            {
                swap(mat[i], mat[pivot]);
                det *= -1;
            }

            det *= mat[i][i];

            for (int j = i + 1; j < n; j++)
            {

                double factor = mat[j][i] / mat[i][i];

                for (int k = i; k < n; k++)
                {

                    mat[j][k] -= factor * mat[i][k];
                }
            }
        }

        return round(det);
    }

    int countSpanTree(int n, vector<vector<int>> &edges)
    {

        if (n == 1)
            return 1;

        vector<vector<double>> lap(n, vector<double>(n, 0));

        // Build Laplacian Matrix
        for (auto &e : edges)
        {

            int u = e[0];
            int v = e[1];

            lap[u][u]++;
            lap[v][v]++;

            lap[u][v] = -1;
            lap[v][u] = -1;
        }

        // Create minor matrix
        vector<vector<double>> minor(n - 1,
                                     vector<double>(n - 1));

        for (int i = 0; i < n - 1; i++)
        {

            for (int j = 0; j < n - 1; j++)
            {

                minor[i][j] = lap[i][j];
            }
        }

        return (int)determinant(minor, n - 1);
    }
};

int main()
{

    int tc;
    cin >> tc;

    while (tc--)
    {

        int n, m;
        cin >> n >> m;

        vector<vector<int>> edges(m, vector<int>(2));

        for (int i = 0; i < m; i++)
        {

            cin >> edges[i][0] >> edges[i][1];
        }

        Solution ob;
        cout << ob.countSpanTree(n, edges) << "\n";
    }

    return 0;
}

/*
Question: Given an undirected graph with n vertices and m edges, find the total number of spanning trees in the graph.

Example 1:
Input:
n = 4, m = 5
edges = [[0, 1], [0, 2], [0, 3], [1, 2], [2, 3]]
Output: 8
Explanation: The graph has 8 spanning trees.

Example 2:
Input:
n = 3, m = 3
edges = [[0, 1], [1, 2], [0, 2]]
Output: 3
Explanation: The graph has 3 spanning trees.

Example 3:
Input:
n = 5, m = 4
edges = [[0, 1], [1, 2], [2, 3], [3, 4]]
Output: 1
Explanation: The graph has only 1 spanning tree, which is the graph itself.

=============================================================================
Approach:
1. We can use Kirchhoff's theorem to find the number of spanning trees in a graph
2. According to Kirchhoff's theorem, the number of spanning trees in a graph is equal to any cofactor of its Laplacian matrix.
3. The Laplacian matrix L of a graph is defined as L = D - A, where D is the degree matrix and A is the adjacency matrix of the graph.
4. To find the number of spanning trees, we can compute the determinant of any (n-1) x (n-1) minor of the Laplacian matrix, which can be obtained by removing any one row and one column from the Laplacian matrix.
5. We can implement the determinant calculation using Gaussian elimination, which has a time complexity of O(n^3).

Time Complexity: O(n^3) due to the determinant calculation using Gaussian elimination.
Space Complexity: O(n^2) for storing the Laplacian matrix and its minor.

Dry Run:
Input:
n = 4, m = 5
edges = [[0, 1], [0, 2], [0, 3], [1, 2], [2, 3]]
1. Construct the Laplacian matrix L:
   L = [[3, -1, -1, -1],
        [-1, 2, -1, 0],
        [-1, -1, 3, -1],
        [-1, 0, -1, 2]]
2. Remove the last row and column to get the minor matrix:
   minor = [[3, -1, -1],
            [-1, 2, -1],
            [-1, -1, 3]]
3. Calculate the determinant of the minor matrix using Gaussian elimination:
   - Perform row operations to convert the matrix to upper triangular form and calculate the product of the diagonal elements.
4. The determinant is found to be 8, which is the number of spanning trees in the graph.



*/