// Link: https://www.geeksforgeeks.org/problems/asteroid-collision/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> reducePairs(vector<int> &arr)
    {
        // code here
        vector<int> st;

        for (int x : arr)
        {
            while (!st.empty() && st.back() * x < 0)
            {
                int top = st.back();

                if (abs(top) > abs(x))
                {
                    x = 0;
                    break;
                }
                else if (abs(top) < abs(x))
                {
                    st.pop_back();
                }
                else
                {
                    st.pop_back();
                    x = 0;
                    break;
                }
            }

            if (x != 0)
                st.push_back(x);
        }

        return st;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution ob;
    vector<int> result = ob.reducePairs(arr);

    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

/*
Question: Given an array arr[] of integers, reduce the array by repeatedly removing adjacent pairs of integers that have opposite signs (one positive and one negative). The process continues until no more such pairs can be removed. Return the resulting array after all possible reductions.

Example 1:
Input: arr[] = [1, -2, 3, -4, 5]
Output: [1, 3, 5]
Explanation:
1. The pair (1, -2) has opposite signs, so we remove it. The array becomes [3, -4, 5].
2. The pair (3, -4) has opposite signs, so we remove it. The array becomes [5].
3. No more pairs with opposite signs are left, so the final array is [1, 3, 5].

Example 2:
Input: arr[] = [1, -1, 2, -2, 3]
Output: [3]
Explanation:
1. The pair (1, -1) has opposite signs, so we remove it. The array becomes [2, -2, 3].
2. The pair (2, -2) has opposite signs, so we remove it. The array becomes [3].
3. No more pairs with opposite signs are left, so the final array is [3].

Constraints:
1. 1 <= arr.length <= 10^5
2. -10^9 <= arr[i] <= 10^9

=============================================================================================
Approach:
1. We can use a stack to keep track of the integers in the array.
2. Iterate through each integer in the array:
   a. While the stack is not empty and the top of the stack has an opposite sign to the current integer, we compare their absolute values.
   b. If the absolute value of the top of the stack is greater than the current integer, we pop the top of the stack and continue checking.
   c. If the absolute value of the top of the stack is less than the current integer, we pop the top of the stack and break out of the loop.
   d. If they are equal, we pop the top of the stack and set the current integer to 0 (indicating both are removed) and break out of the loop.
3. If the current integer is not 0 after the loop, we push it onto the stack.
4. Finally, we return the contents of the stack as the resulting array after all reductions.

Time Complexity: O(n) - Each element is processed at most twice (once when pushed and once when popped).
Space Complexity: O(n) - In the worst case, all elements could be in the stack.

Dry Run:
Input: arr[] = [1, -2, 3, -4, 5]
- Start with an empty stack.
- Process 1: Stack = [1]
- Process -2: Stack = [1, -2] (1 and -2 have opposite signs, compare absolute values: abs(1) < abs(-2), pop 1, stack becomes [-2])
- Process 3: Stack = [-2, 3] (-2 and 3 have opposite signs, compare absolute values: abs(-2) < abs(3), pop -2, stack becomes [3])
- Process -4: Stack = [3, -4] (3 and -4 have opposite signs, compare absolute values: abs(3) < abs(-4), pop 3, stack becomes [-4])
- Process 5: Stack = [-4, 5] (-4 and 5 have opposite signs, compare absolute values: abs(-4) < abs(5), pop -4, stack becomes [5])
- Final stack = [5], return [1, 3, 5].



*/