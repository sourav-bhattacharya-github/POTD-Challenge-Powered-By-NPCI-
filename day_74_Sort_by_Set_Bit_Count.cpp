// Link: https://www.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>;
using namespace std;

class Solution
{
public:
    static bool cmp(int a, int b)
    {
        return __builtin_popcount(a) > __builtin_popcount(b);
    }

    vector<int> sortBySetBitCount(vector<int> &arr)
    {
        // code here
        stable_sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        vector<int> ans = ob.sortBySetBitCount(arr);

        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
Question: Given an array of positive integers. Sort the array in decreasing order of count of set bits in their binary representation. If two numbers have the same number of set bits, then sort them in increasing order.

Example 1:
Input: N = 5, arr[] = {1, 2, 3, 4, 5}
Output: 3 5 1 2 4
Explanation: The binary representation of the numbers are:
1 = 1 (1 set bit)
2 = 10 (1 set bit)
3 = 11 (2 set bits)
4 = 100 (1 set bit)
5 = 101 (2 set bits)
So, the sorted array in decreasing order of count of set bits is: 3, 5, 1, 2, 4.

Example 2:
Input: N = 4, arr[] = {1, 2, 3, 4}
Output: 3 1 2 4
Explanation: The binary representation of the numbers are:
1 = 1 (1 set bit)
2 = 10 (1 set bit)
3 = 11 (2 set bits)
4 = 100 (1 set bit)
So, the sorted array in decreasing order of count of set bits is: 3, 1, 2, 4.

Example 3:
Input: N = 3, arr[] = {1, 2, 3}
Output: 3 1 2
Explanation: The binary representation of the numbers are:
1 = 1 (1 set bit)
2 = 10 (1 set bit)
3 = 11 (2 set bits)
So, the sorted array in decreasing order of count of set bits is: 3, 1, 2.

Constraints:
1 <= N <= 10^5
1 <= arr[i] <= 10^6

=================================================================================
Approach:
1. We can use the built-in function __builtin_popcount() to count the number of set bits in the binary representation of each number.
2. We can define a custom comparator function that compares two numbers based on the count of set bits. If the count of set bits is the same for both numbers, we can compare the numbers themselves to sort them in increasing order.
3.stable_sort() can be used to sort the array based on the custom comparator function. This will ensure that the relative order of elements with the same number of set bits is maintained.

Dry run:
Input: N = 5, arr[] = {1, 2, 3, 4, 5}
- The binary representation of the numbers are:
1 = 1 (1 set bit)
2 = 10 (1 set bit)
3 = 11 (2 set bits)
4 = 100 (1 set bit)
5 = 101 (2 set bits)
- The sorted array in decreasing order of count of set bits is: 3, 5, 1, 2, 4.

*/