// Link: https://www.geeksforgeeks.org/problems/buildings-receiving-sunlight3032/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int visibleBuildings(vector<int> &arr)
    {
        // code here
        int maxHeight = 0;
        int count = 0;

        for (int height : arr)
        {
            if (height >= maxHeight)
            {
                count++;
                maxHeight = height;
            }
        }
        return count;
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
    int result = ob.visibleBuildings(arr);

    cout << result << endl;

    return 0;
}

/*
Question: Given an array arr[] representing the heights of buildings, find the number of buildings that can receive sunlight. A building receives sunlight if it is the first building or if it is taller than or equal to all the buildings to its left.

Example 1:
Input: arr[] = [6, 2, 8, 4, 11, 13]
Output: 4
Explanation:
1. The first building (6) always receives sunlight.
2. The second building (2) is shorter than the first, so it doesn't receive sunlight.
3. The third building (8) is taller than 6 and 2, so it receives sunlight.
4. The fourth building (4) is shorter than 8, so it doesn't receive sunlight.
5. The fifth building (11) is taller than all previous, so it receives sunlight.
6. The sixth building (13) is taller than all previous, so it receives sunlight.
Total = 4 (6, 8, 11, 13).

Example 2:
Input: arr[] = [2, 5, 1, 8, 3]
Output: 3
Explanation: Buildings with heights 2, 5, and 8 receive sunlight.

Constraints:
1 <= arr.size() <= 10^6
1 <= arr[i] <= 10^8

============================================================================================
Approach:
1. Initialize a variable `maxHeight` to keep track of the maximum height encountered so far and a variable `count` to count the number of buildings that receive sunlight.
2. Iterate through the array of building heights:
   - For each building height, check if it is greater than or equal to `maxHeight`.
   - If it is, increment the `count` and update `maxHeight` to the current building's height.
3. Return the `count` of buildings that receive sunlight.


Time Complexity: O(n)
Space Complexity: O(1)

Dry Run:
Input: arr[] = [6, 2, 8, 4, 11, 13]
- Initialize `maxHeight = 0`, `count = 0`
- For height = 6: 6 >= 0 (true), count = 1, maxHeight = 6
- For height = 2: 2 >= 6 (false), count = 1, maxHeight = 6
- For height = 8: 8 >= 6 (true), count = 2, maxHeight = 8
- For height = 4: 4 >= 8 (false), count = 2, maxHeight = 8
- For height = 11: 11 >= 8 (true), count = 3, maxHeight = 11
- For height = 13: 13 >= 11 (true), count = 4, maxHeight = 13
Output: 4

*/
