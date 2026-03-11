// Link:https://www.geeksforgeeks.org/problems/minimum-number-of-k-consecutive-bit-flips--171650/1
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kBitFlips(vector<int> &arr, int k)
    {
        // code here
        int n = arr.size();
        vector<int> isFlipped(n, 0);

        int flip = 0, ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (i >= k)
                flip ^= isFlipped[i - k];

            if ((arr[i] ^ flip) == 0)
            {
                if (i + k > n)
                    return -1;
                ans++;

                flip ^= 1;
                isFlipped[i] = 1;
            }
        }

        return ans;
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.kBitFlips(arr, k) << endl;
    }

    return 0;
}

/*
QUESTION: Given a binary array and an integer K, find the minimum number of K consecutive bit flips required to convert all the bits in the array to 1. If it is not possible, return -1.
Example 1:
Input: arr = [0,1,0], K = 1
output: 2
Explanation: Flip the first bit and then the third bit.

Example 2:
Input: arr = [1,1,0], K = 2
Output: -1
Explanation: No matter how we flip the subarray of size 2, we cannot make all bits equal to 1.
Example 3:
Input: arr = [0,0,0,1,0,1,1,0], K = 3
Output: 3
Explanation: Flip subarray [0,0,0], flip subarray [1,0,1] and flip subarray [1,1,0].
====================================================================================================

Brute Force Approach:
1. Iterate through the array and whenever we encounter a 0, flip the next K bits.
2. Keep track of the number of flips made.
3. If at any point we cannot flip K bits (i.e., we reach the end of the array), return -1.

Optimized Approach:
1. Use a variable to keep track of the current flip state (whether we are currently in a flipped segment or not).
2. Iterate through the array and whenever we encounter a 0 that is not in a flipped segment, flip the next K bits and update the flip state.
3. Keep track of the number of flips made.
4. If at any point we cannot flip K bits (i.e., we reach the end of the array), return -1.
5. Return the total number of flips made at the end.
6. To optimize the flipping process, we can use an auxiliary array to keep track of the flips and use XOR to determine the current state of each bit without actually flipping the bits in the original array.

Time Complexity: O(n)
Space Complexity: O(n) due to the auxiliary array used to track flips.

Dry Run:
Input: arr = [0,0,0,1,0,1,1,0], K = 3
1. Start with flip = 0, ans = 0, and isFlipped = [0,0,0,0,0,0,0,0]
2. i = 0: arr[0] = 0, flip = 0, so we need to flip.
    Flip the next 3 bits and update isFlipped[0] = 1, flip = 1, ans = 1
3. i = 1: arr[1] = 0, flip = 1, so we are in a flipped segment. No need to flip.
4. i = 2: arr[2] = 0, flip = 1, so we are in a flipped segment. No need to flip.
5. i = 3: arr[3] = 1, flip = 1, so we are in a flipped segment. No need to flip.
6. i = 4: arr[4] = 0, flip = 1, so we are in a flipped segment. No need to flip.
7. i = 5: arr[5] = 1, flip = 1, so we are in a flipped segment. No need to flip.
8. i = 6: arr[6] = 1, flip = 1, so we are in a flipped segment. No need to flip.
9. i = 7: arr[7] = 0, flip = 1, so we are in a flipped segment. No need to flip.
10. End of array, return ans = 1.




*/
