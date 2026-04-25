// Link: https://www.geeksforgeeks.org/problems/common-elements1132/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c)
    {
        // code here
        int an = a.size(), bn = b.size(), cn = c.size();
        int i = 0, j = 0, k = 0;

        vector<int> res;

        while (i < an && j < bn && k < cn)
        {
            if (a[i] == b[j] && b[j] == c[k])
            {
                if (res.empty() || res.back() != a[i])
                {
                    res.push_back(a[i]);
                }
                i++;
                j++;
                k++;
            }
            else
            {
                if (a[i] < b[j])
                    i++;
                else if (b[j] < c[k])
                    j++;
                else
                    k++;
            }
        }

        return res;
    }
};

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vector<int> a(n1), b(n2), c(n3);
    for (int i = 0; i < n1; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n3; i++)
    {
        cin >> c[i];
    }

    Solution ob;

    vector<int> res = ob.commonElements(a, b, c);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}

/*
Question: Given three sorted arrays in non-decreasing order, return all common elements in non-decreasing order across these arrays. If there are no such elements return an empty array.

Examples :

Input: a[] = [1, 5, 10, 20, 40, 80], b[] = [6, 7, 20, 80, 100], c[] = [3, 4, 15, 20, 30, 70, 80, 120]
Output: [20, 80]
Explanation: The elements 20 and 80 appear in all three arrays a, b, and c, making them the only common elements, so the output is [20, 80].

Input: a[] = [1, 2, 3, 4, 5], b[] = [6, 7], c[] = [8, 9, 10]
Output: []
Explanation: Since none of the elements in arrays a, b, and c appear in all three arrays, there are no common elements, so the output is [].

Input:  a[] = [1, 1, 1, 2, 2, 2], b[] = [1, 1, 2, 2, 2], c[] = [1, 1, 1, 1, 2, 2, 2, 2]
Output: [1, 2]
Explanation: Ignoring duplicates, 1 and 2 are present in all three arrays, so the output is [1, 2].


Constraints:
1 ≤ a.size(), b.size(), c.size() ≤ 105
-105 ≤ a[i], b[i] , c[i] ≤ 105

==========================================================================================
Approach:
1.We can use a three-pointer approach since the arrays are already sorted.
2. Initialize three pointers i, j, and k to 0, representing the current indices of arrays a, b, and c respectively.
3. Iterate while all three pointers are within the bounds of their respective arrays:
   a. If a[i], b[j], and c[k] are all equal, we have found a common element.
   b. Check if this element is already in the result vector (to handle duplicates). If not, add it to the result.
   c. Increment all three pointers i, j, and k.
   d. If the elements are not equal, increment the pointer that points to the smallest element among a[i], b[j], and c[k] to move closer to a potential common value.
4. Return the result vector containing all unique common elements.

Time Complexity: O(n1 + n2 + n3) - We traverse each array at most once.
Space Complexity: O(1) - Excluding the space required for the output array.

Dry Run:
Input: a = [1, 5, 10, 20], b = [6, 7, 20], c = [3, 4, 15, 20]
- i=0, j=0, k=0: a[0]=1, b[0]=6, c[0]=3. Smallest is a[0], i++.
- i=1, j=0, k=0: a[1]=5, b[0]=6, c[0]=3. Smallest is c[0], k++.
- i=1, j=0, k=1: a[1]=5, b[0]=6, c[1]=4. Smallest is c[1], k++.
- i=1, j=0, k=2: a[1]=5, b[0]=6, c[2]=15. Smallest is a[1], i++.
- i=2, j=0, k=2: a[2]=10, b[0]=6, c[2]=15. Smallest is b[0], j++.
- i=2, j=1, k=2: a[2]=10, b[1]=7, c[2]=15. Smallest is b[1], j++.
- i=2, j=2, k=2: a[2]=10, b[2]=20, c[2]=15. Smallest is a[2], i++.
- i=3, j=2, k=2: a[3]=20, b[2]=20, c[2]=15. Smallest is c[2], k++.
- i=3, j=2, k=3: a[3]=20, b[2]=20, c[3]=20. All equal, add 20 to res, i++, j++, k++.
- Loop ends as pointers exceed array bounds.
- Return res = [20].

*/