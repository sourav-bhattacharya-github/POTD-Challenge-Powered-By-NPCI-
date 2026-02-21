// Link:https://www.geeksforgeeks.org/problems/find-h-index--165609/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        // code here
        int n = citations.size();
        vector<int> freq(n + 1);

        for (int c : citations)
        {
            if (c >= n)
            {
                freq[n] += 1;
            }
            else
            {
                freq[c] += 1;
            }
        }

        int idx = n;

        int sum = freq[n];

        while (idx > sum)
        {
            idx--;
            sum += freq[idx];
        }

        return idx;
    }
};

/*
question: You are given an array citations[], where each element citations[i] represents the number of citations received by the ith paper of a researcher. You have to calculate the researcher’s H-index.
The H-index is defined as the maximum value H, such that the researcher has published at least H papers, and all those papers have citation value greater than or equal to H.


Example 1:
Input: citations[] = {3, 0, 6, 1, 5}
Output: 3
Explanation: The researcher has 5 papers with citations [3, 0, 6, 1, 5]. The researcher has 3 papers with at least 3 citations each and the remaining two papers have no more than 3 citations each. Thus, the H-index is 3.
*/