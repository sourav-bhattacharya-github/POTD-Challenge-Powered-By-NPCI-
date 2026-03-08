// Link: https://www.geeksforgeeks.org/problems/pythagorean-triplet3018/1
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool pythagoreanTriplet(vector<int> &arr)
    {

        int n = arr.size(); // Get the number of elements in the array

        // Create an unordered set to store the squares of the elements
        unordered_set<long long> st;

        // Calculate the squares of the elements and store them in the set and also update the original array with their squares
        for (int i = 0; i < n; i++)
        {
            long long sq = 1LL * arr[i] * arr[i];
            st.insert(sq);
            arr[i] = sq;
        }

        // Check for every pair of elements if their sum of squares exists in the set which would indicate the presence of a Pythagorean triplet
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                long long sum = arr[i] + arr[j];

                // If the sum of squares of arr[i] and arr[j] exists in the set, it means we have found a Pythagorean triplet
                if (st.find(sum) != st.end())
                    return true;
            }
        }

        return false;
    }
};

/*
Question: Given an array of integers, determine if there exists a Pythagorean triplet in the array. A Pythagorean triplet is a set of three integers a, b, c such that a^2 + b^2 = c^2.

Example 1:
Input: arr[] = {3, 1, 4, 6, 5}
Output: True
Explanation: There is a Pythagorean triplet in the array (3, 4, 5) because 3^2 + 4^2 = 5^2.

Example 2:
Input: arr[] = {10, 4, 6, 12, 5}
Output: False
Explanation: There is no Pythagorean triplet in the array.

====================================================================================================================
Brute Force Approach:
1. Iterate through all possible combinations of three integers in the array.
2. For each combination, check if the sum of squares of the two smaller integers equals the square of the largest integer.
Time Complexity: O(n^3) due to three nested loops.
====================================================================================================================
Optimal Approach:
1. First, compute the squares of all elements in the array and store them in a hash set for O(1) average time complexity lookups.
2. Then, iterate through all pairs of integers in the array and check if the sum of their squares exists in the hash set.
Time Complexity: O(n^2) due to two nested loops for checking pairs, and O(n) for computing squares and storing in the set, resulting in O(n^2) overall.


Expected Time Complexity: O(n^2)
Expected Auxiliary Space: O(n)

*/