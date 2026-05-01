// Link: https://www.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> kthLargest(vector<int> &arr, int k)
    {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> ans;

        for (int x : arr)
        {
            pq.push(x);

            if (pq.size() > k)
                pq.pop();

            if (pq.size() < k)
                ans.push_back(-1);
            else
                ans.push_back(pq.top());
        }

        return ans;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Solution ob;
    vector<int> res = ob.kthLargest(arr, k);

    for (int x : res)
        cout << x << " ";
    cout << endl;

    return 0;
}

/*
Question: Given an array of integers and an integer K, find the Kth largest element in the stream of integers. If the Kth largest element does not exist, return -1.

Example 1:
Input:
N = 6, K = 3
A[] = {1, 2, 3, 4, 5, 6}
Output: -1  -1  3  4  5  6
Explanation: The stream of integers is 1, 2, 3, 4, 5, 6. The Kth largest element after each insertion is as follows:
- After inserting 1:[1] Kth largest element does not exist, so return -1.
- After inserting 2:[1, 2] Kth largest element does not exist, so return -1.
- After inserting 3:[1, 2, 3] Kth largest element is 3.
- After inserting 4:[1, 2, 3, 4] Kth largest element is 3.
- After inserting 5:[1, 2, 3, 4, 5] Kth largest element is 3.
- After inserting 6:[1, 2, 3, 4, 5, 6] Kth largest element is 4.

Example 2:
Input:
N = 5, K = 2
A[] = {5, 2, 1, 3, 4}
Output: -1  5  5  5  5
Explanation: The stream of integers is 5, 2, 1, 3, 4. The Kth largest element after each insertion is as follows:
- After inserting 5:[5] Kth largest element does not exist, so return -1.
- After inserting 2:[5, 2] Kth largest element is 5.
- After inserting 1:[5, 2, 1] Kth largest element is 5.
- After inserting 3:[5, 2, 1, 3] Kth largest element is 5.
- After inserting 4:[5, 2, 1, 3, 4] Kth largest element is 5.

Constraints:
1 <= N <= 10^5
1 <= K <= N

===============================================================================================
Approach:
1. We can use a min-heap (priority queue) to keep track of the K largest elements in the stream.
2. For each element in the stream, we add it to the min-heap.
3. If the size of the min-heap exceeds K, we remove the smallest element (the top of the min-heap).
4. After processing each element, if the size of the min-heap is less than K, we append -1 to the answer vector. Otherwise, we append the top of the min-heap (the Kth largest element) to the answer vector.

Time Complexity: O(N log K) where N is the number of elements in the stream and K is the size of the min-heap.
Space Complexity: O(K) for the min-heap.

Dry Run:
Input: N = 6, K = 3, A[] = {1, 2, 3, 4, 5, 6}
- After inserting 1: min-heap = [1], answer = [-1]
- After inserting 2: min-heap = [1, 2], answer = [-1, -1]
- After inserting 3: min-heap = [1, 2, 3], answer = [-1, -1, 3]
- After inserting 4: min-heap = [2, 3, 4], answer = [-1, -1, 3, 3]
- After inserting 5: min-heap = [3, 4, 5], answer = [-1, -1, 3, 3, 3]
- After inserting 6: min-heap = [4, 5, 6], answer = [-1, -1, 3, 3, 3, 4]
- Final answer = [-1, -1, 3, 3, 3, 4]



*/