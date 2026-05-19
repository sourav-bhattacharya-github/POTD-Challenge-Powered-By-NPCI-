// Link: https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumMultiplications(
        vector<int> &arr,
        int start,
        int end)
    {

        // Edge case
        if (start == end)
            return 0;

        vector<int> dist(1000, INT_MAX);

        queue<pair<int, int>> q;

        q.push({start, 0});

        dist[start] = 0;

        while (!q.empty())
        {

            auto [node, steps] = q.front();

            q.pop();

            for (int x : arr)
            {

                int next =
                    (node * x) % 1000;

                // Better path found
                if (steps + 1 < dist[next])
                {

                    dist[next] = steps + 1;

                    // Reached target
                    if (next == end)
                        return steps + 1;

                    q.push({next,
                            steps + 1});
                }
            }
        }

        return -1;
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
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end)
             << endl;
    }
}


/*
*Question: Given two integers, start and end, along with an array of integers arr[]. In one operation, you can multiply the current value by any element from arr[], and then take the result modulo 1000 to obtain a new value.

Find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.

Examples :

Input: arr[] = [2, 5, 7], start = 3, end = 30
Output: 2
Explanation:
Step 1: 3*2 = 6 % 1000 = 6 
Step 2: 6*5 = 30 % 1000 = 30
Input: arr[] = [3, 4, 65], start = 7, end = 175
Output: 4
Explanation:
Step 1: 7 * 3 = 21 % 1000 = 21  
Step 2: 21 * 3 = 63 % 1000 = 63  
Step 3: 63 * 65 = 4095 % 1000 = 95  
Step 4: 95 * 65 = 6175 % 1000 = 175 

Input: arr[] = [2, 4], start = 3, end = 5
Output: -1
Explanation: Starting from 3 and multiplying by 2 or 4 always produces even numbers after the first step. Since 5 is odd, it can never be reached.

Constraints:
1  ≤ arr.size()  ≤ 103
1  ≤ arr[i]  ≤ 103
0  ≤ start, end  < 103

===========================================================================================
Approach:
1. This is a shortest path problem, so we use BFS (0/1 BFS can also be used).
2. Create a distance array `dist[]` of size 1000 initialized with INT_MAX to track minimum steps to reach each value.
3. Use a queue to store pairs of (current_value, steps).
4. Start from `start` with 0 steps, push it to queue and mark dist[start] = 0.
5. For each state popped from queue, try multiplying by each element in arr[].
6. Calculate next value as (current * arr[i]) % 1000.
7. If we find a better path (steps + 1 < dist[next]), update distance and push to queue.
8. If next == end, return steps + 1 immediately (early termination).
9. If queue becomes empty and we haven't reached end, return -1.


Time Complexity: O(n * 1000) where n is size of arr[], 
Space: O(1000) for distance array.


Dry run (example):

Example: arr = [3, 4, 65], start = 7, end = 175

Initial:
    dist[*] = INF, dist[7] = 0
    queue = [(7,0)]

Step 1: pop (7,0)
    try x=3 -> next = (7*3)%1000 = 21. dist[21]=1, push (21,1)
    try x=4 -> next = 28. dist[28]=1, push (28,1)
    try x=65-> next = 455. dist[455]=1, push (455,1)
    queue = [(21,1),(28,1),(455,1)]

Step 2: pop (21,1)
    x=3 -> next = 63. dist[63]=2, push (63,2)
    x=4 -> next = 84. dist[84]=2, push (84,2)
    x=65-> next = 365. dist[365]=2, push (365,2)
    queue = [(28,1),(455,1),(63,2),(84,2),(365,2)]

Step 3: pop (28,1)
    x=3 -> next = 84 but dist[84]==2 so skip
    x=4 -> next = 112. dist[112]=2, push (112,2)
    x=65-> next = 820. dist[820]=2, push (820,2)
    queue = [(455,1),(63,2),(84,2),(365,2),(112,2),(820,2)]

Step 4: pop (455,1)
    x=3 -> next = 365 but dist[365]==2 so skip
    x=4 -> next = 820 but dist[820]==2 so skip
    x=65-> next = 575. dist[575]=2, push (575,2)
    queue now contains states at distance 2...

Continue BFS:
    pop (63,2): 63*65%1000 = 95 -> dist[95]=3, push (95,3)
    pop (84,2): 84*65%1000 = 460 -> dist[460]=3, push (460,3)
    pop (365,2): 365*65%1000 =  3725%1000=725 -> dist[725]=3, push (725,3)
    ...

Eventually: pop (95,3)
    95*65%1000 = 6175%1000 = 175 -> dist[175]=4, reached target -> return 4

This matches the expected output: 4


*/